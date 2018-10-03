/********************************************************************************
** Form generated from reading UI file 'inputwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTWIDGET_H
#define UI_INPUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *labelPhoto;
    QDateEdit *dateEditBirth;
    QLineEdit *lineEditID;
    QToolButton *FiletoolButton;
    QLineEdit *lineEditName;
    QLineEdit *lineEditNation;
    QLineEdit *lineEditAddress;
    QComboBox *comboBoxgender;
    QLineEdit *lineEditoffice;
    QToolButton *toolButtonCheck;
    QToolButton *toolButtoncancel;

    void setupUi(QWidget *InputWidget)
    {
        if (InputWidget->objectName().isEmpty())
            InputWidget->setObjectName(QStringLiteral("InputWidget"));
        InputWidget->resize(459, 508);
        label = new QLabel(InputWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 131, 41));
        label->setStyleSheet(QString::fromUtf8("font: 25 24pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_2 = new QLabel(InputWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 90, 71, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 15pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_3 = new QLabel(InputWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 61, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 15pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_4 = new QLabel(InputWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 180, 61, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 15pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_5 = new QLabel(InputWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 150, 61, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 25 15pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_6 = new QLabel(InputWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 210, 61, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 25 15pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_7 = new QLabel(InputWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 270, 91, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 25 15pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_8 = new QLabel(InputWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 240, 61, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 25 15pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        label_9 = new QLabel(InputWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 300, 61, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 25 15pt \"Adobe \345\256\213\344\275\223 Std L\";"));
        labelPhoto = new QLabel(InputWidget);
        labelPhoto->setObjectName(QStringLiteral("labelPhoto"));
        labelPhoto->setGeometry(QRect(160, 310, 231, 131));
        labelPhoto->setStyleSheet(QStringLiteral("background-color:white"));
        dateEditBirth = new QDateEdit(InputWidget);
        dateEditBirth->setObjectName(QStringLiteral("dateEditBirth"));
        dateEditBirth->setGeometry(QRect(160, 240, 110, 22));
        lineEditID = new QLineEdit(InputWidget);
        lineEditID->setObjectName(QStringLiteral("lineEditID"));
        lineEditID->setGeometry(QRect(160, 90, 241, 25));
        FiletoolButton = new QToolButton(InputWidget);
        FiletoolButton->setObjectName(QStringLiteral("FiletoolButton"));
        FiletoolButton->setGeometry(QRect(100, 310, 51, 21));
        lineEditName = new QLineEdit(InputWidget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(160, 120, 241, 25));
        lineEditNation = new QLineEdit(InputWidget);
        lineEditNation->setObjectName(QStringLiteral("lineEditNation"));
        lineEditNation->setGeometry(QRect(160, 180, 241, 25));
        lineEditAddress = new QLineEdit(InputWidget);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));
        lineEditAddress->setGeometry(QRect(160, 210, 241, 25));
        comboBoxgender = new QComboBox(InputWidget);
        comboBoxgender->setObjectName(QStringLiteral("comboBoxgender"));
        comboBoxgender->setGeometry(QRect(160, 150, 69, 22));
        lineEditoffice = new QLineEdit(InputWidget);
        lineEditoffice->setObjectName(QStringLiteral("lineEditoffice"));
        lineEditoffice->setGeometry(QRect(160, 270, 241, 25));
        toolButtonCheck = new QToolButton(InputWidget);
        toolButtonCheck->setObjectName(QStringLiteral("toolButtonCheck"));
        toolButtonCheck->setGeometry(QRect(60, 450, 91, 31));
        toolButtoncancel = new QToolButton(InputWidget);
        toolButtoncancel->setObjectName(QStringLiteral("toolButtoncancel"));
        toolButtoncancel->setGeometry(QRect(290, 450, 91, 31));

        retranslateUi(InputWidget);

        QMetaObject::connectSlotsByName(InputWidget);
    } // setupUi

    void retranslateUi(QWidget *InputWidget)
    {
        InputWidget->setWindowTitle(QApplication::translate("InputWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("InputWidget", "\344\277\241\346\201\257\350\276\223\345\205\245", Q_NULLPTR));
        label_2->setText(QApplication::translate("InputWidget", "\345\267\245\344\275\234ID\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("InputWidget", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("InputWidget", "\346\260\221\346\227\217\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("InputWidget", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("InputWidget", "\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("InputWidget", "\347\255\276\345\217\221\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("InputWidget", "\347\224\237\346\227\245\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("InputWidget", "\347\205\247\347\211\207\357\274\232", Q_NULLPTR));
        labelPhoto->setText(QString());
        FiletoolButton->setText(QApplication::translate("InputWidget", "\346\265\217\350\247\210", Q_NULLPTR));
        toolButtonCheck->setText(QApplication::translate("InputWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        toolButtoncancel->setText(QApplication::translate("InputWidget", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputWidget: public Ui_InputWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTWIDGET_H
