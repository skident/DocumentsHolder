#pragma once

#include <QObject>
#include "IStore.h"
#include "Actions/QmlAction.h"
#include "Adapters/TaskInfoAdapter.h"

#include "Settings/AppSettings.h"
#include "Persistency/Persistency.h"

class TasksStore
        : public QObject
        , public IStore
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> tasks READ tasks NOTIFY tasksChanged)
    Q_PROPERTY(TaskInfoAdapter* editTask READ editTask NOTIFY editTaskChanged)

public:
    TasksStore();

    void process(IAction* action) override;

    QList<QObject*> tasks() const;

    TaskInfoAdapter* editTask() const;

private:
    void addTask(TaskInfoAdapter* taskInfo);

    void removeTask(TaskInfoAdapter* task);

    void editTask(TaskInfoAdapter* task);

    void applyTask(TaskInfoAdapter* task);
signals:
    void tasksChanged();
    void editTaskChanged();

private:
    QList<QObject*> m_tasks;
    TaskInfoAdapter* m_editTask = nullptr;

    Persistancy m_storage;
};

