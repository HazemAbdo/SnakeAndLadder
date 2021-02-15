#pragma once
#include "Card.h"
class CardTen :public Card
{

	// CardTen Parameters:
	static int CardPrice;
	static int Fees;
	static int reserved;
	static bool Saved,Loaded; // to save and load the parameters once

public:
	CardTen(const CellPosition& pos); // A Constructor takes card Parameters

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTen which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTen on the passed Player
	
	virtual void Save(ofstream&, Type);
	virtual void Load(ifstream& Infile);
	static void setReserved(int a);
	
	static void setSaved(bool);// setter for saved used to save the cardPrice ,Fees once
	static void setLoaded(bool);// setter for loaded used to load the cardPrice ,Fees once

	virtual ~CardTen(); // A Virtual Destructor

};




