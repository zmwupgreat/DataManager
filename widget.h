#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QTreeWidgetItem>
#include "databasecontrol.h"
#include "struct_define.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    CheckDir();
    void TableViewInit();
public slots:
    void btnInput();//添加信息槽
private:
    QPoint last;//智能指针 用于界面移动鼠标事件重写
    Ui::Widget *ui;
    QSqlQueryModel *TableModel;//数据表显示模型
    DataBaseControl *DBControl = DataBaseControl::GetDatabase();//获取数据库类指针

protected://重写鼠标事件，使窗口可移动
        void mousePressEvent(QMouseEvent *e);
        void mouseMoveEvent(QMouseEvent *e);
        void mouseReleaseEvent(QMouseEvent *e);
        void paintEvent(QPaintEvent *e);
};

#endif // WIDGET_H
