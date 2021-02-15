#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters()
{
	  // Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("Click on the source cell ...");
	SourceCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();

	/*Card* pCard = new Card(SourceCell);
	if (pGrid->AddObjectToCell(pCard))
	{
		pIn->GetUserAction();
	}
	else
		return;

	pOut->ClearStatusBar();*/
}

void CopyCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	//2-Execute Copy
	Grid* pGrid = pManager->GetGrid();

	if (SourceCell.IsValidCell()) {
		Card* newCard = new Card(SourceCell);
		newCard = pGrid->GetCard(SourceCell);
		if (newCard)
			pGrid->SetClipboard(newCard);
		Card::CardNum--;
	}
}