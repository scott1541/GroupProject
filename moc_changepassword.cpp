/****************************************************************************
** Meta object code from reading C++ file 'changepassword.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "changepassword.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changepassword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChangePassword_t {
    QByteArrayData data[9];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChangePassword_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChangePassword_t qt_meta_stringdata_ChangePassword = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ChangePassword"
QT_MOC_LITERAL(1, 15, 22), // "on_lineEdit_textEdited"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "arg1"
QT_MOC_LITERAL(4, 44, 24), // "on_lineEdit_2_textEdited"
QT_MOC_LITERAL(5, 69, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 91, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 115, 24), // "on_lineEdit_3_textEdited"
QT_MOC_LITERAL(8, 140, 19) // "getPasswordStrength"

    },
    "ChangePassword\0on_lineEdit_textEdited\0"
    "\0arg1\0on_lineEdit_2_textEdited\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_lineEdit_3_textEdited\0getPasswordStrength"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChangePassword[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    0,   50,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    1,   52,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void ChangePassword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChangePassword *_t = static_cast<ChangePassword *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_lineEdit_2_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_lineEdit_3_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->getPasswordStrength(); break;
        default: ;
        }
    }
}

const QMetaObject ChangePassword::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChangePassword.data,
      qt_meta_data_ChangePassword,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChangePassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChangePassword::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChangePassword.stringdata))
        return static_cast<void*>(const_cast< ChangePassword*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChangePassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
