#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QImage>
#include <QFile>
#include <QFileDialog>
#include <QDateTime>
#include "struct_define.h"
#include "databasecontrol.h"

namespace Ui {
class InputWidget;
}

class InputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputWidget(QWidget *parent = 0);
    ~InputWidget();
    void ClearEdit();

private:
    Ui::InputWidget *ui;
    DataBaseControl *DBcontrol = DataBaseControl::GetDatabase();//数据库对象
    QString ImagePath;
public slots:
    void InsertBtn();
    void SelectImage();
signals:
    void sendRet(bool);
};

#endif // INPUTWIDGET_H
