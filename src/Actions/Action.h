#pragma once
#include "IAction.h"

class Action : public IAction
{
public:
    Action();
    Action(const std::string& name) : IAction(name)
    {

    }
};
