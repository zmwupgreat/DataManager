/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[19];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 8), // "btnInput"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 20), // "handleInputResultMSG"
QT_MOC_LITERAL(4, 38, 3), // "ret"
QT_MOC_LITERAL(5, 42, 7), // "btnExit"
QT_MOC_LITERAL(6, 50, 9), // "btnDelete"
QT_MOC_LITERAL(7, 60, 9), // "btnExport"
QT_MOC_LITERAL(8, 70, 10), // "btnPrinter"
QT_MOC_LITERAL(9, 81, 9), // "btnSearch"
QT_MOC_LITERAL(10, 91, 18), // "handleConditionMSG"
QT_MOC_LITERAL(11, 110, 9), // "condition"
QT_MOC_LITERAL(12, 120, 13), // "TreeitemClick"
QT_MOC_LITERAL(13, 134, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(14, 151, 4), // "item"
QT_MOC_LITERAL(15, 156, 6), // "column"
QT_MOC_LITERAL(16, 163, 14), // "TableitemClick"
QT_MOC_LITERAL(17, 178, 15), // "handleFinishMSG"
QT_MOC_LITERAL(18, 194, 3) // "MSG"

    },
    "Widget\0btnInput\0\0handleInputResultMSG\0"
    "ret\0btnExit\0btnDelete\0btnExport\0"
    "btnPrinter\0btnSearch\0handleConditionMSG\0"
    "condition\0TreeitemClick\0QTreeWidgetItem*\0"
    "item\0column\0TableitemClick\0handleFinishMSG\0"
    "MSG"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    1,   70,    2, 0x0a /* Public */,
       5,    0,   73,    2, 0x0a /* Public */,
       6,    0,   74,    2, 0x0a /* Public */,
       7,    0,   75,    2, 0x0a /* Public */,
       8,    0,   76,    2, 0x0a /* Public */,
       9,    0,   77,    2, 0x0a /* Public */,
      10,    1,   78,    2, 0x0a /* Public */,
      12,    2,   81,    2, 0x0a /* Public */,
      16,    0,   86,    2, 0x0a /* Public */,
      17,    1,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->btnInput(); break;
        case 1: _t->handleInputResultMSG((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->btnExit(); break;
        case 3: _t->btnDelete(); break;
        case 4: _t->btnExport(); break;
        case 5: _t->btnPrinter(); break;
        case 6: _t->btnSearch(); break;
        case 7: _t->handleConditionMSG((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->TreeitemClick((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->TableitemClick(); break;
        case 10: _t->handleFinishMSG((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
struct qt_meta_stringdata_ProcessThread_t {
    QByteArrayData data[4];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessThread_t qt_meta_stringdata_ProcessThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ProcessThread"
QT_MOC_LITERAL(1, 14, 13), // "send_startcmd"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3) // "MSG"

    },
    "ProcessThread\0send_startcmd\0\0MSG"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void ProcessThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProcessThread *_t = static_cast<ProcessThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_startcmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProcessThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProcessThread::send_startcmd)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ProcessThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ProcessThread.data,
      qt_meta_data_ProcessThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProcessThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessThread.stringdata0))
        return static_cast<void*>(const_cast< ProcessThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ProcessThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ProcessThread::send_startcmd(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
