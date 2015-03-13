/****************************************************************************
** Meta object code from reading C++ file 'startmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "startmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_startmenu_t {
    QByteArrayData data[15];
    char stringdata[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_startmenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_startmenu_t qt_meta_stringdata_startmenu = {
    {
QT_MOC_LITERAL(0, 0, 9), // "startmenu"
QT_MOC_LITERAL(1, 10, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(4, 59, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 81, 13), // "CreateAccount"
QT_MOC_LITERAL(6, 95, 8), // "Username"
QT_MOC_LITERAL(7, 104, 8), // "Password"
QT_MOC_LITERAL(8, 113, 13), // "CheckUsername"
QT_MOC_LITERAL(9, 127, 23), // "on_lineEdit_textChanged"
QT_MOC_LITERAL(10, 151, 4), // "arg1"
QT_MOC_LITERAL(11, 156, 24), // "on_label_7_linkActivated"
QT_MOC_LITERAL(12, 181, 4), // "link"
QT_MOC_LITERAL(13, 186, 24), // "on_lineEdit_3_textEdited"
QT_MOC_LITERAL(14, 211, 24) // "on_lineEdit_2_textEdited"

    },
    "startmenu\0on_radioButton_clicked\0\0"
    "on_radioButton_2_clicked\0on_pushButton_clicked\0"
    "CreateAccount\0Username\0Password\0"
    "CheckUsername\0on_lineEdit_textChanged\0"
    "arg1\0on_label_7_linkActivated\0link\0"
    "on_lineEdit_3_textEdited\0"
    "on_lineEdit_2_textEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_startmenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    2,   62,    2, 0x08 /* Private */,
       8,    1,   67,    2, 0x08 /* Private */,
       9,    1,   70,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,
      13,    1,   76,    2, 0x08 /* Private */,
      14,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void startmenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        startmenu *_t = static_cast<startmenu *>(_o);
        switch (_id) {
        case 0: _t->on_radioButton_clicked(); break;
        case 1: _t->on_radioButton_2_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->CreateAccount((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: { bool _r = _t->CheckUsername((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_label_7_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_lineEdit_3_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_lineEdit_2_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject startmenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_startmenu.data,
      qt_meta_data_startmenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *startmenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *startmenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_startmenu.stringdata))
        return static_cast<void*>(const_cast< startmenu*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int startmenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
