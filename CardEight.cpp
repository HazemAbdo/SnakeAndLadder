#include "CardEight.h"
CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)

}

CardEight::~CardEight(void)
{

}

void CardEight::ReadCardParameters(Grid* pGrid)
{



}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid , pPlayer);
	pPlayer->SetFreeze(true); // freezes the player for one turn
}

void CardEight ::Save(ofstream & Outfile ,Type type){
	if (type==CARD)
	{
		Card::Save(Outfile,CARD);
		Outfile<<endl;
	}

}