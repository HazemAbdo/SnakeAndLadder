#include "DeleteGameObjectAction.h"
#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include"Card.h"
#include"CardOne.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void DeleteGameObjectAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	//Read Parameters
	pOut->PrintMessage("Click on the Object you want to DELETE!");
	Position = pIn->GetCellClicked();
	pOut->ClearStatusBar();


}


void DeleteGameObjectAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(Position);
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{

}