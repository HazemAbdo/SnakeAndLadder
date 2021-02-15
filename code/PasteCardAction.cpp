#include "PasteCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include"Ladder.h"
#include"Snake.h"
#include"Card.h"
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
#include"CopyCardAction.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
  // Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters()
{

  ///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


    // Get a Pointer to the Input / Output Interfaces
  Grid* pGrid = pManager->GetGrid();
  Output* pOut = pGrid->GetOutput();
  Input* pIn = pGrid->GetInput();

  // Read the  parameter
  pOut->PrintMessage("Click on the Destination cell ...");
  DestinationCell = pIn->GetCellClicked();
  pOut->ClearStatusBar();
}
void PasteCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Card* pCard = NULL;
	Grid* pGrid = pManager->GetGrid();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	if (pGrid->GetClipboard()) {
		switch (pGrid->GetClipboard()->GetCardNumber())
		{
		case 1:
			pCard = new CardOne(DestinationCell);
			break;
		case 2:
			pCard = new CardTwo(DestinationCell);
			break;
		case 3:
			pCard = new CardThree(DestinationCell);
			break;
		case 4:
			pCard = new CardFour(DestinationCell);
			break;
		case 5:
			pCard = new CardFive(DestinationCell);
			break;
		case 6:
			pCard = new CardSix(DestinationCell);
			break;
		case 7:
			pCard = new CardSeven(DestinationCell);
			break;
		case 8:
			pCard = new CardEight(DestinationCell);
			break;
		case 9:
			pCard = new CardNine(DestinationCell);
			break;
		case 10:
			pCard = new CardTen(DestinationCell);
			break;
		case 11:
			pCard = new CardEleven(DestinationCell);
			break;
		case 12:
			pCard = new CardTwelve(DestinationCell);
			break;
		case 13:
			pCard = new CardThirteen(DestinationCell);
			break;
		case 14:
			pCard = new CardFourteen(DestinationCell);
			break;

		}// will point to the card object type


		if (pCard)
		{
			bool added = pGrid->AddObjectToCell(pCard);
			if (!added)
			{
				pCard = pGrid->GetClipboard();
			}
			else
				return;
		}
	}
}