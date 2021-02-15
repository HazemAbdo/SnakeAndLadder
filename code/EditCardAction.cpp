#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include"Card.h"
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
EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void EditCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	//Read Parameters
	pOut->PrintMessage("Click on the source to edit...");
	CardPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();


}
void EditCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Card* pCard = NULL;
	Grid* pGrid = pManager->GetGrid();
	pCard = pGrid->GetCard(CardPosition);
	if (pCard) {
		switch (pCard->GetCardNumber())
		{
		case 1:
			pCard = new CardOne(CardPosition);
			break;

			// A- Add the remaining cases
		case 2:
			pCard = new CardTwo(CardPosition);
			break;
		case 3:
			pCard = new CardThree(CardPosition);
			break;
		case 4:
			pCard = new CardFour(CardPosition);
			break;
		case 5:
			pCard = new CardFive(CardPosition);
			break;
		case 6:
			pCard = new CardSix(CardPosition);
			break;
		case 7:
			pCard = new CardSeven(CardPosition);
			break;
		case 8:
			pCard = new CardEight(CardPosition);
			break;
		case 9:
			pCard = new CardNine(CardPosition);
			break;
		case 10:
			pCard = new CardTen(CardPosition);
			CardTen::setReserved(0);
			CardTen::setLoaded(false);// so if it was loaded before it changes the parameters
			break;
		case 11:
			pCard = new CardEleven(CardPosition);
			CardEleven::setLoaded(false); // so if it was loaded before it changes the parameters
			CardEleven::setReserved(0);
			break;
		case 12:
			pCard = new CardTwelve(CardPosition);
			CardTwelve::setLoaded(false);// so if it was loaded before it changes the parameters
			CardTwelve::setReserved(0);
			break;
		case 13:
			pCard = new CardThirteen(CardPosition);
			CardThirteen::setLoaded(false);// so if it was loaded before it changes the parameters
			CardThirteen::setReserved(0);
			break;
		case 14:
			pCard = new CardFourteen(CardPosition);
			CardFourteen::setLoaded(false);// so if it was loaded before it changes the parameters
			CardFourteen::setReserved(0);
			break;
		}
		// A- We get a pointer to the Grid from the ApplicationManager
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		pGrid->RemoveObjectFromCell(CardPosition);
		pGrid->AddObjectToCell(pCard);

	}
	else {
		pGrid->PrintErrorMessage("Cell has no cards , Click to continue");
	}

}

EditCardAction::~EditCardAction()
{
}