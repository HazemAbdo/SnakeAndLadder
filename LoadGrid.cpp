#include "LoadGrid.h"
#include "Ladder.h"
#include "Snake.h"
#include"CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"
LoadGrid::LoadGrid(ApplicationManager *pApp) : Action (pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


LoadGrid::~LoadGrid(void)
{
}

void LoadGrid :: ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the fileName parameter
	pOut->PrintMessage("Please Enter File Name ( Without .txt):");
	fileName = pIn->GetSrting( pOut );
	pOut->ClearStatusBar();


}

void LoadGrid :: Execute()
{
	ReadActionParameters();//file name

	Grid* pGrid = pManager->GetGrid(); // Get a Pointer to Grid
	Output* pOut = pGrid->GetOutput();// Get a Pointer to the  Output Interface
	Input* pIn = pGrid->GetInput(); // Get a Pointer to the  Input Interface

	fileName.append(".txt");  // file extension
	InFile.open(fileName);   //opens the file



	int number;
	GameObject* CurrentObject;

	if (InFile.is_open())   //make sure the file exists
	{
		pGrid->CleanGrid(); //to clean the grid  
		InFile >> number;
		CellPosition  cell; //just to construct the Gameobjects

		//============Drawing Ladders=====================

		for(int i=0;i<number ;i++)
		{

			CurrentObject=new Ladder( cell , cell );
			CurrentObject->Load(InFile);

			pGrid->AddObjectToCell(CurrentObject);

		}

		//============Drawing Snake=====================

		InFile >> number;
		for(int i=0;i<number ;i++)
		{

			CurrentObject=new Snake( cell , cell );
			CurrentObject->Load(InFile);

			pGrid->AddObjectToCell(CurrentObject);

		}

		//============Drawing Cards=====================
		CardTen::setLoaded(false); // set the static data member Loaded false so the user can load the grid again
		CardEleven::setLoaded(false); // set the static data member Loaded false so the user can load the grid again
		CardTwelve::setLoaded(false); // set the static data member Loaded false so the user can load the grid again
		CardThirteen::setLoaded(false); // set the static data member Loaded false so the user can load the grid again
		CardFourteen::setLoaded(false); // set the static data member Loaded false so the user can load the grid again

		InFile >> number;
		for(int i=0;i<number ;i++)
		{
			int CardNumber;
			InFile>>CardNumber;

			switch(CardNumber){
			case 1:
				CurrentObject=new CardOne( cell );
				break;
			case 2:
				CurrentObject=new CardTwo( cell );
				break;
			case 3:
				CurrentObject=new CardThree( cell );
				break;
			case 4:
				CurrentObject=new CardFour( cell );
				break;
			case 5:
				CurrentObject=new CardFive( cell );
				break;
			case 6:
				CurrentObject=new CardSix( cell );
				break;
			case 7:
				CurrentObject=new CardSeven( cell );
				break;
			case 8:
				CurrentObject=new CardEight( cell );
				break;
			case 9:
				CurrentObject=new CardNine( cell );
				break;
			case 10:
				CurrentObject=new CardTen( cell );
				break;
			case 11:
				CurrentObject=new CardEleven( cell );
				break;
			case 12:
				CurrentObject=new CardTwelve( cell );
				break;
			case 13:
				CurrentObject=new CardThirteen( cell );
				break;
			case 14:
				CurrentObject=new CardFourteen( cell );
				break;


			}

			CurrentObject->Load(InFile);

			pGrid->AddObjectToCell(CurrentObject);

		}



		InFile.close();
		pOut->PrintMessage("Grid Loaded");

	}
	else       //the file doesn't exist
	{
		pOut->PrintMessage("file doesn't exist");
	}



}