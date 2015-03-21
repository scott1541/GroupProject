/****************************************************************************
** Meta object code from reading C++ file 'addpassword.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addpassword.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addpassword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_addPassword_t {
    QByteArrayData data[8];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addPassword_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addPassword_t qt_meta_stringdata_addPassword = {
    {
QT_MOC_LITERAL(0, 0, 11), // "addPassword"
QT_MOC_LITERAL(1, 12, 24), // "on_lineEdit_3_textEdited"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 4), // "arg1"
QT_MOC_LITERAL(4, 43, 24), // "on_lineEdit_5_textEdited"
QT_MOC_LITERAL(5, 68, 14), // "addNewPassword"
QT_MOC_LITERAL(6, 83, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 105, 7) // "checked"

    },
    "addPassword\0on_lineEdit_3_textEdited\0"
    "\0arg1\0on_lineEdit_5_textEdited\0"
    "addNewPassword\0on_pushButton_clicked\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addPassword[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       5,    0,   40,    2, 0x08 /* Private */,
       6,    1,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void addPassword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addPassword *_t = static_cast<addPassword *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_3_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_lineEdit_5_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->addNewPassword(); break;
        case 3: _t->on_pushButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject addPassword::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addPassword.data,
      qt_meta_data_addPassword,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *addPassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addPassword::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_addPassword.stringdata))
        return static_cast<void*>(const_cast< addPassword*>(this));
    return QDialog::qt_metacast(_clname);
}

int addPassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
