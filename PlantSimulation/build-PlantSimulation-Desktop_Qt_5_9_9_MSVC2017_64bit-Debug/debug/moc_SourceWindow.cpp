/****************************************************************************
** Meta object code from reading C++ file 'SourceWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PlantSimulation/WidgetWindows/SourceWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SourceWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SourceWindow_t {
    QByteArrayData data[8];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SourceWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SourceWindow_t qt_meta_stringdata_SourceWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SourceWindow"
QT_MOC_LITERAL(1, 13, 12), // "sendWorkTime"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "QVector<int>"
QT_MOC_LITERAL(4, 40, 15), // "getTimeInterval"
QT_MOC_LITERAL(5, 56, 12), // "getStartTime"
QT_MOC_LITERAL(6, 69, 10), // "getEndTime"
QT_MOC_LITERAL(7, 80, 11) // "getWorkTime"

    },
    "SourceWindow\0sendWorkTime\0\0QVector<int>\0"
    "getTimeInterval\0getStartTime\0getEndTime\0"
    "getWorkTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SourceWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   44,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       6,    1,   50,    2, 0x08 /* Private */,
       7,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void SourceWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SourceWindow *_t = static_cast<SourceWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendWorkTime((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<int>(*)>(_a[2]))); break;
        case 1: _t->getTimeInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->getStartTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->getEndTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->getWorkTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
            typedef void (SourceWindow::*_t)(QString , QVector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SourceWindow::sendWorkTime)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SourceWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SourceWindow.data,
      qt_meta_data_SourceWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SourceWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SourceWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SourceWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SourceWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SourceWindow::sendWorkTime(QString _t1, QVector<int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE