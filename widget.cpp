#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    InitObject();
    CheckDir();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}
/*
 * 初始化模块
 */
void Widget::InitObject()
{
    Inputwidget = new InputWidget;
    TableModel = new QSqlQueryModel;
    loadingwindow = new LoadingForm;
    process = new ProcessThread(this);
    printer = new PrintManager;
    searchwidget = new SearchForm;
    TableViewInit("");
    TreeWidgetInit();

    connect(process,SIGNAL(send_startcmd(int)),this,SLOT(handleFinishMSG(int)));
    connect(ui->toolButtonInput,SIGNAL(clicked(bool)),SLOT(btnInput()));
    connect(ui->toolButtonexit,SIGNAL(clicked(bool)),SLOT(btnExit()));
    connect(ui->toolButtonDelete,SIGNAL(clicked(bool)),SLOT(btnDelete()));
    connect(ui->toolButtonExport,SIGNAL(clicked(bool)),SLOT(btnExport()));
    connect(ui->toolButtonPrinter,SIGNAL(clicked(bool)),SLOT(btnPrinter()));
    connect(ui->toolButtonSearch,SIGNAL(clicked(bool)),SLOT(btnSearch()));
    connect(ui->toolButtonBackup,SIGNAL(clicked(bool)),SLOT(btnbackup()));
    connect(searchwidget,SIGNAL(sendCondition(QString)),SLOT(handleConditionMSG(QString)));
    connect(Inputwidget,SIGNAL(sendRet(bool)),SLOT(handleInputResultMSG(bool)));
    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),SLOT(TreeitemClick(QTreeWidgetItem*,int)));
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),SLOT(TableitemClick()));

}
Widget::~Widget()
{
    delete ui;
    delete Inputwidget;
    delete loadingwindow;
    delete process;
    delete printer;
    delete searchwidget;
}
/*
 * 检查数据目录是否完整
 */
void Widget::CheckDir()
{
    QDir dataDir;
    QDir databaseDir;
    QDir ImageDir;

    QString dataPath = "../../data/";
    QString dbPath = "../../data/database/";
    QString imagepath = "../../data/Image/";

    if(!dataDir.exists(dataPath))
        dataDir.mkpath(dataPath);
    if(!databaseDir.exists(dbPath))
        databaseDir.mkpath(dbPath);
    if(!ImageDir.exists(imagepath))
        ImageDir.mkpath(imagepath);
    DBcontrol->GetDatabase();
}
/*
 * 输入信息
 */
void Widget::btnInput()
{
    Inputwidget->ClearEdit();
    Inputwidget->show();
}
/*
 * 处理输入窗口返回信息
 */
void Widget::handleInputResultMSG(bool ret)
{
    if(ret)
        QMessageBox::warning(NULL,"提示","信息写入成功","确定");
    else
        QMessageBox::warning(NULL,"提示","信息写入失败","确定");
    TableViewInit("");
    TreewidgetIteminit();
}
/*
 * 退出程序
 */
void Widget::btnExit()
{
    this->close();
    qApp->exit(0);
}
/*
 * 查询槽
 */
void Widget::btnSearch()
{
    searchwidget->CleanEdit();
    searchwidget->show();
}
/*
 * 处理查询
 */
void Widget::handleConditionMSG(QString condition)
{
    TableViewInit(condition);
}

/*
 * 删除槽
 */
void Widget::btnDelete()
{

        QItemSelectionModel *selection=ui->tableView->selectionModel();
        QModelIndexList selected=selection->selectedIndexes();
        if(selected.size()<=0)
        {
                QMessageBox::information(this,QString("提示"),QString("请选择至少一条记录！"));
                return;
        }
        else
        {
            int ok=QMessageBox::warning(this,QString("删除选定记录"),QString("是否确定删除%1条选定记录？").arg(QString::number(selected.size()/9)),QMessageBox::Yes,QMessageBox::No);
            if(ok==QMessageBox::No)
            {
                return;
            }
            else
            {
                foreach(QModelIndex index,selected)
                {
                    if(index.column()== 0)
                    {
                        QString date_temp=TableModel->data(index,Qt::DisplayRole).toString();
                        qDebug()<<date_temp;
                        QString temp=QString("ID='%1'").arg(date_temp);
                        DBcontrol->DeleteData(temp);
                    }
                }

            }
        }
        TableViewInit("");
        TreeWidgetInit();
}
/*
 * 打印槽
 */
void Widget::btnPrinter()
{
    QItemSelectionModel *selection=ui->tableView->selectionModel();
    QModelIndexList selected=selection->selectedIndexes();
    if(selected.size()==0)
    {
        QMessageBox::information(this,"提示","请选择一条数据!");
        return;
    }
    printer->PrintDocument();
}
/*
 * 导出槽
 */
void Widget::btnExport()
{
    QString excel_filename=QFileDialog::getSaveFileName(NULL,tr("保存excel文件"),"","Excel(*.xlsx *.xls)");

    if(excel_filename.isEmpty())
    {
        QMessageBox::information(this,"提示","输入文件名");
        return;
    }
    else
    {
        loadingwindow->show();

        process->SetProcess(EXPORTRUNNING);
        process->SetFilename(excel_filename);

        process->start();
    }
}
/*
 * 导出功能函数
 */
int Widget::ExportFunction(QString filename)
{

    excel=NULL;
    workBooks=NULL;
    workBook=NULL;
    workSheet=NULL;
    workSheets=NULL;
    excel=new QAxObject("Excel.Application");//加载Excel驱动
    excel->setProperty("Visible",false);
    workBooks=excel->querySubObject("WorkBooks");
    workBooks->dynamicCall("Add");
    workBook=excel->querySubObject("ActiveWorkBook");
    workSheets=workBook->querySubObject("Sheets");
    workSheet=workBook->querySubObject("Sheets(int)",1);

    QAxObject *cell=workSheet->querySubObject("Cells(int,int)",1,1);
    cell->setProperty("Value","证件ID");
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,2);
    cell->setProperty("Value","姓名");
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,3);
    cell->setProperty("Value","录入时间");
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,4);
    cell->setProperty("Value","性别");
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,5);
    cell->setProperty("Value","民族");
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,6);
    cell->setProperty("Value","出生年月");
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,7);
    cell->setProperty("Value","地址");
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,8);
    cell->setProperty("Value","签发单位");
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,9);
    cell->setProperty("Value","照片地址");
    cell->clear();

    QVector<InfoData> Alldata = DBcontrol->GetAllData("");

    for(int i = 0; i < Alldata.size(); i++)
    {
        for(int j = 1; j < 10; j++)
        {
            cell->clear();
            cell = workSheet->querySubObject("Cells(int,int)",i+2,j);
            switch (j) {
            case 1:cell->setProperty("Value",Alldata.at(i).ID);break;
            case 2:cell->setProperty("Value",Alldata.at(i).Name);break;
            case 3:cell->setProperty("Value",Alldata.at(i).Time);break;
            case 4:cell->setProperty("Value",Alldata.at(i).Gender);break;
            case 5:cell->setProperty("Value",Alldata.at(i).Nation);break;
            case 6:cell->setProperty("Value",Alldata.at(i).Birthtime);break;
            case 7:cell->setProperty("Value",Alldata.at(i).Address);break;
            case 8:cell->setProperty("Value",Alldata.at(i).Office);break;
            case 9:cell->setProperty("Value",Alldata.at(i).Image);break;
            }
        }
    }
    workBook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filename));
    workBook->dynamicCall("Close(Boolen)",false);
    excel->dynamicCall("Quit(void)");

    return EXPORTFINISH;
}
/*
 * 备份槽
 */
void Widget::btnbackup()
{
    DBcontrol->CloseDB();
    QString filename = QFileDialog::getExistingDirectory(this,"Backup Data",QDir::currentPath());
    QDateTime time = QDateTime::currentDateTime();
    filename += "/"+time.toString("yyyy-MM-dd-hhmmss")+"-backup.zip";
    loadingwindow->show();
    process->SetProcess(BACKUPRUNNING);
    process->SetFilename(filename);

    process->start();
}
/*
 * 备份函数
 */
int Widget::BackupFunction(QString filename)
{
    bool ret = JlCompress::compressDir(filename,"../../data");
    if(ret)
        return BACKUPFINISH;
    else
        return BACKUPWRONG;
}
/*
 * 初始化表结构
 */
void Widget::TableViewInit(QString condition)
{
    //设置tableview的属性
    ui->tableView->setShowGrid(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->setVisible(false);
    TableModel->clear();
    DBcontrol->SelectallData(TableModel,condition,0);
    ui->tableView->setModel(TableModel);
    //设置表头
    TableModel->setHeaderData(0,Qt::Horizontal,"证件ID");
    TableModel->setHeaderData(1,Qt::Horizontal,"姓名");
    TableModel->setHeaderData(2,Qt::Horizontal,"录入时间");
    TableModel->setHeaderData(3,Qt::Horizontal,"性别");
    TableModel->setHeaderData(4,Qt::Horizontal,"民族");
    TableModel->setHeaderData(5,Qt::Horizontal,"出生年月");
    TableModel->setHeaderData(6,Qt::Horizontal,"地址");
    TableModel->setHeaderData(7,Qt::Horizontal,"签发单位");
    TableModel->setHeaderData(8,Qt::Horizontal,"照片地址");
    ui->tableView->show();
}
/*
 * 初始化树结构
 */
void Widget::TreeWidgetInit()
{
    ui->treeWidget->setHeaderLabel("日期");
    TreewidgetIteminit();
}
/*
 * 删除所有树节点
 */
void Widget::deleteTreeItem()
{
   for(int i=0;i<ui->treeWidget->topLevelItemCount();i++)
   {
       for(int j=0;j<ui->treeWidget->topLevelItem(i)->childCount();j++)
       {
           for(int k=0;k<ui->treeWidget->topLevelItem(i)->child(j)->childCount();k++)
           {
               if(ui->treeWidget->topLevelItem(i)->child(j)->child(k))
               {
                   delete ui->treeWidget->topLevelItem(i)->child(j)->child(k);
               }
           }
           if(ui->treeWidget->topLevelItem(i)->child(j))
           {
               delete ui->treeWidget->topLevelItem(i)->child(j);
           }
       }
       if(ui->treeWidget->topLevelItem(i))
       {
           delete ui->treeWidget->topLevelItem(i);
       }
   }
}
/*
 * 初始化树节点
 */
void Widget::TreewidgetIteminit()
{
    deleteTreeItem();
    QVector<QString> Timevector = DBcontrol->getTimedata();
    if(Timevector.size() == 0)
        return;
        for(int row=0;row<Timevector.size();row++)
        {//在数据库对象中的结构体数组中查询获取时间
            QString Time_date=Timevector.at(row);
            QStringList Time_temp_List=Time_date.split(" ");//时间分离
            QStringList Time_list=Time_temp_List.at(0).split('/');//日期分离
            //分离日期生成树节点
            QString year=Time_list.at(0)+" 年";
            QString month=Time_list.at(1)+" 月";
            QString day=Time_list.at(2)+" 日";
            bool day_flag=false;
            bool month_flag=false;
            bool year_flag=false;
            for(int i=0;i<ui->treeWidget->topLevelItemCount();i++)
            {
                if(ui->treeWidget->topLevelItem(i)->text(0)==year)
                {
                    for(int j=0;j<ui->treeWidget->topLevelItem(i)->childCount();j++)
                    {
                        if(ui->treeWidget->topLevelItem(i)->child(j)->text(0)==month)
                        {
                            for(int m=0;m<ui->treeWidget->topLevelItem(i)->child(j)->childCount();m++)
                            {

                                if(ui->treeWidget->topLevelItem(i)->child(j)->child(m)->text(0)==day)
                                {
                                    day_flag=true;
                                    break;
                                }
                            }
                            if(!day_flag)
                            {
                                QTreeWidgetItem *day_item=new QTreeWidgetItem;
                                day_item->setText(0,day);
                                ui->treeWidget->topLevelItem(i)->child(j)->addChild(day_item);
                            }
                            month_flag=true;
                            break;
                        }
                    }
                    if(!month_flag)
                    {
                        QTreeWidgetItem *month_item=new QTreeWidgetItem;
                        QTreeWidgetItem *day_item=new QTreeWidgetItem;
                        month_item->setText(0,month);
                        day_item->setText(0,day);
                        month_item->addChild(day_item);
                        ui->treeWidget->topLevelItem(i)->addChild(month_item);
                    }
                    year_flag=true;
                    break;
                }
            }
            if(!year_flag)
            {
                QTreeWidgetItem *year_item=new QTreeWidgetItem;
                QTreeWidgetItem *month_item=new QTreeWidgetItem;
                QTreeWidgetItem *day_item=new QTreeWidgetItem;
                year_item->setText(0,year);
                month_item->setText(0,month);
                day_item->setText(0,day);
                month_item->addChild(day_item);
                year_item->addChild(month_item);
                int yearcount=ui->treeWidget->topLevelItemCount();
                ui->treeWidget->insertTopLevelItem(yearcount,year_item);
            }
        }
}
/*
 * 树节点相应槽
 */
void Widget::TreeitemClick(QTreeWidgetItem *item, int column)
{
    QString condition;
    if(item->parent()==NULL)
        {
            QString temp=item->text(column).mid(0,4);
            condition=QString("and Time LIKE '%1%'").arg(temp);
            TableViewInit(condition);
        }
        else if(item->parent()->parent())
        {
            QString temp_day=item->text(column).mid(0,2);
            QString temp_month=item->parent()->text(column).mid(0,2);
            QString temp_year=item->parent()->parent()->text(column).mid(0,4);
            QString temp=temp_year+"/"+temp_month+"/"+temp_day;
            condition=QString("and Time LIKE '%1%'").arg(temp);
            TableViewInit(condition);
        }
        else if(item->parent())
        {
            QString temp_year=item->parent()->text(column).mid(0,4);
            QString temp_month=item->text(column).mid(0,2);
            QString temp=temp_year+"/"+temp_month;
            condition=QString("and Time LIKE '%1%'").arg(temp);
            TableViewInit(condition);
        }
}
/*
 * 表节点对应槽
 */
void Widget::TableitemClick()
{
    int row = ui->tableView->currentIndex().row();
    ui->labelID->setText(TableModel->data(TableModel->index(row,0),Qt::DisplayRole).toString());
    ui->labelname->setText(TableModel->data(TableModel->index(row,1),Qt::DisplayRole).toString());
    ui->labelgender->setText(TableModel->data(TableModel->index(row,3),Qt::DisplayRole).toString());
    ui->labelbirth->setText(TableModel->data(TableModel->index(row,5),Qt::DisplayRole).toString());
    ui->labeladdress->setText(TableModel->data(TableModel->index(row,6),Qt::DisplayRole).toString());
    QImage photo;
    photo.load(TableModel->data(TableModel->index(row,8),Qt::DisplayRole).toString());
    photo = photo.scaled(ui->labelphoto->size(),Qt::KeepAspectRatio);
    ui->labelphoto->setPixmap(QPixmap::fromImage(photo));

    InfoData data;
    data.ID = TableModel->data(TableModel->index(row,0),Qt::DisplayRole).toString();
    data.Name = TableModel->data(TableModel->index(row,1),Qt::DisplayRole).toString();
    data.Time = TableModel->data(TableModel->index(row,2),Qt::DisplayRole).toString();
    data.Gender = TableModel->data(TableModel->index(row,3),Qt::DisplayRole).toString();
    data.Nation = TableModel->data(TableModel->index(row,4),Qt::DisplayRole).toString();
    data.Birthtime = TableModel->data(TableModel->index(row,5),Qt::DisplayRole).toString();
    data.Address = TableModel->data(TableModel->index(row,6),Qt::DisplayRole).toString();
    data.Office = TableModel->data(TableModel->index(row,7),Qt::DisplayRole).toString();
    data.Image = TableModel->data(TableModel->index(row,8),Qt::DisplayRole).toString();
    printer->CreateHTML(data);
}
/*
 * 接收线程完成信息槽
 */
void Widget::handleFinishMSG(int MSG)
{
    switch (MSG) {
    case EXPORTFINISH:{
        loadingwindow->close();
        QMessageBox::information(this,QString("提示"),QString("导出到excel完成！"));
    }break;
    case BACKUPFINISH:{
        loadingwindow->close();
        QMessageBox::information(this,QString("提示"),QString("备份完成！"));
    }break;
    case BACKUPWRONG:{
        loadingwindow->close();
        QMessageBox::information(this,QString("提示"),QString("备份失败！"));
    }break;
    }
}
/*
 * 鼠标事件重写
 */
void Widget::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void Widget::mouseMoveEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    last=e->globalPos();
    move(x()+dx,y()+dy);
}
void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();
    move(x()+dx,y()+dy);
}
/*
 * 线程类
 */
ProcessThread::ProcessThread(Widget *win)
{
    processStatus = PROCESSINIT;
    this->win = win;
}

void ProcessThread::run()
{
    switch(processStatus)
    {
    case EXPORTRUNNING:
    {
        processStatus = PROCESSINIT;
        emit send_startcmd(win->ExportFunction(filename));
    }break;
    case BACKUPRUNNING:
    {
        processStatus = PROCESSINIT;
        emit send_startcmd(win->BackupFunction(filename));
    }break;

    }
}
void ProcessThread::SetFilename(QString filename)
{
    this->filename = filename;
}
void ProcessThread::SetProcess(int status)
{
    this->processStatus = status;
}
