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
        QString dbPath = "./data/database";
                QDir dbDir;
                if(!dbDir.exists(dbPath))
                    dbDir.mkpath(dbPath);
                creat_database();
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
    SQLstr += QString("Address varchr ,");
    SQLstr += QString("Office TEXT,");
    SQLstr += QString("ValidTime varchar NOT NULL,");
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


