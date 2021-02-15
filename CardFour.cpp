#include "Card.h"
#include "CardFour.h"
#include "input.h"
#include"Output.h"
#include"Snake.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)

}

CardFour::~CardFour(void)
{
}



void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	Snake * SnakePtr=pGrid->GetNextSnake(position); //Gets the next Snake  
	Output * pOut =pGrid->GetOutput();
	Card::Apply(pGrid, pPlayer);
	if(SnakePtr)//if there is a snake
	{
		pGrid->UpdatePlayerCell(pPlayer , SnakePtr->GetPosition()); // to move the player to the laddder
		SnakePtr->Apply(pGrid,pPlayer);  // applies ladder action 
	}
}

void CardFour ::Save(ofstream & Outfile ,Type type){
	if (type==CARD)
	{
		Card::Save(Outfile,CARD);
		Outfile<<endl;
	}

}