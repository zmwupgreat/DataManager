#include "databasecontrol.h"
#include <QFile>
#include <QMessageBox>
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif

DataBaseControl* DataBaseControl::MainDB = NULL;

DataBaseControl::DataBaseControl()
{
    QFile DBFile(DATABASEPATH);
    if(DBFile.exists())
    {
        if(!DatabaseConnect(DATABASEPATH))//连接数据库
        {
            QMessageBox::warning(NULL,"提示","数据库启动失败","确定");
            exit(-1);
        }
    }
    else
    {
        QString dbPath = "../../data/database";
                QDir dbDir;
                if(!dbDir.exists(dbPath))
                    dbDir.mkpath(dbPath);
                CreateDatabase();
    }
}
/*
 * 创建数据库
 */
void DataBaseControl::CreateDatabase()
{
    DataBase = QSqlDatabase::addDatabase("QSQLITE");//设置数据库类型
    DataBase.setDatabaseName(DATABASEPATH);//设置数据库
    DataBase.open();//打开数据库
    QSqlQuery CreateTable;
    QString SQLstr = QString("CREATE TABLE DATAMANAGER (ID varchar NOT NULL PRIMARY KEY,");
    SQLstr += QString("Name varchar NOT NULL,");
    SQLstr += QString("Time varchar NOT NULL,");
    SQLstr += QString("Gender varchar NOT NULL,");
    SQLstr += QString("Nation varchar NOT NULL,");
    SQLstr += QString("Birthtime varchar NOT NULL,");
    SQLstr += QString("Address varchr,");
    SQLstr += QString("Office TEXT,");
    SQLstr += QString("Image TEXT)");
    bool ret_create = CreateTable.exec(SQLstr);
    if(!ret_create)
    {
        QMessageBox::warning(NULL,"提示","数据库表创建失败失败","确定");
        return;
    }
}
/*
 * 连接数据库
 */
bool DataBaseControl::DatabaseConnect(QString dbpath)
{
    DataBase = QSqlDatabase::addDatabase("QSQLITE");
    DataBase.setDatabaseName(dbpath);
    if(DataBase.isOpen())
    {
        DataBase.close();
    }
    bool ret = DataBase.open();
    return ret;
}
/*
 * 插入数据
 */
bool DataBaseControl::InsertData(InfoData infodata)
{
    if(!DataBase.isOpen())
        DataBase.open();
    QSqlQuery Insert;
    QString SQLstr = QString("insert into DATAMANAGER values(");
    SQLstr += QString("'%1'").arg(infodata.ID);
    SQLstr += QString(",'%1'").arg(infodata.Name);
    SQLstr += QString(",'%1'").arg(infodata.Time);
    SQLstr += QString(",'%1'").arg(infodata.Gender);
    SQLstr += QString(",'%1'").arg(infodata.Nation);
    SQLstr += QString(",'%1'").arg(infodata.Birthtime);
    SQLstr += QString(",'%1'").arg(infodata.Address);
    SQLstr += QString(",'%1'").arg(infodata.Office);
    SQLstr += QString(",'%1');").arg(infodata.Image);
    bool ret = Insert.exec(SQLstr);
    if(!ret)
        return false;
    else
        return true;
}
/*
 * 显示查询
 */
bool DataBaseControl::SelectallData(QSqlQueryModel *model, QString condition, int limitIndex)
{
    if(!DataBase.isOpen())
        DataBase.open();

    QString SQLstr = QString("select ID,Name,Time,Gender,Nation,Birthtime,Address,Office,Image from DATAMANAGER where 1=1 ");
    SQLstr += condition;
    SQLstr += "order by Time desc ";
    SQLstr += QString("limit %1,%2").arg(QString::number(limitIndex)).arg(QString::number(6));

    model->setQuery(SQLstr);
    DataBase.close();
    return true;

}
/*
 * 查询时间
 */
QVector<QString> DataBaseControl::getTimedata()
{
    if(!DataBase.isOpen())
        DataBase.open();
    QSqlQuery Timequery;
    QVector<QString> Timevector;
    QString SQLstr = QString("select Time from DATAMANAGER");
    Timequery.exec(SQLstr);
    if(!Timequery.first())
    {
        return Timevector;
    }
    while(true)
    {
        QString Time = Timequery.value(0).toString();
        Timevector.append(Time);
        if(!Timequery.next())
            break;
    }
    Timequery.clear();
    DataBase.close();
    return Timevector;
}
/*
 * 删除信息
 */
bool DataBaseControl::DeleteData(QString condition)
{
    if(!DataBase.isOpen())
        DataBase.open();
    QSqlQuery delquery;
    QString SQLstr = QString("delete from DATAMANAGER where ");
    SQLstr += condition;
    qDebug()<<SQLstr;
    bool ret = delquery.exec(SQLstr);
    DataBase.close();
    if(!ret)
        return false;
    else
        return true;
}
/*
 * 获取所有数据
 */
QVector<InfoData> DataBaseControl::GetAllData(QString condition)
{
    if(!DataBase.isOpen())
        DataBase.open();
    QVector<InfoData> Alldata;
    QSqlQuery selectquery;
    QString SQLstr = QString("select * from DATAMANAGER where 1=1 ");
    SQLstr += condition;
    SQLstr += "order by Time";
    selectquery.exec(SQLstr);
    if(!selectquery.first())
    {
        return Alldata;
    }
    while(true)
    {
        InfoData infodata;
        infodata.ID = selectquery.value(0).toString();
        infodata.Name = selectquery.value(1).toString();
        infodata.Time = selectquery.value(2).toString();
        infodata.Gender = selectquery.value(3).toString();
        infodata.Nation = selectquery.value(4).toString();
        infodata.Birthtime = selectquery.value(5).toString();
        infodata.Address  = selectquery.value(6).toString();
        infodata.Office = selectquery.value(7).toString();
        infodata.Image = selectquery.value(8).toString();
        Alldata.append(infodata);
        if(!selectquery.next())
          {
            break;
          }
    }
    return Alldata;
}
/*
 * 关闭数据库
 */
void DataBaseControl::CloseDB()
{
    if(DataBase.isOpen())
        DataBase.close();
}
