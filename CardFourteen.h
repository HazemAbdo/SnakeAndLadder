#pragma once
#include "Card.h"
class CardFourteen :
	public Card
{
	// CardFourteen Parameters:
	static int CardPrice;
	static int Fees;
	static int reserved;
	static bool Saved,Loaded; // to save and load the parameters once

public:
	CardFourteen(const CellPosition& pos); // A Constructor takes card Parameters

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardFourteen which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFourteen on the passed Player
	// by decrementing the player's wallet by the walletAmount data member
	virtual void Save(ofstream&, Type);
	virtual void Load(ifstream& Infile);
	static void setReserved(int a);
	static  void setSaved(bool);// setter for saved used to save the cardPrice ,Fees once
	static void setLoaded(bool);// setter for loaded used to load the cardPrice ,Fees once

	virtual ~CardFourteen(); // A Virtual Destructor

};

