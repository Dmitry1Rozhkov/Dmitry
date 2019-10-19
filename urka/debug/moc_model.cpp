/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_iii__TModel_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iii__TModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iii__TModel_t qt_meta_stringdata_iii__TModel = {
    {
QT_MOC_LITERAL(0, 0, 11) // "iii::TModel"

    },
    "iii::TModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iii__TModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void iii::TModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject iii::TModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_iii__TModel.data,
    qt_meta_data_iii__TModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *iii::TModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iii::TModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iii__TModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int iii::TModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_iii__TComposite_t {
    QByteArrayData data[7];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iii__TComposite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iii__TComposite_t qt_meta_stringdata_iii__TComposite = {
    {
QT_MOC_LITERAL(0, 0, 15), // "iii::TComposite"
QT_MOC_LITERAL(1, 16, 6), // "getPsi"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "TVector"
QT_MOC_LITERAL(4, 32, 6), // "rvalue"
QT_MOC_LITERAL(5, 39, 4), // "BOOM"
QT_MOC_LITERAL(6, 44, 6) // "setPsi"

    },
    "iii::TComposite\0getPsi\0\0TVector\0rvalue\0"
    "BOOM\0setPsi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iii__TComposite[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void iii::TComposite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TComposite *_t = static_cast<TComposite *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getPsi((*reinterpret_cast< TVector(*)>(_a[1]))); break;
        case 1: _t->BOOM(); break;
        case 2: _t->setPsi((*reinterpret_cast< TVector(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TComposite::*)(TVector );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TComposite::getPsi)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TComposite::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TComposite::BOOM)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject iii::TComposite::staticMetaObject = { {
    &TModel::staticMetaObject,
    qt_meta_stringdata_iii__TComposite.data,
    qt_meta_data_iii__TComposite,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *iii::TComposite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iii::TComposite::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iii__TComposite.stringdata0))
        return static_cast<void*>(this);
    return TModel::qt_metacast(_clname);
}

int iii::TComposite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void iii::TComposite::getPsi(TVector _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void iii::TComposite::BOOM()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_iii__TAircraft1_t {
    QByteArrayData data[5];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iii__TAircraft1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iii__TAircraft1_t qt_meta_stringdata_iii__TAircraft1 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "iii::TAircraft1"
QT_MOC_LITERAL(1, 16, 6), // "setPsi"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "TVector"
QT_MOC_LITERAL(4, 32, 6) // "rvalue"

    },
    "iii::TAircraft1\0setPsi\0\0TVector\0rvalue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iii__TAircraft1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void iii::TAircraft1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TAircraft1 *_t = static_cast<TAircraft1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPsi((*reinterpret_cast< TVector(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject iii::TAircraft1::staticMetaObject = { {
    &TAircraft::staticMetaObject,
    qt_meta_stringdata_iii__TAircraft1.data,
    qt_meta_data_iii__TAircraft1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *iii::TAircraft1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iii::TAircraft1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iii__TAircraft1.stringdata0))
        return static_cast<void*>(this);
    return TAircraft::qt_metacast(_clname);
}

int iii::TAircraft1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TAircraft::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_iii__TAircraft2_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iii__TAircraft2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iii__TAircraft2_t qt_meta_stringdata_iii__TAircraft2 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "iii::TAircraft2"
QT_MOC_LITERAL(1, 16, 5), // "Crash"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "iii::TAircraft2\0Crash\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iii__TAircraft2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void iii::TAircraft2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TAircraft2 *_t = static_cast<TAircraft2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Crash(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject iii::TAircraft2::staticMetaObject = { {
    &TAircraft::staticMetaObject,
    qt_meta_stringdata_iii__TAircraft2.data,
    qt_meta_data_iii__TAircraft2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *iii::TAircraft2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iii::TAircraft2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iii__TAircraft2.stringdata0))
        return static_cast<void*>(this);
    return TAircraft::qt_metacast(_clname);
}

int iii::TAircraft2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TAircraft::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_iii__TMissle_t {
    QByteArrayData data[5];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iii__TMissle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iii__TMissle_t qt_meta_stringdata_iii__TMissle = {
    {
QT_MOC_LITERAL(0, 0, 12), // "iii::TMissle"
QT_MOC_LITERAL(1, 13, 6), // "setPsi"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "TVector"
QT_MOC_LITERAL(4, 29, 6) // "rvalue"

    },
    "iii::TMissle\0setPsi\0\0TVector\0rvalue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iii__TMissle[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void iii::TMissle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TMissle *_t = static_cast<TMissle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPsi((*reinterpret_cast< TVector(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject iii::TMissle::staticMetaObject = { {
    &TDynamicObject::staticMetaObject,
    qt_meta_stringdata_iii__TMissle.data,
    qt_meta_data_iii__TMissle,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *iii::TMissle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iii::TMissle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iii__TMissle.stringdata0))
        return static_cast<void*>(this);
    return TDynamicObject::qt_metacast(_clname);
}

int iii::TMissle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TDynamicObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
