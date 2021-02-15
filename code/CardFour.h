#pragma once

#include "Card.h"

// [ CardFour ] Summary:
//  Moves the player forward to the start of the next snake. (If no snakes ahead, do nothing)  

class CardFour : public Card
{

public:
	CardFour(const CellPosition& pos); // A Constructor takes card position
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardFour(); // A Virtual Destructor
	//Didn't override load as it will call base class one 
	virtual void Save(ofstream&, Type);

};

