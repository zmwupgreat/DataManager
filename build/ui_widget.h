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
    QLabel *label;
    QLabel *label_2;
    QToolButton *toolButtonInput;
    QToolButton *toolButton_8;
    QToolButton *toolButtonDelete;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton_12;
    QToolButton *toolButtonexit;
    QToolButton *toolButton_14;
    QTableView *tableView;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1234, 785);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 1211, 761));
        groupBox->setStyleSheet(QStringLiteral(""));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 140, 151, 201));
        label->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 251, 51));
        label_2->setStyleSheet(QStringLiteral("font-size:25px"));
        toolButtonInput = new QToolButton(groupBox);
        toolButtonInput->setObjectName(QStringLiteral("toolButtonInput"));
        toolButtonInput->setGeometry(QRect(0, 60, 141, 51));
        toolButton_8 = new QToolButton(groupBox);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setGeometry(QRect(140, 60, 141, 51));
        toolButtonDelete = new QToolButton(groupBox);
        toolButtonDelete->setObjectName(QStringLiteral("toolButtonDelete"));
        toolButtonDelete->setGeometry(QRect(280, 60, 141, 51));
        toolButton_10 = new QToolButton(groupBox);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        toolButton_10->setGeometry(QRect(420, 60, 141, 51));
        toolButton_11 = new QToolButton(groupBox);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        toolButton_11->setGeometry(QRect(700, 60, 141, 51));
        toolButton_12 = new QToolButton(groupBox);
        toolButton_12->setObjectName(QStringLiteral("toolButton_12"));
        toolButton_12->setGeometry(QRect(560, 60, 141, 51));
        toolButtonexit = new QToolButton(groupBox);
        toolButtonexit->setObjectName(QStringLiteral("toolButtonexit"));
        toolButtonexit->setGeometry(QRect(1090, 10, 101, 31));
        toolButton_14 = new QToolButton(groupBox);
        toolButton_14->setObjectName(QStringLiteral("toolButton_14"));
        toolButton_14->setGeometry(QRect(840, 60, 141, 51));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(330, 350, 851, 361));
        treeWidget = new QTreeWidget(groupBox);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(20, 140, 281, 611));
        treeWidget->setColumnCount(0);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        toolButtonInput->setText(QApplication::translate("Widget", "\350\276\223\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        toolButton_8->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", Q_NULLPTR));
        toolButtonDelete->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
        toolButton_10->setText(QApplication::translate("Widget", "\345\257\274\345\205\245", Q_NULLPTR));
        toolButton_11->setText(QApplication::translate("Widget", "\345\244\207\344\273\275", Q_NULLPTR));
        toolButton_12->setText(QApplication::translate("Widget", "\345\257\274\345\207\272", Q_NULLPTR));
        toolButtonexit->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", Q_NULLPTR));
        toolButton_14->setText(QApplication::translate("Widget", "\346\211\223\345\215\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
