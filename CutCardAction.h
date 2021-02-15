#pragma once
#include "Action.h"

class CutCardAction : public Action
{
    // [Action Parameters]
    CellPosition SourceCell;
    // Note: These parameters should be read in ReadActionParameters()

public:
    CutCardAction(ApplicationManager* pApp); // A Constructor

    virtual void ReadActionParameters(); // ReadsCutCardAction action parameters (cardNumber, cardPosition)

    virtual void Execute(); // Creates a new Card Object of the specific Card Number
                // and Reads the Parameters of This Card Number (if any)
                // then Sets this Card Object to GameObject Pointer of its Cell

    virtual ~CutCardAction(); // A Virtual Destructor
};