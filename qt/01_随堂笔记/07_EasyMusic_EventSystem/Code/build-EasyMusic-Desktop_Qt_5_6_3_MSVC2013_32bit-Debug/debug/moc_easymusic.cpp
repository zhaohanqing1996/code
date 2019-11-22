/****************************************************************************
** Meta object code from reading C++ file 'easymusic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EasyMusic/easymusic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'easymusic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EasyMusic_t {
    QByteArrayData data[18];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EasyMusic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EasyMusic_t qt_meta_stringdata_EasyMusic = {
    {
QT_MOC_LITERAL(0, 0, 9), // "EasyMusic"
QT_MOC_LITERAL(1, 10, 11), // "addSongSlot"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "updateShowList"
QT_MOC_LITERAL(4, 38, 19), // "updateShowListState"
QT_MOC_LITERAL(5, 58, 20), // "updateMediaPlayState"
QT_MOC_LITERAL(6, 79, 18), // "updatePlayBackMode"
QT_MOC_LITERAL(7, 98, 1), // "n"
QT_MOC_LITERAL(8, 100, 17), // "updateShowListRow"
QT_MOC_LITERAL(9, 118, 21), // "updateRateSliderRange"
QT_MOC_LITERAL(10, 140, 3), // "dur"
QT_MOC_LITERAL(11, 144, 21), // "updateRateSliderValue"
QT_MOC_LITERAL(12, 166, 3), // "pos"
QT_MOC_LITERAL(13, 170, 17), // "updatePlayPostion"
QT_MOC_LITERAL(14, 188, 22), // "disconnectSliderPlayer"
QT_MOC_LITERAL(15, 211, 17), // "updateCurrentTime"
QT_MOC_LITERAL(16, 229, 13), // "updatePlayTip"
QT_MOC_LITERAL(17, 243, 9) // "playMusic"

    },
    "EasyMusic\0addSongSlot\0\0updateShowList\0"
    "updateShowListState\0updateMediaPlayState\0"
    "updatePlayBackMode\0n\0updateShowListRow\0"
    "updateRateSliderRange\0dur\0"
    "updateRateSliderValue\0pos\0updatePlayPostion\0"
    "disconnectSliderPlayer\0updateCurrentTime\0"
    "updatePlayTip\0playMusic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EasyMusic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    1,   83,    2, 0x0a /* Public */,
       8,    1,   86,    2, 0x0a /* Public */,
       9,    1,   89,    2, 0x0a /* Public */,
      11,    1,   92,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    1,   97,    2, 0x0a /* Public */,
      16,    0,  100,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EasyMusic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EasyMusic *_t = static_cast<EasyMusic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addSongSlot(); break;
        case 1: _t->updateShowList(); break;
        case 2: _t->updateShowListState(); break;
        case 3: _t->updateMediaPlayState(); break;
        case 4: _t->updatePlayBackMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateShowListRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateRateSliderRange((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->updateRateSliderValue((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->updatePlayPostion(); break;
        case 9: _t->disconnectSliderPlayer(); break;
        case 10: _t->updateCurrentTime((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 11: _t->updatePlayTip(); break;
        case 12: _t->playMusic(); break;
        default: ;
        }
    }
}

const QMetaObject EasyMusic::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EasyMusic.data,
      qt_meta_data_EasyMusic,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EasyMusic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EasyMusic::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EasyMusic.stringdata0))
        return static_cast<void*>(const_cast< EasyMusic*>(this));
    return QWidget::qt_metacast(_clname);
}

int EasyMusic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
