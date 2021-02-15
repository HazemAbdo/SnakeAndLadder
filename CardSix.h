#pragma once
#include "Card.h"
class CardSix :public Card
{
	// CardSix Summary:
		//Move Backword the same number of steps that you just rolled (if you reach a ladder or a snake at the end of moving forward, take it). 

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
													

	virtual ~CardSix(); // A Virtual Destructor
	//Didn't override load as it will call base class one 
	virtual void Save(ofstream&, Type);
};



