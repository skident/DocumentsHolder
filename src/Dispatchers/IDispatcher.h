#pragma once

#include <string>
#include "Actions/IAction.h"

class IDispatcher
{
public:
    IDispatcher();

    virtual ~IDispatcher() = 0;

    virtual void dispatch(IAction* action) const = 0;

    virtual void setName(const std::string& name)
    {
        m_name = name;
    }

    virtual std::string name() const
    {
        return m_name;
    }

private:
    std::string m_name;
};
