/****************************************************************************
** Meta object code from reading C++ file 'viewpassword.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "viewpassword.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewpassword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_viewPassword_t {
    QByteArrayData data[14];
    char stringdata[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_viewPassword_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_viewPassword_t qt_meta_stringdata_viewPassword = {
    {
QT_MOC_LITERAL(0, 0, 12), // "viewPassword"
QT_MOC_LITERAL(1, 13, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "checked"
QT_MOC_LITERAL(4, 42, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 64, 12), // "editPassword"
QT_MOC_LITERAL(6, 77, 4), // "Name"
QT_MOC_LITERAL(7, 82, 11), // "newPassword"
QT_MOC_LITERAL(8, 94, 19), // "getPasswordStrength"
QT_MOC_LITERAL(9, 114, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(10, 138, 23), // "on_pushButton_3_pressed"
QT_MOC_LITERAL(11, 162, 24), // "on_lineEdit_5_textEdited"
QT_MOC_LITERAL(12, 187, 4), // "arg1"
QT_MOC_LITERAL(13, 192, 21) // "on_checkBox_2_clicked"

    },
    "viewPassword\0on_checkBox_toggled\0\0"
    "checked\0on_pushButton_clicked\0"
    "editPassword\0Name\0newPassword\0"
    "getPasswordStrength\0on_pushButton_2_clicked\0"
    "on_pushButton_3_pressed\0"
    "on_lineEdit_5_textEdited\0arg1\0"
    "on_checkBox_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_viewPassword[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    2,   58,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,
      11,    1,   66,    2, 0x08 /* Private */,
      13,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void viewPassword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        viewPassword *_t = static_cast<viewPassword *>(_o);
        switch (_id) {
        case 0: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->editPassword((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->getPasswordStrength(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_pushButton_3_pressed(); break;
        case 6: _t->on_lineEdit_5_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_checkBox_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject viewPassword::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_viewPassword.data,
      qt_meta_data_viewPassword,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *viewPassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *viewPassword::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_viewPassword.stringdata))
        return static_cast<void*>(const_cast< viewPassword*>(this));
    return QDialog::qt_metacast(_clname);
}

int viewPassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
