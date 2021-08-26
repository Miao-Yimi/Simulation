/****************************************************************************
** Meta object code from reading C++ file 'TransWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PlantSimulation/Widgets/TransWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TransWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TransWidget_t {
    QByteArrayData data[16];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TransWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TransWidget_t qt_meta_stringdata_TransWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TransWidget"
QT_MOC_LITERAL(1, 12, 14), // "sendWindowShow"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "sendWindowHide"
QT_MOC_LITERAL(4, 43, 9), // "sendFocus"
QT_MOC_LITERAL(5, 53, 13), // "sendLinkPoint"
QT_MOC_LITERAL(6, 67, 17), // "sendMoveLinkPoint"
QT_MOC_LITERAL(7, 85, 16), // "sendDeleteWidget"
QT_MOC_LITERAL(8, 102, 21), // "sendChangeCableLength"
QT_MOC_LITERAL(9, 124, 10), // "sendUpdate"
QT_MOC_LITERAL(10, 135, 7), // "getName"
QT_MOC_LITERAL(11, 143, 9), // "getUpdate"
QT_MOC_LITERAL(12, 153, 9), // "getLength"
QT_MOC_LITERAL(13, 163, 14), // "getTransNumber"
QT_MOC_LITERAL(14, 178, 8), // "getRaise"
QT_MOC_LITERAL(15, 187, 14) // "getChangeFocus"

    },
    "TransWidget\0sendWindowShow\0\0sendWindowHide\0"
    "sendFocus\0sendLinkPoint\0sendMoveLinkPoint\0"
    "sendDeleteWidget\0sendChangeCableLength\0"
    "sendUpdate\0getName\0getUpdate\0getLength\0"
    "getTransNumber\0getRaise\0getChangeFocus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    2,   86,    2, 0x06 /* Public */,
       5,    4,   91,    2, 0x06 /* Public */,
       6,    4,  100,    2, 0x06 /* Public */,
       7,    1,  109,    2, 0x06 /* Public */,
       8,    3,  112,    2, 0x06 /* Public */,
       9,    0,  119,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,  120,    2, 0x08 /* Private */,
      11,    0,  125,    2, 0x08 /* Private */,
      12,    1,  126,    2, 0x08 /* Private */,
      13,    1,  129,    2, 0x08 /* Private */,
      14,    0,  132,    2, 0x08 /* Private */,
      15,    1,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Int, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Int, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString, QMetaType::Double,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void TransWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TransWidget *_t = static_cast<TransWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendWindowShow(); break;
        case 1: _t->sendWindowHide(); break;
        case 2: _t->sendFocus((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->sendLinkPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 4: _t->sendMoveLinkPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 5: _t->sendDeleteWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sendChangeCableLength((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 7: _t->sendUpdate(); break;
        case 8: _t->getName((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->getUpdate(); break;
        case 10: _t->getLength((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->getTransNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->getRaise(); break;
        case 13: _t->getChangeFocus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TransWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransWidget::sendWindowShow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TransWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransWidget::sendWindowHide)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TransWidget::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransWidget::sendFocus)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TransWidget::*_t)(QPointF , QString , int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransWidget::sendLinkPoint)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TransWidget::*_t)(QPointF , QString , int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransWidget::sendMoveLinkPoint)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (TransWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransWidget::sendDeleteWidget)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (TransWidget::*_t)(QPointF , QString , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransWidget::sendChangeCableLength)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (TransWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TransWidget::sendUpdate)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject TransWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TransWidget.data,
      qt_meta_data_TransWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TransWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TransWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TransWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void TransWidget::sendWindowShow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TransWidget::sendWindowHide()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TransWidget::sendFocus(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TransWidget::sendLinkPoint(QPointF _t1, QString _t2, int _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TransWidget::sendMoveLinkPoint(QPointF _t1, QString _t2, int _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TransWidget::sendDeleteWidget(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TransWidget::sendChangeCableLength(QPointF _t1, QString _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TransWidget::sendUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
