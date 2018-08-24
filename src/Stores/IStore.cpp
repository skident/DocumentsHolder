#include "IStore.h"

IStore::IStore()
{

}

IStore::IStore(const std::string &name)
    : m_name(name)
{

}

void IStore::setName(const std::string &name)
{
    m_name = name;
}

std::string IStore::name() const
{
    return m_name;
}

void IStore::setSupportedActions(const std::vector<ActionType::Enum> &actions)
{
    m_supportedActions.reset();

    for (const auto& actionType : actions)
    {
        setSupportedActions(actionType);
    }
}

void IStore::setSupportedActions(std::initializer_list<ActionType::Enum> actions)
{
    m_supportedActions.reset();

    for (const auto& actionType : actions)
    {
        setSupportedActions(actionType);
    }
}

void IStore::setSupportedActions(ActionType::Enum actionType)
{
    m_supportedActions.set(static_cast<long long>(actionType));
}

void IStore::setSupportedActions(long long filter)
{
    m_supportedActions = filter;
}

bool IStore::isSupported(ActionType::Enum actionType) const
{
    return m_supportedActions.test(static_cast<long long>(actionType));
}

IStore::~IStore()
{

}
