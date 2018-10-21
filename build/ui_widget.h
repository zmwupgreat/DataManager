/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QLabel *labelphoto;
    QLabel *label_2;
    QToolButton *toolButtonInput;
    QToolButton *toolButtonSearch;
    QToolButton *toolButtonDelete;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButtonExport;
    QToolButton *toolButtonexit;
    QToolButton *toolButtonPrinter;
    QTableView *tableView;
    QTreeWidget *treeWidget;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *labelID;
    QLabel *labelname;
    QLabel *labelgender;
    QLabel *labelbirth;
    QLabel *labeladdress;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1234, 785);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 1211, 761));
        groupBox->setStyleSheet(QStringLiteral(""));
        labelphoto = new QLabel(groupBox);
        labelphoto->setObjectName(QStringLiteral("labelphoto"));
        labelphoto->setGeometry(QRect(470, 140, 151, 201));
        labelphoto->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 251, 51));
        label_2->setStyleSheet(QStringLiteral("font-size:25px"));
        toolButtonInput = new QToolButton(groupBox);
        toolButtonInput->setObjectName(QStringLiteral("toolButtonInput"));
        toolButtonInput->setGeometry(QRect(0, 60, 141, 51));
        toolButtonSearch = new QToolButton(groupBox);
        toolButtonSearch->setObjectName(QStringLiteral("toolButtonSearch"));
        toolButtonSearch->setGeometry(QRect(140, 60, 141, 51));
        toolButtonDelete = new QToolButton(groupBox);
        toolButtonDelete->setObjectName(QStringLiteral("toolButtonDelete"));
        toolButtonDelete->setGeometry(QRect(280, 60, 141, 51));
        toolButton_10 = new QToolButton(groupBox);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        toolButton_10->setGeometry(QRect(420, 60, 141, 51));
        toolButton_11 = new QToolButton(groupBox);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        toolButton_11->setGeometry(QRect(700, 60, 141, 51));
        toolButtonExport = new QToolButton(groupBox);
        toolButtonExport->setObjectName(QStringLiteral("toolButtonExport"));
        toolButtonExport->setGeometry(QRect(560, 60, 141, 51));
        toolButtonexit = new QToolButton(groupBox);
        toolButtonexit->setObjectName(QStringLiteral("toolButtonexit"));
        toolButtonexit->setGeometry(QRect(1090, 10, 101, 31));
        toolButtonPrinter = new QToolButton(groupBox);
        toolButtonPrinter->setObjectName(QStringLiteral("toolButtonPrinter"));
        toolButtonPrinter->setGeometry(QRect(840, 60, 141, 51));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(330, 350, 851, 361));
        treeWidget = new QTreeWidget(groupBox);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(20, 140, 281, 611));
        treeWidget->setColumnCount(0);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(700, 140, 81, 21));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(700, 180, 81, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(700, 220, 81, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(700, 260, 81, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(700, 300, 81, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        labelID = new QLabel(groupBox);
        labelID->setObjectName(QStringLiteral("labelID"));
        labelID->setGeometry(QRect(820, 140, 221, 21));
        labelname = new QLabel(groupBox);
        labelname->setObjectName(QStringLiteral("labelname"));
        labelname->setGeometry(QRect(820, 180, 221, 21));
        labelgender = new QLabel(groupBox);
        labelgender->setObjectName(QStringLiteral("labelgender"));
        labelgender->setGeometry(QRect(820, 220, 221, 21));
        labelbirth = new QLabel(groupBox);
        labelbirth->setObjectName(QStringLiteral("labelbirth"));
        labelbirth->setGeometry(QRect(820, 260, 221, 21));
        labeladdress = new QLabel(groupBox);
        labeladdress->setObjectName(QStringLiteral("labeladdress"));
        labeladdress->setGeometry(QRect(820, 300, 221, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        groupBox->setTitle(QString());
        labelphoto->setText(QString());
        label_2->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        toolButtonInput->setText(QApplication::translate("Widget", "\350\276\223\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        toolButtonSearch->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", Q_NULLPTR));
        toolButtonDelete->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
        toolButton_10->setText(QApplication::translate("Widget", "\345\257\274\345\205\245", Q_NULLPTR));
        toolButton_11->setText(QApplication::translate("Widget", "\345\244\207\344\273\275", Q_NULLPTR));
        toolButtonExport->setText(QApplication::translate("Widget", "\345\257\274\345\207\272", Q_NULLPTR));
        toolButtonexit->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", Q_NULLPTR));
        toolButtonPrinter->setText(QApplication::translate("Widget", "\346\211\223\345\215\260", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\350\257\201\344\273\266\345\217\267\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\345\207\272\347\224\237\345\271\264\346\234\210\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        labelID->setText(QString());
        labelname->setText(QString());
        labelgender->setText(QString());
        labelbirth->setText(QString());
        labeladdress->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
