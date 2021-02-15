#include "CardSix.h"
CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
	 
}

CardSix::~CardSix(void)
{
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
		Card::Apply(pGrid, pPlayer);
		pPlayer->MoveInSameTurn(pGrid, - pPlayer->GetJustRolledDiceNum()); //moves the player backword with the same dice number again

}
void CardSix ::Save(ofstream & Outfile ,Type type){
	if (type==CARD)
	{
		Card::Save(Outfile,CARD);
		Outfile<<endl;
	}

}