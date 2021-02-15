#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"

#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
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

void CutCardAction::Execute()
{

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	//2-Execute Cut
	Grid* pGrid = pManager->GetGrid();
	Card * newCard=new Card(SourceCell);
	*newCard= *pGrid->GetCard(SourceCell);
	if (newCard)
	{
		pGrid->SetClipboard(newCard);
		pGrid->RemoveObjectFromCell(SourceCell);
	}
	Card::CardNum--;

}