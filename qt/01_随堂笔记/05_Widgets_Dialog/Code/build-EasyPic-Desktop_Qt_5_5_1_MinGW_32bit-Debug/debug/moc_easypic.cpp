/****************************************************************************
** Meta object code from reading C++ file 'easypic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EasyPic/easypic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'easypic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EasyPic_t {
    QByteArrayData data[7];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EasyPic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EasyPic_t qt_meta_stringdata_EasyPic = {
    {
QT_MOC_LITERAL(0, 0, 7), // "EasyPic"
QT_MOC_LITERAL(1, 8, 23), // "on_localFileBtn_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "on_preBtn_clicked"
QT_MOC_LITERAL(4, 51, 18), // "on_nextBtn_clicked"
QT_MOC_LITERAL(5, 70, 17), // "on_addBtn_clicked"
QT_MOC_LITERAL(6, 88, 20) // "on_deleteBtn_clicked"

    },
    "EasyPic\0on_localFileBtn_clicked\0\0"
    "on_preBtn_clicked\0on_nextBtn_clicked\0"
    "on_addBtn_clicked\0on_deleteBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EasyPic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EasyPic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EasyPic *_t = static_cast<EasyPic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_localFileBtn_clicked(); break;
        case 1: _t->on_preBtn_clicked(); break;
        case 2: _t->on_nextBtn_clicked(); break;
        case 3: _t->on_addBtn_clicked(); break;
        case 4: _t->on_deleteBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EasyPic::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EasyPic.data,
      qt_meta_data_EasyPic,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EasyPic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EasyPic::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EasyPic.stringdata0))
        return static_cast<void*>(const_cast< EasyPic*>(this));
    return QWidget::qt_metacast(_clname);
}

int EasyPic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
