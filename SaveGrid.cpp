#include "SaveGrid.h"
#include"Ladder.h"
#include"Snake.h"
#include"Card.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

SaveGrid::SaveGrid(ApplicationManager *pApp) : Action (pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


SaveGrid::~SaveGrid(void)
{
}


void SaveGrid :: ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the fileName parameter
	pOut->PrintMessage("Please Enter File Name:");
	fileName = pIn->GetSrting( pOut );


	pOut->ClearStatusBar();


}	

void SaveGrid :: Execute()
{
	ReadActionParameters();//file name

	Grid* pGrid = pManager->GetGrid(); // Get a Pointer to Grid
	Output* pOut = pGrid->GetOutput();// Get a Pointer to the  Output Interface

	fileName.append(".txt");  // file extension
	OutFile.open(fileName);

	if (OutFile.is_open())
	{

		OutFile<< Ladder::LadderNum<<endl;
		pGrid->SaveAll(OutFile , LADDER);

		OutFile<< Snake::SnakeNum<<endl;
		pGrid->SaveAll(OutFile , SNAKE);

		OutFile<< Card::CardNum<<endl;
		pGrid->SaveAll(OutFile , CARD);
	}

	CardTen::setSaved(false); // set the static data member saved false so the user can save the grid again
	CardEleven::setSaved(false); // set the static data member saved false so the user can save the grid again
	CardTwelve::setSaved(false); // set the static data member saved false so the user can save the grid again
	CardThirteen::setSaved(false); // set the static data member saved false so the user can save the grid again
	CardFourteen::setSaved(false); // set the static data member saved false so the user can save the grid again

	OutFile.close();

	pOut->PrintMessage("Grid Saved");
}



