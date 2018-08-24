#pragma once

#include "IDispatcher.h"
#include "Stores/IStore.h"
#include <list>

class Dispatcher : public IDispatcher
{
public:
    Dispatcher();

    void addStore(IStore* store);

    void removeStore(IStore* store);

    void dispatch(IAction* action) const override;

protected:
    std::list<IStore*> m_stores;
};

