/****************************************************************************
** Meta object code from reading C++ file 'contactsengine.h'
**
** Created: Thu Sep 23 00:29:52 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../contactsengine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactsengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ContactsEngine[] = {

 // content:
       5,       // revision
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

static const char qt_meta_stringdata_ContactsEngine[] = {
    "ContactsEngine\0"
};

const QMetaObject ContactsEngine::staticMetaObject = {
    { &Plasma::DataEngine::staticMetaObject, qt_meta_stringdata_ContactsEngine,
      qt_meta_data_ContactsEngine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContactsEngine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContactsEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContactsEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContactsEngine))
        return static_cast<void*>(const_cast< ContactsEngine*>(this));
    typedef Plasma::DataEngine QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int ContactsEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef Plasma::DataEngine QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
