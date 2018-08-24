#pragma once

#include <QQmlApplicationEngine>
#include "Dispatchers/Dispatcher.h"
#include "Dispatchers/QmlDispatcher.h"

#include "Stores/TasksStore.h"
#include "Stores/NavigationStore.h"

#include "Adapters/AdaptersFactory.h"

class LifeCycle
{
public:
    LifeCycle();

    void init();
    void start();
    void stop();
    void deinit();

private:
    void registerModules();
    void registerContextProperties();

private:
    QQmlApplicationEngine m_qmlEngine;
    Dispatcher m_dispatcher;
    QmlDispatcher m_qmlDispatcher;

    TasksStore m_tasksStore;
    NavigationStore m_navigationStore;

    AdaptersFactory m_adaptersFactory;
};

