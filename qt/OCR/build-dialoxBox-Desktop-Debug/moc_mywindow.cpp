/****************************************************************************
** Meta object code from reading C++ file 'mywindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialoxBox/mywindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x0a,
      40,   33,    9,    9, 0x0a,
      58,    9,    9,    9, 0x0a,
      74,    9,    9,    9, 0x0a,
      93,    9,    9,    9, 0x0a,
     108,    9,    9,    9, 0x0a,
     125,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyWindow[] = {
    "MyWindow\0\0width\0changeWidth(int)\0"
    "height\0changeHeight(int)\0openDialHello()\0"
    "openDialQuestion()\0openDialText()\0"
    "openChangeFont()\0openChangeColor()\0"
};

void MyWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyWindow *_t = static_cast<MyWindow *>(_o);
        switch (_id) {
        case 0: _t->changeWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->openDialHello(); break;
        case 3: _t->openDialQuestion(); break;
        case 4: _t->openDialText(); break;
        case 5: _t->openChangeFont(); break;
        case 6: _t->openChangeColor(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWindow,
      qt_meta_data_MyWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWindow))
        return static_cast<void*>(const_cast< MyWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
