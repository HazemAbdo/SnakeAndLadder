#pragma once
#include "Card.h"
class CardSeven :public Card
{
	// CardSeven Summary:
		//Gives the player another dice rol

public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player
													  
	virtual ~CardSeven(); // A Virtual Destructor
	//Didn't override load as it will call base class one
	virtual void Save(ofstream&, Type);
};

