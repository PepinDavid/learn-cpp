/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../webnavigator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 4),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 4),
QT_MOC_LITERAL(4, 22, 4),
QT_MOC_LITERAL(5, 27, 4),
QT_MOC_LITERAL(6, 32, 9),
QT_MOC_LITERAL(7, 42, 5),
QT_MOC_LITERAL(8, 48, 6),
QT_MOC_LITERAL(9, 55, 8),
QT_MOC_LITERAL(10, 64, 8),
QT_MOC_LITERAL(11, 73, 9),
QT_MOC_LITERAL(12, 83, 5),
QT_MOC_LITERAL(13, 89, 11),
QT_MOC_LITERAL(14, 101, 9),
QT_MOC_LITERAL(15, 111, 9),
QT_MOC_LITERAL(16, 121, 3),
QT_MOC_LITERAL(17, 125, 9),
QT_MOC_LITERAL(18, 135, 14),
QT_MOC_LITERAL(19, 150, 7),
QT_MOC_LITERAL(20, 158, 7),
QT_MOC_LITERAL(21, 166, 2)
    },
    "MainWindow\0undo\0\0redo\0home\0stop\0"
    "actualise\0about\0newTab\0closeTab\0"
    "loadPage\0changeTab\0index\0changeTitle\0"
    "fullTitle\0changeUrl\0url\0loadBegin\0"
    "loadInProgress\0percent\0loadEnd\0ok\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a,
       3,    0,   90,    2, 0x0a,
       4,    0,   91,    2, 0x0a,
       5,    0,   92,    2, 0x0a,
       6,    0,   93,    2, 0x0a,
       7,    0,   94,    2, 0x0a,
       8,    0,   95,    2, 0x0a,
       9,    0,   96,    2, 0x0a,
      10,    0,   97,    2, 0x0a,
      11,    1,   98,    2, 0x0a,
      13,    1,  101,    2, 0x0a,
      15,    1,  104,    2, 0x0a,
      17,    0,  107,    2, 0x0a,
      18,    1,  108,    2, 0x0a,
      20,    1,  111,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QUrl,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->undo(); break;
        case 1: _t->redo(); break;
        case 2: _t->home(); break;
        case 3: _t->stop(); break;
        case 4: _t->actualise(); break;
        case 5: _t->about(); break;
        case 6: _t->newTab(); break;
        case 7: _t->closeTab(); break;
        case 8: _t->loadPage(); break;
        case 9: _t->changeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->changeTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->changeUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 12: _t->loadBegin(); break;
        case 13: _t->loadInProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->loadEnd((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
