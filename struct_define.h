#ifndef STRUCT_DEFINE_H
#define STRUCT_DEFINE_H
#include <QString>
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
/*
 * 结构体定义
 */
typedef struct InfoData
{
    QString ID;
    QString Name;
    QString Time;
    QString Gender;
    QString Nation;
    QString Birthtime;
    QString Address;
    QString Office;
    QString Image;
}InfoData;

#endif // STRUCT_DEFINE_H
