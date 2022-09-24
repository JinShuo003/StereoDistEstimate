/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[514];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "Signal_ImgDirIsReady"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "Signal_StopAutoMode"
QT_MOC_LITERAL(4, 53, 23), // "Slot_OpenImgBtn_clicked"
QT_MOC_LITERAL(5, 77, 27), // "Slot_StereoCalibBtn_clicked"
QT_MOC_LITERAL(6, 105, 31), // "Slot_ExtractFeaturesBtn_clicked"
QT_MOC_LITERAL(7, 137, 24), // "Slot_CalDepthBtn_clicked"
QT_MOC_LITERAL(8, 162, 24), // "Slot_SaveDataBtn_clicked"
QT_MOC_LITERAL(9, 187, 29), // "Slot_LoadDisparityBtn_clicked"
QT_MOC_LITERAL(10, 217, 24), // "Slot_CalErrorBtn_clicked"
QT_MOC_LITERAL(11, 242, 26), // "Slot_ModifyParaBtn_clicked"
QT_MOC_LITERAL(12, 269, 23), // "Slot_OpenDirBtn_clicked"
QT_MOC_LITERAL(13, 293, 25), // "Slot_AutoStartBtn_clicked"
QT_MOC_LITERAL(14, 319, 19), // "Slot_ProcessNextImg"
QT_MOC_LITERAL(15, 339, 21), // "Slot_PauseBtn_clicked"
QT_MOC_LITERAL(16, 361, 20), // "Slot_NextImg_clicked"
QT_MOC_LITERAL(17, 382, 18), // "Slot_Reset_clicked"
QT_MOC_LITERAL(18, 401, 18), // "Slot_ImgDirIsReady"
QT_MOC_LITERAL(19, 420, 17), // "Slot_StopAutoMode"
QT_MOC_LITERAL(20, 438, 17), // "Slot_ParaAccepted"
QT_MOC_LITERAL(21, 456, 7), // "success"
QT_MOC_LITERAL(22, 464, 15), // "m_showImageArea"
QT_MOC_LITERAL(23, 480, 4), // "left"
QT_MOC_LITERAL(24, 485, 5), // "right"
QT_MOC_LITERAL(25, 491, 9), // "disparity"
QT_MOC_LITERAL(26, 501, 12) // "featureMatch"

    },
    "MainWindow\0Signal_ImgDirIsReady\0\0"
    "Signal_StopAutoMode\0Slot_OpenImgBtn_clicked\0"
    "Slot_StereoCalibBtn_clicked\0"
    "Slot_ExtractFeaturesBtn_clicked\0"
    "Slot_CalDepthBtn_clicked\0"
    "Slot_SaveDataBtn_clicked\0"
    "Slot_LoadDisparityBtn_clicked\0"
    "Slot_CalErrorBtn_clicked\0"
    "Slot_ModifyParaBtn_clicked\0"
    "Slot_OpenDirBtn_clicked\0"
    "Slot_AutoStartBtn_clicked\0Slot_ProcessNextImg\0"
    "Slot_PauseBtn_clicked\0Slot_NextImg_clicked\0"
    "Slot_Reset_clicked\0Slot_ImgDirIsReady\0"
    "Slot_StopAutoMode\0Slot_ParaAccepted\0"
    "success\0m_showImageArea\0left\0right\0"
    "disparity\0featureMatch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       1,  130, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    0,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    0,  121,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    0,  124,    2, 0x08 /* Private */,
      18,    0,  125,    2, 0x08 /* Private */,
      19,    0,  126,    2, 0x08 /* Private */,
      20,    1,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,

 // enums: name, alias, flags, count, data
      22,   22, 0x0,    4,  135,

 // enum data: key, value
      23, uint(MainWindow::left),
      24, uint(MainWindow::right),
      25, uint(MainWindow::disparity),
      26, uint(MainWindow::featureMatch),

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_ImgDirIsReady(); break;
        case 1: _t->Signal_StopAutoMode(); break;
        case 2: _t->Slot_OpenImgBtn_clicked(); break;
        case 3: { bool _r = _t->Slot_StereoCalibBtn_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->Slot_ExtractFeaturesBtn_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->Slot_CalDepthBtn_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->Slot_SaveDataBtn_clicked(); break;
        case 7: _t->Slot_LoadDisparityBtn_clicked(); break;
        case 8: _t->Slot_CalErrorBtn_clicked(); break;
        case 9: _t->Slot_ModifyParaBtn_clicked(); break;
        case 10: _t->Slot_OpenDirBtn_clicked(); break;
        case 11: _t->Slot_AutoStartBtn_clicked(); break;
        case 12: _t->Slot_ProcessNextImg(); break;
        case 13: _t->Slot_PauseBtn_clicked(); break;
        case 14: _t->Slot_NextImg_clicked(); break;
        case 15: _t->Slot_Reset_clicked(); break;
        case 16: _t->Slot_ImgDirIsReady(); break;
        case 17: _t->Slot_StopAutoMode(); break;
        case 18: _t->Slot_ParaAccepted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::Signal_ImgDirIsReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::Signal_StopAutoMode)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::Signal_ImgDirIsReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::Signal_StopAutoMode()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
