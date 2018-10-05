#ifndef CONSTANT_H
#define CONSTANT_H

#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPageSetupDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QMainWindow>
#include <QPainter>
#include <QString>

#include <QTextEdit>
#include "struct_define.h"
class PrintManager : public QMainWindow
{
    Q_OBJECT
public:
    PrintManager();
    ~PrintManager();

    void PrintDocument();
    void CreateHTML(InfoData data);
private slots:
    void printPreview(QPrinter *printer);
private:
    QString html;

};

#endif // CONSTANT_H
