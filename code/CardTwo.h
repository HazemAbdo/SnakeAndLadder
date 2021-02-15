#pragma once
#include "Card.h"
class CardTwo :public Card
{
	// CardTwo Parameters:
	 static int walletAmount; // the wallet value to decrease from the player

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	virtual void Save(ofstream&, Type);
	virtual void Load(ifstream& Infile);
	virtual ~CardTwo(); // A Virtual Destructor
};

