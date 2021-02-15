#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include"Ladder.h"
#include"Cell.h"
#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{



	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (!(pGrid->GetEndGame()))
	{
	

			srand((int)time(NULL)); // time is for different seed each run
			int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

			pGrid->PrintErrorMessage("Roll Dice : "+to_string(diceNumber));//print the generated numbr 

			pGrid->GetCurrentPlayer()->Move(pGrid, diceNumber);



		if (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum() == 99)
		{
			pGrid->SetEndGame(true);
		}

		pGrid->AdvanceCurrentPlayer();
	}


}

RollDiceAction::~RollDiceAction()
{
}