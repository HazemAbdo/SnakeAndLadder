#include "CardThree.h"
#include "CardThree.h"
#include "input.h"
#include"Output.h"
#include"Ladder.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (3 here)

}

CardThree::~CardThree(void)
{
}



void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	Ladder * ladderPtr=pGrid->GetNextLadder(position); //Gets the next ladder  
	Output * pOut =pGrid->GetOutput();
	Card::Apply(pGrid, pPlayer);

	if(ladderPtr)//if there is a ladder
	{
		pGrid->UpdatePlayerCell(pPlayer , ladderPtr->GetPosition()); // to move the player to the laddder
		ladderPtr->Apply(pGrid,pPlayer);  // applies ladder action 
	}
}

void CardThree ::Save(ofstream & Outfile ,Type type){
	if (type==CARD)
	{
		Card::Save(Outfile,CARD);
		Outfile<<endl;
	}

}