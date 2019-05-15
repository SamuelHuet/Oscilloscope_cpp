/****************************************************************************
** Meta object code from reading C++ file 'grille.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Affichage/grille.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grille.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Grille_t {
    QByteArrayData data[11];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Grille_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Grille_t qt_meta_stringdata_Grille = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Grille"
QT_MOC_LITERAL(1, 7, 12), // "ChangeZoom_Y"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "zoom_y"
QT_MOC_LITERAL(4, 28, 12), // "ChangeZoom_X"
QT_MOC_LITERAL(5, 41, 6), // "zoom_x"
QT_MOC_LITERAL(6, 48, 8), // "Scroll_X"
QT_MOC_LITERAL(7, 57, 8), // "scroll_x"
QT_MOC_LITERAL(8, 66, 13), // "ChangeTrigger"
QT_MOC_LITERAL(9, 80, 1), // "y"
QT_MOC_LITERAL(10, 82, 16) // "CheckBox_trigger"

    },
    "Grille\0ChangeZoom_Y\0\0zoom_y\0ChangeZoom_X\0"
    "zoom_x\0Scroll_X\0scroll_x\0ChangeTrigger\0"
    "y\0CheckBox_trigger"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Grille[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       8,    1,   48,    2, 0x0a /* Public */,
      10,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void Grille::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Grille *_t = static_cast<Grille *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChangeZoom_Y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ChangeZoom_X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->Scroll_X((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ChangeTrigger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->CheckBox_trigger((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Grille::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Grille.data,
    qt_meta_data_Grille,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Grille::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Grille::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Grille.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Grille::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
