#pragma once

#include "Action.h"
#include <QString>

class QmlAction : public Action
{
public:
    QmlAction(const QString& name = QString())
        : Action(name.toStdString())
    {

    }

    ~QmlAction()
    {

    }
};


