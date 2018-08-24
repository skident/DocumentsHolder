#pragma once

#include <QObject>

#include "Dispatcher.h"
#include "Adapters/TaskInfoAdapter.h"

class QmlDispatcher
        : public QObject
        , public Dispatcher
{
    Q_OBJECT

public:
    QmlDispatcher();

    void dispatch(IAction* action) const override;

    Q_INVOKABLE void dispatch(ActionType::Enum action) const;

    Q_INVOKABLE void dispatch(ActionType::Enum action, TaskInfoAdapter* taskInfo) const;
};
