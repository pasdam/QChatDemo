TEMPLATE = app

QT += qml quick sql
CONFIG += c++11

SOURCES += main.cpp \
    source/model/ChatDataItem.cpp \
    source/control/ApplicationManager.cpp \
    source/control/MessageManager.cpp \
    source/control/SceneManager.cpp \
    source/model/MessageModel.cpp \
    source/model/UserModel.cpp \
    source/control/UserManager.cpp \
    source/control/DBManager.cpp \
    source/control/ContactsManager.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = qml

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    source/model/ChatDataItem.h \
    source/control/ApplicationManager.h \
    source/control/MessageManager.h \
    source/control/SceneManager.h \
    source/model/MessageModel.h \
    source/model/UserModel.h \
    source/control/UserManager.h \
    source/control/DBManager.h \
    source/control/ContactsManager.h

INCLUDEPATH += \
    source/
