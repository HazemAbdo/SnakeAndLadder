#include "Ladder.h"
#include"Snake.h"
#include"ApplicationManager.h"
#include "Input.h"
#include "Output.h"

int Ladder::LadderNum = 0; //to initialize ladderNum 

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

	this->endCellPos = endCellPos;
	LadderNum++; //increase number of ladders
	///TODO: Do the needed validation
}




void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) to implement this function ==
	int x, y;
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a Ladder.Click to continue..");
	pIn->GetPointClicked(x, y);

	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), endCellPos);
	GameObject* GOBJ = pGrid->GetGameObject(endCellPos);
	if (GOBJ)
	{
		GOBJ->Apply(pGrid, pGrid->GetCurrentPlayer());
	}
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pOut->ClearStatusBar();
}

bool Ladder::IsOverLapping(GameObject* newobj)const
{
	Ladder * pLadder=dynamic_cast<Ladder*>(newobj);
	if (pLadder)
	{
		int VStartpos =pLadder ->GetPosition().VCell() ;
		int VEndPos=pLadder ->GetEndPosition().VCell() ;

		if (VStartpos  <= position.VCell()  &&  VStartpos>= endCellPos.VCell() )
			return true;

		if (VEndPos <= position.VCell() && VEndPos >= endCellPos.VCell()  )
			return true;
		if( VStartpos >=position.VCell() && VEndPos <=endCellPos.VCell())
			return true;
	}
	Snake * pSnake= dynamic_cast< Snake* >( newobj );

	if(pSnake && pSnake->GetPosition().VCell() == endCellPos.VCell()) // if the end of this ladder is start for a snake
		return true;

	return false;
}

void Ladder::Save(ofstream& OutFile, Type type)
{
	if (type == LADDER)
		OutFile << position.GetCellNum() << ' ' << endCellPos.GetCellNum() << endl; //write data to the file 
}

void Ladder::Load(ifstream& Infile) // loads ladder info from text file
{
	int startCellNum, endCellNum;
	Infile >> startCellNum >> endCellNum; //Read data from the file 

	position = position.GetCellPositionFromNum(startCellNum); // get start cell for the ladder from the number
	endCellPos = endCellPos.GetCellPositionFromNum(endCellNum); // get end cell for the ladder from the number
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
	LadderNum--; //decreace the total number of ladders
}