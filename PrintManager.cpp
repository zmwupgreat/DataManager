#include "PrintManager.h"
#include <string>

#include <QDebug>
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
PrintManager::PrintManager()
{

}

PrintManager::~PrintManager()
{

}

void PrintManager::PrintDocument()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::Custom);
    printer.setPaperSize(QSizeF(600,600),QPrinter::Point);

    QPrintPreviewDialog preview(&printer, this);

    // 当要生成预览页面时，发射paintRequested()信号
    connect(&preview, SIGNAL(paintRequested(QPrinter*)),this,SLOT(printPreview(QPrinter*)));

    preview.setWindowTitle(tr("文件打印预览"));
    preview.exec();
}

void PrintManager::printPreview(QPrinter *printer)
{
    QTextEdit *ted = new QTextEdit;
    ted->insertHtml(html);
    ted->document()->print(printer);

}
//创建html
void PrintManager::CreateHTML(InfoData data)
{
    html.clear();
    html+="<html><body><table width=\"580\" height=\"1024\"border=\"1\" align=\"center\">";
    html+="<caption><h1>身份信息凭证</h1><caption>";
    html+="<tr><td width=\"130\">姓名</td>";
    html+="<td>"+data.Name+"</td>";
    html+="<td rowspan=\"5\" width=\"102\"height=\"126\"><img src =\""+data.Image+"\" align=\"top\"></td></tr>";
    html+="<tr><td width=\"130\">证件ID号</td><td>"+data.ID+"</td></tr>";
    html+="<tr><td width=\"130\">性别</td><td>"+data.Gender+"</td></tr>";
    html+="<tr><td width=\"130\">民族</td><td>"+data.Nation+"</td></tr>";
    html+="<tr><td>出生年月</td><td>"+data.Birthtime+"</td></tr>";
    html+="<tr><td>住址</td><td colspan=\"2\">"+data.Address+"</td></tr>";
    html+="<tr><td>签发机关</td><td colspan=\"2\">"+data.Office+"</td></tr>";
    html+="<tr><td>录入时间</td><td colspan=\"2\">"+data.Time+"</td></tr></table></body></html>";
}
