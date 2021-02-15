#include "CardNine.h"   

CardNine::CardNine(const CellPosition& pos ) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
	 

}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentiNined in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut= pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage(" Click Cell to move to ");
	Goto= pIn->GetCellClicked(); // reading card   
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiNined in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	Card::Apply(pGrid, pPlayer);

	pGrid->UpdatePlayerCell(pPlayer,Goto);
	GameObject * GmObject =pGrid->GetGameObject(Goto);

	if(GmObject) ///if the new cell has an object
		GmObject->Apply(pGrid,pPlayer); //applies object action 

}

void CardNine::  Save( ofstream &OutFile  ,Type type)
{
	if (type== CARD){
		Card::Save(OutFile, type); // to save postition and card number
		OutFile<<Goto.GetCellNumFromPosition(Goto)<<endl;
	}
} 

void CardNine ::Load(ifstream &Infile)
{
	Card::Load(Infile);

	int cellNum;
	Infile>>cellNum;
	Goto=Goto.GetCellPositionFromNum(cellNum);
}