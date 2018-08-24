#include "IAction.h"

IAction::IAction()
{

}

IAction::IAction(const std::string &name)
    : m_name(name)
{

}

std::string IAction::toString() const
{
    return "";
}

void IAction::setName(const std::string &name)
{
    m_name = name;
}

std::string IAction::name() const
{
    return m_name;
}

void IAction::setActionType(ActionType::Enum actionType)
{
    m_actionType = actionType;
}

ActionType::Enum IAction::actionType() const
{
    return m_actionType;
}

void IAction::setData(void *ptr)
{
    m_data_ptr = ptr;
}

void *IAction::data() const
{
    return m_data_ptr;
}

IAction::~IAction()
{

}
