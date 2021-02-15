#pragma once
#include "Card.h"
class CardNine :
	public Card
{
	CellPosition Goto;
public:
	CardNine(const CellPosition& pos ); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNine which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	virtual void Save(ofstream&, Type);
	virtual void Load(ifstream &Infile);
	virtual ~CardNine(); // A Virtual Destructor

};

