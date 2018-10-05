#ifndef LOADINGFORM_H
#define LOADINGFORM_H

#include <QWidget>

namespace Ui {
class LoadingForm;
}

class LoadingForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingForm(QWidget *parent = 0);
    ~LoadingForm();

private:
    Ui::LoadingForm *ui;
};

#endif // LOADINGFORM_H
