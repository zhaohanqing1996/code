/****************************************************************************
** Meta object code from reading C++ file 'easynote.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EasyNote/easynote.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'easynote.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EasyNote_t {
    QByteArrayData data[7];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EasyNote_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EasyNote_t qt_meta_stringdata_EasyNote = {
    {
QT_MOC_LITERAL(0, 0, 8), // "EasyNote"
QT_MOC_LITERAL(1, 9, 11), // "newFileSlot"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "openFileSlot"
QT_MOC_LITERAL(4, 35, 14), // "saveFileAsSlot"
QT_MOC_LITERAL(5, 50, 12), // "saveFileSlot"
QT_MOC_LITERAL(6, 63, 17) // "updateChangeState"

    },
    "EasyNote\0newFileSlot\0\0openFileSlot\0"
    "saveFileAsSlot\0saveFileSlot\0"
    "updateChangeState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EasyNote[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EasyNote::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EasyNote *_t = static_cast<EasyNote *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newFileSlot(); break;
        case 1: _t->openFileSlot(); break;
        case 2: _t->saveFileAsSlot(); break;
        case 3: _t->saveFileSlot(); break;
        case 4: _t->updateChangeState(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EasyNote::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EasyNote.data,
      qt_meta_data_EasyNote,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EasyNote::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EasyNote::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EasyNote.stringdata0))
        return static_cast<void*>(const_cast< EasyNote*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int EasyNote::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
