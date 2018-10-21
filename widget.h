#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>
#include <QTableView>
#include <QMouseEvent>
#include <QVector>
#include <QDebug>
#include <QStandardItemModel>
#include <QTreeWidgetItem>
#include <QAxObject>
#include <QThread>
#include <QFileDialog>
#include "loadingform.h"
#include "databasecontrol.h"
#include "struct_define.h"
#include "inputwidget.h"
#include "PrintManager.h"
#include "searchform.h"
#define PROCESSINIT 0
#define EXPORTRUNNING 1
#define IMPORTRUNNING 2
#define BACKUPRUNNING 3

#define EXPORTFINISH 4
#define IMPORTFINISH 5
#define BACKUPFINISH 6

class ProcessThread;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void InitObject();//初始化模块
    void CheckDir();//检查文件路径
    void TableViewInit(QString condition);//初始化表结构
    void TreeWidgetInit();//初始化树结构
    void deleteTreeItem();//删除所有树节点
    void TreewidgetIteminit();//根据数据库时间生成树节点
    int ExportFunction(QString filename);//导出功能函数

public slots:
    void btnInput();//添加信息槽
    void handleInputResultMSG(bool ret);//接收信息输入结果
    void btnExit(); //退出槽
    void btnDelete();//删除槽
    void btnExport();//导出槽
    void btnPrinter();//打印槽
    void btnSearch();//查询槽
    void handleConditionMSG(QString condition);//接收查询条件
    void TreeitemClick(QTreeWidgetItem *item, int column);//点击树节点相应槽
    void TableitemClick();//点击表节点对应槽
    void handleFinishMSG(int MSG); //接收线程结束信息

private:
    QPoint last;//智能指针 用于界面移动鼠标事件重写
    Ui::Widget *ui;
    QSqlQueryModel *TableModel;//数据表显示模型
    InputWidget *Inputwidget;//输入窗口
    DataBaseControl *DBcontrol = DataBaseControl::GetDatabase();//获取数据库指针
    //Excel导出相关实例
    QAxObject *excel;
    QAxObject *workBooks;
    QAxObject *workBook;
    QAxObject *workSheets;
    QAxObject *workSheet;
    LoadingForm *loadingwindow;
    ProcessThread *process;
    PrintManager *printer;
    SearchForm *searchwidget;


protected://重写鼠标事件，使窗口可移动
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
};
/*
 * 执行线程
 */
class ProcessThread : public QThread
{
    Q_OBJECT
public:
    ProcessThread(Widget *win);
    void SetProcess(int status);
    void SetFilename(QString filename);
signals:
    void send_startcmd(int MSG);

private:
    Widget *win;
    int processStatus;
    QString filename;
    void run();
};

#endif // WIDGET_H
