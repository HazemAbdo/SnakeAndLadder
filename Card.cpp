#include "Card.h"

int Card::CardNum=0;

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
	CardNum++;
	cardNumber = -1;
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}


void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract class

}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

Card::~Card()
{
	CardNum--; //decreace the total number of cards
}

void Card :: Save( ofstream & OutFile ,Type type )
{
	if(type == CARD)
		OutFile<<cardNumber<<' '<<position.GetCellNum()<<' ';


}
 void Card::Load(ifstream &Infile)
{
	int cellNum;
	Infile>>cellNum;
	position=position.GetCellPositionFromNum(cellNum);
}

 