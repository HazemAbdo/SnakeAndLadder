#pragma once

#include "Card.h"

// [ CardThree ] Summary:
// Moves the player forward to the start of the next ladder. (If no ladders ahead, do nothing) 

class CardThree : public Card
{

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardThree(); // A Virtual Destructor
	//Didn't override load as it will call base class one 
virtual void Save(ofstream&, Type);

};

