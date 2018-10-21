#include "searchform.h"
#include "ui_searchform.h"

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
    ui->comboBoxgender->addItem("男");
    ui->comboBoxgender->addItem("女");
    connect(ui->toolButtoncheck,SIGNAL(clicked(bool)),SLOT(onCheckbtn()));
    connect(ui->toolButtoncancel,SIGNAL(clicked(bool)),SLOT(close()));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}

SearchForm::~SearchForm()
{
    delete ui;
}
/*
 * 查询确定
 */
void SearchForm::onCheckbtn()
{
    QString condition = "";

    if(!ui->lineEditID->text().isEmpty())
    {
        condition += QString("and ID='%1'").arg(ui->lineEditID->text());
    }
    if(!ui->lineEditName->text().isEmpty())
    {
        condition += QString("and Name like '%1%'").arg(ui->lineEditName->text());
    }
    if(!ui->lineEditNation->text().isEmpty())
    {
        condition += QString("and Nation='%1'").arg(ui->lineEditNation->text());
    }
    if(!ui->lineEditOffice->text().isEmpty())
    {
        condition += QString("and Office='%1'").arg(ui->lineEditOffice->text());
    }
    if(condition == "")
    {
        QMessageBox::warning(NULL,"提示","请输入查询条件","确定");
    }
    else
    {
        condition += QString("and Gender='%1'").arg(ui->comboBoxgender->currentText());
        emit sendCondition(condition);
        this->close();
    }
}
/*
 * 清理输入框
 */
void SearchForm::CleanEdit()
{
    ui->lineEditID->clear();
    ui->lineEditName->clear();
    ui->lineEditNation->clear();
    ui->lineEditOffice->clear();
}
