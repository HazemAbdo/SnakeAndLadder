#include "InputRollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include"Ladder.h"
#include"Cell.h"

InputRollDiceAction::InputRollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputRollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void InputRollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	// -- If not ended, do the following --:


	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (!(pGrid->GetEndGame()))
	{

		pOut->PrintMessage("“Please enter a dice value between 1-6”");
		int no = pIn->GetInteger(pOut);

		while (no <= 0 || no > 6)//validation on dicenumber
		{
			pOut->PrintMessage("Invalid value ,Please enter a dice value between 1-6");
			no = pIn->GetInteger(pOut);
		}

		int diceNumber = no;// from 1 to 6
		pOut->ClearStatusBar();
		pGrid->GetCurrentPlayer()->Move(pGrid, diceNumber);

		if (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum() >= 99)
		{
			pGrid->SetEndGame(true);
		}


		pGrid->AdvanceCurrentPlayer();


	}

}
InputRollDiceAction::~InputRollDiceAction()
{
}