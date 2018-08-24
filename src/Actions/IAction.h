#pragma once

#include <string>
#include "ActionType.h"

class IAction
{
public:
    IAction();
    IAction(const std::string& name);

    virtual ~IAction() = 0;

    virtual std::string toString() const;

    virtual void setName(const std::string& name);

    virtual std::string name() const;

    void setActionType(ActionType::Enum actionType);

    ActionType::Enum actionType() const;

    void setData(void* ptr);

    void* data() const;

    template <typename T>
    T* data() const
    {
        return static_cast<T*>(m_data_ptr);
    }

private:
    std::string m_name;
    ActionType::Enum m_actionType = ActionType::Enum::NONE;

    void* m_data_ptr = nullptr;
};

