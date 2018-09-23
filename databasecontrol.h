#ifndef DATABASECONTROL_H
#define DATABASECONTROL_H

#include "struct_define.h"
#include <QString>
#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

#define DATABASEPATH "./data/database/database.db"
class DataBaseControl
{
public:
    //DataBaseControl();
    bool DatabaseConnect(QString dbpath); //按照数据库路径连接数据库
    void CreateDatabase();//创建数据库
    int SelectallData(QString condition); //根据条件查询所有数据
    bool DeleteData(QString condition); //根据条件删除数据
    bool InsertData(InfoData infodata); //插入数据库
    //单例模式声明数据库类
    static DataBaseControl* GetDatabase()
    {
        if(MainDB == NULL)
        {
            MainDB = new DataBaseControl;
        }
        return MainDB;
    }
private:
    static DataBaseControl *MainDB;
    DataBaseControl();
    QSqlDatabase DataBase;//数据库

};

#endif // DATABASECONTROL_H
