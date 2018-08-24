#include "LifeCycle.h"

#include <QQmlContext>
#include <cassert>
#include <functional>

#include "Adapters/TaskInfoAdapter.h"

LifeCycle::LifeCycle()
{
    registerModules();
}

void LifeCycle::init()
{
    registerContextProperties();

    m_qmlDispatcher.addStore(&m_tasksStore);
    m_qmlDispatcher.addStore(&m_navigationStore);

    m_qmlEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    assert (!m_qmlEngine.rootObjects().isEmpty());
}


void LifeCycle::start()
{
    m_navigationStore.setPage(Page::Enum::ALL_NOTES_ACTIVITY);
//    m_navigationStore.setPage(Page::Enum::CAMERA_ACTIVITY);
}

void LifeCycle::stop()
{

}

void LifeCycle::deinit()
{

}

void LifeCycle::registerModules()
{
    static constexpr auto FLUX_ENUMS = "Flux.Enums";
    static constexpr auto FLUX_ADAPTERS = "Flux.Adapters";

    qmlRegisterType<TaskInfoAdapter>(FLUX_ADAPTERS, 1, 0, "TaskInfo");

    qmlRegisterUncreatableType<Page>(FLUX_ENUMS, 1, 0, "Pages",
                                                 "Cannot create Page type in QML");

    qmlRegisterUncreatableType<ActionType>(FLUX_ENUMS, 1, 0, "Actions",
                                                 "Cannot create ActionType type in QML");
}

void LifeCycle::registerContextProperties()
{
    static auto setContextProperty = [this](const QString& name, QObject* obj)
    {
        m_qmlEngine.rootContext()->setContextProperty(name, obj);
    };

    setContextProperty("Dispatcher", &m_qmlDispatcher);

    setContextProperty("TasksStore", &m_tasksStore);
    setContextProperty("NavigationStore", &m_navigationStore);

    setContextProperty("AdaptersFactory", &m_adaptersFactory);
}
