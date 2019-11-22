/****************************************************************************
** Meta object code from reading C++ file 'easycalculate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../calculate/easycalculate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'easycalculate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EasyCalculate_t {
    QByteArrayData data[13];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EasyCalculate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EasyCalculate_t qt_meta_stringdata_EasyCalculate = {
    {
QT_MOC_LITERAL(0, 0, 13), // "EasyCalculate"
QT_MOC_LITERAL(1, 14, 15), // "on_btn1_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "on_btn2_clicked"
QT_MOC_LITERAL(4, 47, 15), // "on_btn3_clicked"
QT_MOC_LITERAL(5, 63, 15), // "on_btn4_clicked"
QT_MOC_LITERAL(6, 79, 15), // "on_btn5_clicked"
QT_MOC_LITERAL(7, 95, 15), // "on_btn6_clicked"
QT_MOC_LITERAL(8, 111, 15), // "on_btn7_clicked"
QT_MOC_LITERAL(9, 127, 15), // "on_btn8_clicked"
QT_MOC_LITERAL(10, 143, 15), // "on_btn9_clicked"
QT_MOC_LITERAL(11, 159, 22), // "on_clearOneBtn_clicked"
QT_MOC_LITERAL(12, 182, 22) // "on_clearAllBtn_clicked"

    },
    "EasyCalculate\0on_btn1_clicked\0\0"
    "on_btn2_clicked\0on_btn3_clicked\0"
    "on_btn4_clicked\0on_btn5_clicked\0"
    "on_btn6_clicked\0on_btn7_clicked\0"
    "on_btn8_clicked\0on_btn9_clicked\0"
    "on_clearOneBtn_clicked\0on_clearAllBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EasyCalculate[] = {

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
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EasyCalculate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EasyCalculate *_t = static_cast<EasyCalculate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn1_clicked(); break;
        case 1: _t->on_btn2_clicked(); break;
        case 2: _t->on_btn3_clicked(); break;
        case 3: _t->on_btn4_clicked(); break;
        case 4: _t->on_btn5_clicked(); break;
        case 5: _t->on_btn6_clicked(); break;
        case 6: _t->on_btn7_clicked(); break;
        case 7: _t->on_btn8_clicked(); break;
        case 8: _t->on_btn9_clicked(); break;
        case 9: _t->on_clearOneBtn_clicked(); break;
        case 10: _t->on_clearAllBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EasyCalculate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EasyCalculate.data,
      qt_meta_data_EasyCalculate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EasyCalculate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EasyCalculate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EasyCalculate.stringdata0))
        return static_cast<void*>(const_cast< EasyCalculate*>(this));
    return QWidget::qt_metacast(_clname);
}

int EasyCalculate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
