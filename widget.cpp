#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    CheckDir();
}

Widget::~Widget()
{
    delete ui;
}
/*
 * 检查数据目录是否完整
 */
void Widget::CheckDir()
{
    QDir dataDir;
    QDir databaseDir;

    QString dataPath = "data/";
    QString dbPath = "data/database/";


    if(!dataDir.exists(dataPath))
        dataDir.mkpath(dataPath);
    if(!databaseDir.exists(dbPath))
        databaseDir.mkpath(dbPath);
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
