
#include "CardSeven.h"
#include"time.h"


CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)

}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,  pPlayer);
	// 2- Generate a random number from 1 to 6 --> This step is done for you
	Output* pOut = pGrid->GetOutput();

	if (!(pGrid->GetEndGame()))
	{
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

		pGrid->PrintErrorMessage("New Roll Dice : "+to_string(diceNumber));
		pGrid->GetCurrentPlayer()->MoveInSameTurn(pGrid, diceNumber);//moves the player without changing turn count



		GameObject* PG = pGrid->GetCurrentPlayer()->GetCell()->GetGameObject();
		if (PG)
		{
			PG->Apply(pGrid, pGrid->GetCurrentPlayer());
		}

		if (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum() == 99)
		{
			pGrid->SetEndGame(true);
		}

		pGrid->AdvanceCurrentPlayer();
	}
}

void CardSeven ::Save(ofstream & Outfile ,Type type){
	if (type==CARD)
	{
		Card::Save(Outfile,CARD);
		Outfile<<endl;
	}

}