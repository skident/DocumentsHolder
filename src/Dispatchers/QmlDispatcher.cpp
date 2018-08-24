#include "QmlDispatcher.h"

#include <QVariantMap>
#include <QDebug>
#include "Actions/QmlAction.h"

QmlDispatcher::QmlDispatcher()
{

}

void QmlDispatcher::dispatch(IAction *action) const
{
    Dispatcher::dispatch(action);
}

void QmlDispatcher::dispatch(ActionType::Enum action) const
{
    QmlAction qmlAction;
    qmlAction.setActionType(action);
    this->dispatch(&qmlAction);
}

void QmlDispatcher::dispatch(ActionType::Enum action, TaskInfoAdapter *taskInfo) const
{
    QmlAction qmlAction;
    qmlAction.setActionType(action);
    qmlAction.setData(taskInfo);
    this->dispatch(&qmlAction);
}
