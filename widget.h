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
#include <QStandardItemModel>
#include <QTreeWidgetItem>
#include "databasecontrol.h"
#include "struct_define.h"
#include "inputwidget.h"

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

public slots:
    void btnInput();//添加信息槽
    void handleInputResultMSG(bool ret);//接收信息输入结果
    void btnExit(); //退出槽
    void btnDelete();//删除槽
    void TreeitemClick(QTreeWidgetItem *item, int column);//点击树节点相应槽

private:
    QPoint last;//智能指针 用于界面移动鼠标事件重写
    Ui::Widget *ui;
    QSqlQueryModel *TableModel;//数据表显示模型
    InputWidget *Inputwidget;//输入窗口
    DataBaseControl *DBcontrol = DataBaseControl::GetDatabase();//获取数据库指针
    bool Treeitem_select;

protected://重写鼠标事件，使窗口可移动
        void mousePressEvent(QMouseEvent *e);
        void mouseMoveEvent(QMouseEvent *e);
        void mouseReleaseEvent(QMouseEvent *e);
};

#endif // WIDGET_H
