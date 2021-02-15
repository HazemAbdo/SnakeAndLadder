#pragma once
#include "Action.h"

class PasteCardAction : public Action
{
    // [Action Parameters]
    CellPosition DestinationCell;
    int CardNumber;
    // Note: These parameters should be read in ReadActionParameters()

public:
    PasteCardAction(ApplicationManager* pApp); // A Constructor

    virtual void ReadActionParameters(); // Reads PasteCardAction action parameters (cardNumber, cardPosition)

    virtual void Execute(); // Creates a new Card Object of the specific Card Number
                // and Reads the Parameters of This Card Number (if any)
                // then Sets this Card Object to GameObject Pointer of its Cell

    virtual ~PasteCardAction(); // A Virtual Destructor
};