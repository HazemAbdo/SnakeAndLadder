#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	pOut->ClearStatusBar();

}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Snake* pSnake ;

	if (startPos.IsValidCell() && endPos.IsValidCell())
	{
		if ( startPos.HCell() !=endPos.HCell() ) // if the input is invalid 
		{
			pGrid->PrintErrorMessage("End cell and start cell are in the same column , Click to Continue");
			return;
		}
		if ( startPos.VCell() >= endPos.VCell() ) // if the input is invalid 
		{
			pGrid->PrintErrorMessage("start cell cannot be smaller than end cell , Click to Continue");
			return;
		}

		pSnake = new Snake(startPos, endPos);

		if( pGrid->IsOverLapping(pSnake) ){
			pGrid->PrintErrorMessage(" Snake can't overlap with other Snake and can't start from the end of a Ladder , Click to Continue");
			delete pSnake;
			return;
		}

	}else{
		pGrid->PrintErrorMessage("Check Ladder ecification , Click to Continue");
		return;
	}

	// Create a Ladder object with the parameters read from the user


	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		delete pSnake;
	}

}