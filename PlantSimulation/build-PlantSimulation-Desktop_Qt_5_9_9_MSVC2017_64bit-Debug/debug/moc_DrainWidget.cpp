/****************************************************************************
** Meta object code from reading C++ file 'DrainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PlantSimulation/Widgets/DrainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DrainWidget_t {
    QByteArrayData data[27];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrainWidget_t qt_meta_stringdata_DrainWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DrainWidget"
QT_MOC_LITERAL(1, 12, 14), // "sendWindowShow"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "sendWindowHide"
QT_MOC_LITERAL(4, 43, 9), // "sendFocus"
QT_MOC_LITERAL(5, 53, 13), // "sendLinkPoint"
QT_MOC_LITERAL(6, 67, 17), // "sendMoveLinkPoint"
QT_MOC_LITERAL(7, 85, 19), // "sendStartSimulation"
QT_MOC_LITERAL(8, 105, 17), // "sendEndSimulation"
QT_MOC_LITERAL(9, 123, 13), // "sendWorkState"
QT_MOC_LITERAL(10, 137, 16), // "sendDeleteWidget"
QT_MOC_LITERAL(11, 154, 7), // "getName"
QT_MOC_LITERAL(12, 162, 9), // "getUpdate"
QT_MOC_LITERAL(13, 172, 13), // "getWindowShow"
QT_MOC_LITERAL(14, 186, 13), // "getWindowHide"
QT_MOC_LITERAL(15, 200, 14), // "getChangeFocus"
QT_MOC_LITERAL(16, 215, 8), // "getRaise"
QT_MOC_LITERAL(17, 224, 14), // "getDrainNumber"
QT_MOC_LITERAL(18, 239, 18), // "getStartSimulation"
QT_MOC_LITERAL(19, 258, 16), // "getEndSimulation"
QT_MOC_LITERAL(20, 275, 12), // "getDrainWork"
QT_MOC_LITERAL(21, 288, 15), // "changeWorkState"
QT_MOC_LITERAL(22, 304, 15), // "getTimeInterval"
QT_MOC_LITERAL(23, 320, 8), // "getCargo"
QT_MOC_LITERAL(24, 329, 10), // "getSpeedUp"
QT_MOC_LITERAL(25, 340, 12), // "getSpeedDown"
QT_MOC_LITERAL(26, 353, 14) // "getTimerRemake"

    },
    "DrainWidget\0sendWindowShow\0\0sendWindowHide\0"
    "sendFocus\0sendLinkPoint\0sendMoveLinkPoint\0"
    "sendStartSimulation\0sendEndSimulation\0"
    "sendWorkState\0sendDeleteWidget\0getName\0"
    "getUpdate\0getWindowShow\0getWindowHide\0"
    "getChangeFocus\0getRaise\0getDrainNumber\0"
    "getStartSimulation\0getEndSimulation\0"
    "getDrainWork\0changeWorkState\0"
    "getTimeInterval\0getCargo\0getSpeedUp\0"
    "getSpeedDown\0getTimerRemake"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrainWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  139,    2, 0x06 /* Public */,
       3,    0,  140,    2, 0x06 /* Public */,
       4,    2,  141,    2, 0x06 /* Public */,
       5,    4,  146,    2, 0x06 /* Public */,
       6,    4,  155,    2, 0x06 /* Public */,
       7,    1,  164,    2, 0x06 /* Public */,
       8,    1,  167,    2, 0x06 /* Public */,
       9,    2,  170,    2, 0x06 /* Public */,
      10,    1,  175,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,  178,    2, 0x08 /* Private */,
      12,    0,  183,    2, 0x08 /* Private */,
      13,    0,  184,    2, 0x08 /* Private */,
      14,    0,  185,    2, 0x08 /* Private */,
      15,    1,  186,    2, 0x08 /* Private */,
      16,    0,  189,    2, 0x08 /* Private */,
      17,    1,  190,    2, 0x08 /* Private */,
      18,    1,  193,    2, 0x08 /* Private */,
      19,    1,  196,    2, 0x08 /* Private */,
      20,    2,  199,    2, 0x08 /* Private */,
      21,    0,  204,    2, 0x08 /* Private */,
      22,    1,  205,    2, 0x08 /* Private */,
      23,    1,  208,    2, 0x08 /* Private */,
      24,    0,  211,    2, 0x08 /* Private */,
      25,    0,  212,    2, 0x08 /* Private */,
      26,    0,  213,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Int, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Int, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DrainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DrainWidget *_t = static_cast<DrainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendWindowShow(); break;
        case 1: _t->sendWindowHide(); break;
        case 2: _t->sendFocus((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->sendLinkPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 4: _t->sendMoveLinkPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 5: _t->sendStartSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sendEndSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendWorkState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->sendDeleteWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->getName((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->getUpdate(); break;
        case 11: _t->getWindowShow(); break;
        case 12: _t->getWindowHide(); break;
        case 13: _t->getChangeFocus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->getRaise(); break;
        case 15: _t->getDrainNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->getStartSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->getEndSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->getDrainWork((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 19: _t->changeWorkState(); break;
        case 20: _t->getTimeInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->getCargo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->getSpeedUp(); break;
        case 23: _t->getSpeedDown(); break;
        case 24: _t->getTimerRemake(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DrainWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrainWidget::sendWindowShow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DrainWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrainWidget::sendWindowHide)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DrainWidget::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrainWidget::sendFocus)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DrainWidget::*_t)(QPointF , QString , int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrainWidget::sendLinkPoint)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DrainWidget::*_t)(QPointF , QString , int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrainWidget::sendMoveLinkPoint)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DrainWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrainWidget::sendStartSimulation)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (DrainWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrainWidget::sendEndSimulation)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (DrainWidget::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrainWidget::sendWorkState)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (DrainWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DrainWidget::sendDeleteWidget)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject DrainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrainWidget.data,
      qt_meta_data_DrainWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DrainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrainWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DrainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void DrainWidget::sendWindowShow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DrainWidget::sendWindowHide()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DrainWidget::sendFocus(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DrainWidget::sendLinkPoint(QPointF _t1, QString _t2, int _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DrainWidget::sendMoveLinkPoint(QPointF _t1, QString _t2, int _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DrainWidget::sendStartSimulation(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DrainWidget::sendEndSimulation(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DrainWidget::sendWorkState(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DrainWidget::sendDeleteWidget(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
