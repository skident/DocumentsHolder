#include "TasksStore.h"



TasksStore::TasksStore()
    : m_storage("tasks.txt")
{
    setSupportedActions(ActionType::Enum::ADD_TASK
                        | ActionType::Enum::REMOVE_TASK
                        | ActionType::Enum::EDIT_TASK
                        | ActionType::Enum::APPLY_TASK);


    m_tasks = m_storage.loadTasks();
}

void TasksStore::process(IAction *action)
{
    if (!action)
    {
        return;
    }

    TaskInfoAdapter* taskInfo = action->data<TaskInfoAdapter>();
    if (!taskInfo)
    {
        return;
    }

    switch (action->actionType())
    {
    case ActionType::Enum::CANCEL_EDIT_TASK:
        break;
    case ActionType::Enum::ADD_TASK:
        addTask(taskInfo);
        break;

    case ActionType::Enum::REMOVE_TASK:
        removeTask(taskInfo);
        break;

    case ActionType::Enum::EDIT_TASK:
        editTask(taskInfo);
        break;

    case ActionType::Enum::APPLY_TASK:
        applyTask(taskInfo);
        break;

    default:
        break;
    }

    m_storage.storeTasks(m_tasks);

}

QList<QObject *> TasksStore::tasks() const
{
    return m_tasks;
}

TaskInfoAdapter *TasksStore::editTask() const
{
    return m_editTask;
}

void TasksStore::addTask(TaskInfoAdapter *taskInfo)
{
    m_tasks.push_back(taskInfo);
    emit tasksChanged();
}

void TasksStore::removeTask(TaskInfoAdapter *task)
{
    m_tasks.removeOne(task);
    emit tasksChanged();
}

void TasksStore::editTask(TaskInfoAdapter *task)
{
    m_editTask = task;
    emit editTaskChanged();
}

void TasksStore::applyTask(TaskInfoAdapter *task)
{
    for (auto it : m_tasks)
    {
        if (dynamic_cast<TaskInfoAdapter*>(it) == task)
        {
            it = task;
            break;
        }
    }
    emit tasksChanged();
}
