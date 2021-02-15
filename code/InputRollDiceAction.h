#pragma once

#include "Action.h"

class InputRollDiceAction : public Action
{

    // No parameters for this action

public:
    InputRollDiceAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    virtual ~InputRollDiceAction();
};