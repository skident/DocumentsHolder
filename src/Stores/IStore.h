#pragma once

#include <string>
#include <bitset>
#include <QDebug>

#include "Actions/ActionType.h"

class IAction;

class IStore
{
public:
    IStore();
    IStore(const std::string& name);

    virtual ~IStore() = 0;

    virtual void process(IAction* action) = 0;

    virtual void setName(const std::string& name);

    virtual std::string name() const;

    void setSupportedActions(const std::vector<ActionType::Enum>& actions);

    void setSupportedActions(std::initializer_list<ActionType::Enum> actions);

    void setSupportedActions(ActionType::Enum actionType);

    void setSupportedActions(long long filter);

    bool isSupported(ActionType::Enum actionType) const;

private:
    std::string m_name;
    std::bitset<sizeof(long long) * 8> m_supportedActions;
};

