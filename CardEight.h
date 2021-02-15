#pragma once
#include "Card.h"
class CardEight :
	public Card
{

	// CardEight Parameters:
	// Prevents the player from rolling the next turn.  

public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEight on the passed Player


	virtual ~CardEight(); // A Virtual Destructor
	//Didn't override load as it will call base class one 
	virtual void Save(ofstream&, Type);

};

