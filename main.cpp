#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "LifeCycle/LifeCycle.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    LifeCycle lifeCycle;
    lifeCycle.init();
    lifeCycle.start();

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    return app.exec();
}
