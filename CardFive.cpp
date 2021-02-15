#include "CardFive.h"
CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
	 
}

CardFive::~CardFive(void)
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
		Card::Apply(pGrid, pPlayer);
		pPlayer->MoveInSameTurn(pGrid, pPlayer->GetJustRolledDiceNum()); //moves the player with the same dice number again

}
void CardFive ::Save(ofstream & Outfile ,Type type){
	if (type==CARD)
	{
		Card::Save(Outfile,CARD);
		Outfile<<endl;
	}

}