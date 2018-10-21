/********************************************************************************
** Form generated from reading UI file 'searchform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFORM_H
#define UI_SEARCHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchForm
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QToolButton *toolButtoncheck;
    QToolButton *toolButtoncancel;
    QLineEdit *lineEditID;
    QLineEdit *lineEditName;
    QLineEdit *lineEditNation;
    QLineEdit *lineEditOffice;
    QComboBox *comboBoxgender;

    void setupUi(QWidget *SearchForm)
    {
        if (SearchForm->objectName().isEmpty())
            SearchForm->setObjectName(QStringLiteral("SearchForm"));
        SearchForm->resize(459, 508);
        label = new QLabel(SearchForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 131, 41));
        label->setStyleSheet(QString::fromUtf8("font: 25 24pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_2 = new QLabel(SearchForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 130, 81, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_3 = new QLabel(SearchForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 180, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_4 = new QLabel(SearchForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 230, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_5 = new QLabel(SearchForm);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 280, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_6 = new QLabel(SearchForm);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 330, 81, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 25 14pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        toolButtoncheck = new QToolButton(SearchForm);
        toolButtoncheck->setObjectName(QStringLiteral("toolButtoncheck"));
        toolButtoncheck->setGeometry(QRect(70, 410, 81, 41));
        toolButtoncancel = new QToolButton(SearchForm);
        toolButtoncancel->setObjectName(QStringLiteral("toolButtoncancel"));
        toolButtoncancel->setGeometry(QRect(280, 410, 81, 41));
        lineEditID = new QLineEdit(SearchForm);
        lineEditID->setObjectName(QStringLiteral("lineEditID"));
        lineEditID->setGeometry(QRect(180, 129, 221, 31));
        lineEditName = new QLineEdit(SearchForm);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(180, 180, 221, 31));
        lineEditNation = new QLineEdit(SearchForm);
        lineEditNation->setObjectName(QStringLiteral("lineEditNation"));
        lineEditNation->setGeometry(QRect(180, 280, 221, 31));
        lineEditOffice = new QLineEdit(SearchForm);
        lineEditOffice->setObjectName(QStringLiteral("lineEditOffice"));
        lineEditOffice->setGeometry(QRect(180, 330, 221, 31));
        comboBoxgender = new QComboBox(SearchForm);
        comboBoxgender->setObjectName(QStringLiteral("comboBoxgender"));
        comboBoxgender->setGeometry(QRect(180, 230, 81, 31));

        retranslateUi(SearchForm);

        QMetaObject::connectSlotsByName(SearchForm);
    } // setupUi

    void retranslateUi(QWidget *SearchForm)
    {
        SearchForm->setWindowTitle(QApplication::translate("SearchForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SearchForm", "\346\237\245\350\257\242\346\235\241\344\273\266", Q_NULLPTR));
        label_2->setText(QApplication::translate("SearchForm", "\350\257\201\344\273\266ID\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("SearchForm", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("SearchForm", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("SearchForm", "\346\260\221\346\227\217\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("SearchForm", "\347\255\276\345\217\221\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        toolButtoncheck->setText(QApplication::translate("SearchForm", "\347\241\256\345\256\232", Q_NULLPTR));
        toolButtoncancel->setText(QApplication::translate("SearchForm", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchForm: public Ui_SearchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORM_H
