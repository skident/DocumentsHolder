QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "src"

SOURCES += main.cpp \
    src/Actions/Action.cpp \
    src/Actions/IAction.cpp \
    src/Actions/QmlAction.cpp \
    src/Adapters/AdaptersFactory.cpp \
    src/Adapters/TaskInfoAdapter.cpp \
    src/Dispatchers/Dispatcher.cpp \
    src/Dispatchers/IDispatcher.cpp \
    src/Dispatchers/QmlDispatcher.cpp \
    src/LifeCycle/LifeCycle.cpp \
    src/Persistency/Persistency.cpp \
    src/Settings/AppSettings.cpp \
    src/Stores/IStore.cpp \
    src/Stores/NavigationStore.cpp \
    src/Stores/Store.cpp \
    src/Stores/TasksStore.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CopyrightTemplate

HEADERS += \
    src/Actions/Action.h \
    src/Actions/ActionType.h \
    src/Actions/IAction.h \
    src/Actions/QmlAction.h \
    src/Adapters/AdaptersFactory.h \
    src/Adapters/CustomEnums.h \
    src/Adapters/TaskInfoAdapter.h \
    src/Dispatchers/Dispatcher.h \
    src/Dispatchers/IDispatcher.h \
    src/Dispatchers/QmlDispatcher.h \
    src/LifeCycle/LifeCycle.h \
    src/Persistency/Persistency.h \
    src/Settings/AppSettings.h \
    src/Stores/IStore.h \
    src/Stores/NavigationStore.h \
    src/Stores/Store.h \
    src/Stores/TasksStore.h
