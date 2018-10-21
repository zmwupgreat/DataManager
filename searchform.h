#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QWidget>
#include <QMessageBox>
#include "struct_define.h"
namespace Ui {
class SearchForm;
}

class SearchForm : public QWidget
{
    Q_OBJECT

public:
    explicit SearchForm(QWidget *parent = 0);
    ~SearchForm();
    void CleanEdit();
public slots:
    void onCheckbtn();
signals:
    void sendCondition(QString condition);
private:
    Ui::SearchForm *ui;
};

#endif // SEARCHFORM_H
