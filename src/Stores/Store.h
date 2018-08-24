#pragma once

#include "IStore.h"
#include "Actions/IAction.h"
#include <cassert>
#include <QDebug>

class Store : public IStore
{
public:
    Store();
    Store(const std::string& name) : IStore(name)
    {

    }

    void process(IAction* action) override
    {
        assert(action);

        qDebug() << "Store:" << this->name().c_str()
                 << "processed action:" << action->name().c_str();
    }
};

