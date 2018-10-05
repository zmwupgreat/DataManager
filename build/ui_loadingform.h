/********************************************************************************
** Form generated from reading UI file 'loadingform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGFORM_H
#define UI_LOADINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingForm
{
public:
    QLabel *label;

    void setupUi(QWidget *LoadingForm)
    {
        if (LoadingForm->objectName().isEmpty())
            LoadingForm->setObjectName(QStringLiteral("LoadingForm"));
        LoadingForm->resize(334, 106);
        label = new QLabel(LoadingForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 241, 51));
        label->setStyleSheet(QString::fromUtf8("font: 28pt \"\351\273\221\344\275\223\";"));

        retranslateUi(LoadingForm);

        QMetaObject::connectSlotsByName(LoadingForm);
    } // setupUi

    void retranslateUi(QWidget *LoadingForm)
    {
        LoadingForm->setWindowTitle(QApplication::translate("LoadingForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("LoadingForm", "\350\257\267\347\250\215\347\255\211......", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadingForm: public Ui_LoadingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGFORM_H
