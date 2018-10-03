#include "inputwidget.h"
#include "ui_inputwidget.h"

InputWidget::InputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputWidget)
{
    ui->setupUi(this);
    ui->comboBoxgender->addItem("男");
    ui->comboBoxgender->addItem("女");
    ui->dateEditBirth->setCalendarPopup(true);
    QDate date = QDate::currentDate();
    ui->dateEditBirth->setDisplayFormat("yyyy/MM/dd");
    ui->dateEditBirth->setDate(date);
    connect(ui->toolButtoncancel,SIGNAL(clicked(bool)),SLOT(close()));
    connect(ui->toolButtonCheck,SIGNAL(clicked(bool)),SLOT(InsertBtn()));
    connect(ui->FiletoolButton,SIGNAL(clicked(bool)),SLOT(SelectImage()));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}

InputWidget::~InputWidget()
{
    delete ui;
}
/*
 * 获取图片
 */
void InputWidget::SelectImage()
{
    ImagePath = QFileDialog::getOpenFileName(NULL,tr("选择数据库文件"),".","*.jpg *.bmp *.png *.jpeg");
        if(ImagePath.isEmpty())
            return;
        else
        {
            QImage photo;
            photo.load(ImagePath);
            photo = photo.scaled(231,131,Qt::KeepAspectRatio);
            ui->labelPhoto->setPixmap(QPixmap::fromImage(photo));
        }
}

/*
 * 确定按钮槽，插入数据
 */
void InputWidget::InsertBtn()
{
    InfoData InsertInfo;
    if(ui->lineEditID->text().isEmpty()
            ||ui->lineEditName->text().isEmpty()
            ||ui->lineEditNation->text().isEmpty())
    {
           QMessageBox::warning(NULL,"提示","请确定输入完整ID，姓名，民族","确定");
           return;
    }
    InsertInfo.ID = ui->lineEditID->text();
    InsertInfo.Name = ui->lineEditName->text();
    QDateTime time = QDateTime::currentDateTime();
    InsertInfo.Time = time.toString("yyyy/MM/dd hh:mm:ss");
    InsertInfo.Birthtime = ui->dateEditBirth->text();
    InsertInfo.Gender = ui->comboBoxgender->currentText();
    InsertInfo.Nation = ui->lineEditNation->text();
    if(ui->lineEditAddress->text().isEmpty())
        InsertInfo.Address = " ";
    else
        InsertInfo.Address = ui->lineEditAddress->text();
    if(ui->lineEditoffice->text().isEmpty())
        InsertInfo.Office = " ";
    else
        InsertInfo.Office = ui->lineEditoffice->text();
    QString ImageFile = ImagePath;
    QString newfilename = "../../data/Image/"+InsertInfo.ID+".jpg";
    QFile::copy(ImageFile,newfilename);
    InsertInfo.Image = newfilename;
    if(!DBcontrol->InsertData(InsertInfo))
    {
        emit sendRet(false);
        this->close();
        return;
    }
    else
    {
        emit sendRet(true);
        this->close();
        return;
    }
}

/*
 * 清理输入框
 */
void InputWidget::ClearEdit()
{
    ui->lineEditID->clear();
    ui->lineEditName->clear();
    ui->lineEditNation->clear();
    ui->lineEditoffice->clear();
    ui->lineEditAddress->clear();
    ui->labelPhoto->clear();
}
