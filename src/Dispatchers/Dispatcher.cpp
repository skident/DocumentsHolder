#include "Dispatcher.h"

#include <algorithm>
#include <QDebug>

Dispatcher::Dispatcher()
{

}

void Dispatcher::addStore(IStore *store)
{
    m_stores.push_back(store);
}

void Dispatcher::removeStore(IStore *store)
{
    m_stores.erase(std::remove_if(m_stores.begin(), m_stores.end(),
                                  [store](IStore* ptr){ return store == ptr; }));
}

void Dispatcher::dispatch(IAction *action) const
{
    if (!action)
    {
        return;
    }

    for (auto it : m_stores)
    {
        if (it->isSupported(action->actionType()))
        {
            it->process(action);
        }
    }
}
