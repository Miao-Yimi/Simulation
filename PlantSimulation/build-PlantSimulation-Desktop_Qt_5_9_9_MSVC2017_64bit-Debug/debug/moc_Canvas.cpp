/****************************************************************************
** Meta object code from reading C++ file 'Canvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PlantSimulation/Widgets/Canvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Canvas_t {
    QByteArrayData data[33];
    char stringdata0[481];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Canvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Canvas_t qt_meta_stringdata_Canvas = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Canvas"
QT_MOC_LITERAL(1, 7, 15), // "sendCancleFocus"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "sendMousePoint"
QT_MOC_LITERAL(4, 39, 10), // "sendPoint1"
QT_MOC_LITERAL(5, 50, 10), // "sendPoint2"
QT_MOC_LITERAL(6, 61, 10), // "sendUpdate"
QT_MOC_LITERAL(7, 72, 9), // "sendRaise"
QT_MOC_LITERAL(8, 82, 17), // "sendMoveLinkPoint"
QT_MOC_LITERAL(9, 100, 10), // "sendNumber"
QT_MOC_LITERAL(10, 111, 14), // "sendSubsequent"
QT_MOC_LITERAL(11, 126, 22), // "sendSubStartSimulation"
QT_MOC_LITERAL(12, 149, 20), // "sendSubEndSimulation"
QT_MOC_LITERAL(13, 170, 9), // "sendCargo"
QT_MOC_LITERAL(14, 180, 13), // "sendWorkState"
QT_MOC_LITERAL(15, 194, 12), // "sendWantWork"
QT_MOC_LITERAL(16, 207, 16), // "sendDeleteWidget"
QT_MOC_LITERAL(17, 224, 21), // "sendChangeCableLength"
QT_MOC_LITERAL(18, 246, 16), // "getCreateStation"
QT_MOC_LITERAL(19, 263, 15), // "getCreateSource"
QT_MOC_LITERAL(20, 279, 14), // "getCreateDrain"
QT_MOC_LITERAL(21, 294, 14), // "getCreateTrans"
QT_MOC_LITERAL(22, 309, 19), // "getWidgetPressState"
QT_MOC_LITERAL(23, 329, 11), // "getTwoPoint"
QT_MOC_LITERAL(24, 341, 14), // "getCreateCable"
QT_MOC_LITERAL(25, 356, 12), // "getLinkPoint"
QT_MOC_LITERAL(26, 369, 16), // "getMoveLinkPoint"
QT_MOC_LITERAL(27, 386, 18), // "getStartSimulation"
QT_MOC_LITERAL(28, 405, 16), // "getEndSimulation"
QT_MOC_LITERAL(29, 422, 12), // "getWorkState"
QT_MOC_LITERAL(30, 435, 8), // "getCargo"
QT_MOC_LITERAL(31, 444, 15), // "getDeleteWidget"
QT_MOC_LITERAL(32, 460, 20) // "getChangeCableLength"

    },
    "Canvas\0sendCancleFocus\0\0sendMousePoint\0"
    "sendPoint1\0sendPoint2\0sendUpdate\0"
    "sendRaise\0sendMoveLinkPoint\0sendNumber\0"
    "sendSubsequent\0sendSubStartSimulation\0"
    "sendSubEndSimulation\0sendCargo\0"
    "sendWorkState\0sendWantWork\0sendDeleteWidget\0"
    "sendChangeCableLength\0getCreateStation\0"
    "getCreateSource\0getCreateDrain\0"
    "getCreateTrans\0getWidgetPressState\0"
    "getTwoPoint\0getCreateCable\0getLinkPoint\0"
    "getMoveLinkPoint\0getStartSimulation\0"
    "getEndSimulation\0getWorkState\0getCargo\0"
    "getDeleteWidget\0getChangeCableLength"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canvas[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  169,    2, 0x06 /* Public */,
       3,    2,  172,    2, 0x06 /* Public */,
       4,    2,  177,    2, 0x06 /* Public */,
       5,    2,  182,    2, 0x06 /* Public */,
       6,    0,  187,    2, 0x06 /* Public */,
       7,    0,  188,    2, 0x06 /* Public */,
       8,    4,  189,    2, 0x06 /* Public */,
       9,    1,  198,    2, 0x06 /* Public */,
      10,    2,  201,    2, 0x06 /* Public */,
      11,    1,  206,    2, 0x06 /* Public */,
      12,    1,  209,    2, 0x06 /* Public */,
      13,    1,  212,    2, 0x06 /* Public */,
      14,    2,  215,    2, 0x06 /* Public */,
      15,    1,  220,    2, 0x06 /* Public */,
      16,    1,  223,    2, 0x06 /* Public */,
      17,    3,  226,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  233,    2, 0x08 /* Private */,
      19,    0,  234,    2, 0x08 /* Private */,
      20,    0,  235,    2, 0x08 /* Private */,
      21,    0,  236,    2, 0x08 /* Private */,
      22,    2,  237,    2, 0x08 /* Private */,
      23,    0,  242,    2, 0x08 /* Private */,
      24,    0,  243,    2, 0x08 /* Private */,
      25,    4,  244,    2, 0x08 /* Private */,
      26,    4,  253,    2, 0x08 /* Private */,
      27,    1,  262,    2, 0x08 /* Private */,
      28,    1,  265,    2, 0x08 /* Private */,
      29,    2,  268,    2, 0x08 /* Private */,
      30,    1,  273,    2, 0x08 /* Private */,
      31,    1,  276,    2, 0x08 /* Private */,
      32,    3,  279,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Int, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Double,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Int, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Int, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Double,    2,    2,    2,

       0        // eod
};

void Canvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Canvas *_t = static_cast<Canvas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCancleFocus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendMousePoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sendPoint1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sendPoint2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->sendUpdate(); break;
        case 5: _t->sendRaise(); break;
        case 6: _t->sendMoveLinkPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 7: _t->sendNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sendSubsequent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->sendSubStartSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->sendSubEndSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->sendCargo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->sendWorkState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->sendWantWork((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->sendDeleteWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->sendChangeCableLength((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 16: _t->getCreateStation(); break;
        case 17: _t->getCreateSource(); break;
        case 18: _t->getCreateDrain(); break;
        case 19: _t->getCreateTrans(); break;
        case 20: _t->getWidgetPressState((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 21: _t->getTwoPoint(); break;
        case 22: _t->getCreateCable(); break;
        case 23: _t->getLinkPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 24: _t->getMoveLinkPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 25: _t->getStartSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->getEndSimulation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->getWorkState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 28: _t->getCargo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->getDeleteWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->getChangeCableLength((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Canvas::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendCancleFocus)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendMousePoint)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendPoint1)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendPoint2)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendUpdate)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendRaise)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(QPointF , QString , int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendMoveLinkPoint)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendNumber)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendSubsequent)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendSubStartSimulation)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendSubEndSimulation)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendCargo)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendWorkState)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendWantWork)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendDeleteWidget)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (Canvas::*_t)(QPointF , QString , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canvas::sendChangeCableLength)) {
                *result = 15;
                return;
            }
        }
    }
}

const QMetaObject Canvas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Canvas.data,
      qt_meta_data_Canvas,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Canvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Canvas.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Canvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void Canvas::sendCancleFocus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Canvas::sendMousePoint(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Canvas::sendPoint1(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Canvas::sendPoint2(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Canvas::sendUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Canvas::sendRaise()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Canvas::sendMoveLinkPoint(QPointF _t1, QString _t2, int _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Canvas::sendNumber(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Canvas::sendSubsequent(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Canvas::sendSubStartSimulation(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Canvas::sendSubEndSimulation(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Canvas::sendCargo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Canvas::sendWorkState(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Canvas::sendWantWork(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Canvas::sendDeleteWidget(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Canvas::sendChangeCableLength(QPointF _t1, QString _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
