#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();





	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members

	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	ReadActionParameters();
	Ladder* pLadder ;

	if (startPos.IsValidCell() && endPos.IsValidCell())
	{
		if ( startPos.HCell() !=endPos.HCell() ) // if the input is invalid 
		{
			pGrid->PrintErrorMessage("End cell and start cell are in the same column , Click to Continue");
			return;
		}
		if ( startPos.VCell() <= endPos.VCell() ) // if the input is invalid 
		{
			pGrid->PrintErrorMessage("end cell cannot be smaller than start cell , Click to Continue");
			return;
		}

		pLadder = new Ladder(startPos, endPos);

		if( pGrid->IsOverLapping(pLadder) )
		{
			pGrid->PrintErrorMessage(" Ladder can't overlap with other ladder and can't start from the end of a snake , Click to Continue");
			delete pLadder;
			return;
		}

	}else{
		pGrid->PrintErrorMessage("Check Ladder ecification , Click to Continue");
		return;
	}

	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		delete pLadder;
	}

}
