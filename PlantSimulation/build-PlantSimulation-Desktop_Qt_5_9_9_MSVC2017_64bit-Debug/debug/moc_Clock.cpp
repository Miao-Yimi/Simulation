/****************************************************************************
** Meta object code from reading C++ file 'Clock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PlantSimulation/Widgets/Clock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Clock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Clock_t {
    QByteArrayData data[17];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Clock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Clock_t qt_meta_stringdata_Clock = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Clock"
QT_MOC_LITERAL(1, 6, 14), // "sendTimerState"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 19), // "sendStartSimulation"
QT_MOC_LITERAL(4, 42, 17), // "sendEndSimulation"
QT_MOC_LITERAL(5, 60, 13), // "sendWorkStart"
QT_MOC_LITERAL(6, 74, 13), // "getTimerStart"
QT_MOC_LITERAL(7, 88, 11), // "getTimerEnd"
QT_MOC_LITERAL(8, 100, 10), // "getSpeedUp"
QT_MOC_LITERAL(9, 111, 12), // "getSpeedDown"
QT_MOC_LITERAL(10, 124, 14), // "getTimerRemake"
QT_MOC_LITERAL(11, 139, 17), // "changeCurrentTime"
QT_MOC_LITERAL(12, 157, 12), // "getStartTime"
QT_MOC_LITERAL(13, 170, 10), // "getEndTime"
QT_MOC_LITERAL(14, 181, 11), // "getWorkTime"
QT_MOC_LITERAL(15, 193, 12), // "QVector<int>"
QT_MOC_LITERAL(16, 206, 15) // "getDeleteWidget"

    },
    "Clock\0sendTimerState\0\0sendStartSimulation\0"
    "sendEndSimulation\0sendWorkStart\0"
    "getTimerStart\0getTimerEnd\0getSpeedUp\0"
    "getSpeedDown\0getTimerRemake\0"
    "changeCurrentTime\0getStartTime\0"
    "getEndTime\0getWorkTime\0QVector<int>\0"
    "getDeleteWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Clock[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,
       5,    2,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    1,  104,    2, 0x08 /* Private */,
      13,    1,  107,    2, 0x08 /* Private */,
      14,    2,  110,    2, 0x08 /* Private */,
      16,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Clock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Clock *_t = static_cast<Clock *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendTimerState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sendStartSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendEndSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendWorkStart((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->getTimerStart(); break;
        case 5: _t->getTimerEnd(); break;
        case 6: _t->getSpeedUp(); break;
        case 7: _t->getSpeedDown(); break;
        case 8: _t->getTimerRemake(); break;
        case 9: _t->changeCurrentTime(); break;
        case 10: _t->getStartTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->getEndTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->getWorkTime((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<int>(*)>(_a[2]))); break;
        case 13: _t->getDeleteWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Clock::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Clock::sendTimerState)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Clock::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Clock::sendStartSimulation)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Clock::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Clock::sendEndSimulation)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Clock::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Clock::sendWorkStart)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Clock::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Clock.data,
      qt_meta_data_Clock,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Clock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Clock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Clock.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Clock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Clock::sendTimerState(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Clock::sendStartSimulation(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Clock::sendEndSimulation(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Clock::sendWorkStart(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
