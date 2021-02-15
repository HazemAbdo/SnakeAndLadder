#include "Snake.h"
#include"Ladder.h"

int Snake::SnakeNum = 0; //to initialize ladderNum 

Snake::Snake(const CellPosition& endcellpos, const CellPosition& startcellpos) : GameObject(endcellpos)
{

	this->startcellpos = startcellpos;
	SnakeNum++; //increase number of ladders
	///TODO: Do the needed validation
}




void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, startcellpos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a Snake.Click to continue..");


	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), startcellpos);
	GameObject* GOBJ = pGrid->GetGameObject(startcellpos);
	if (GOBJ)
	{
		GOBJ->Apply(pGrid, pGrid->GetCurrentPlayer());
	}
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the startcellpos
	//    Review the "pGrid" functions and decide which function can be used for that

}


void Snake::Save(ofstream& OutFile, Type type)
{
	if (type == SNAKE)
		OutFile << position.GetCellNum() << ' ' << startcellpos.GetCellNum() << endl; //write data to the file 
}

void Snake::Load(ifstream& Infile) // loads ladder info from text file
{
	int startCellNum, endCellNum;
	Infile >> startCellNum >> endCellNum; //Read data from the file 

	position = position.GetCellPositionFromNum(startCellNum); // get start cell for the ladder from the number
	startcellpos = startcellpos.GetCellPositionFromNum(endCellNum); // get end cell for the ladder from the number
}
bool Snake::IsOverLapping(GameObject* newobj)const
{
	Snake * pSnake=dynamic_cast<Snake*>(newobj);
	if (pSnake)
	{
		int VStartpos =pSnake ->GetPosition().VCell() ;
		int VEndPos=pSnake ->GetEndPosition().VCell() ;

		if (VStartpos  >= position.VCell()  &&  VStartpos<= startcellpos.VCell() )
			return true;

		if (VEndPos >= position.VCell() && VEndPos <= startcellpos.VCell()  )
			return true;
		if( VStartpos <=position.VCell() && VEndPos >=startcellpos.VCell())
			return true;
	}
	Ladder * pLadder= dynamic_cast< Ladder* >( newobj );

	if(pLadder && pLadder->GetEndPosition().VCell() == position.VCell()) // if the start of this snake is start for a ladder
		return true;

	return false;
}

CellPosition Snake::GetEndPosition() const
{
	return startcellpos;
}

Snake::~Snake()
{
	SnakeNum--; //decreace the total number of snakes
}