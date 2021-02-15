#include "CardTwo.h"
#include"Card.h"
int CardTwo::walletAmount = 0;

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
    cardNumber = 2;
	// set the inherited cardNumber data member with the card number (1 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{


    ///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


    // == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


    // 1- Get a Pointer to the Input / Output Interfaces from the Grid
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();
    // 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
    //    Don't forget to first print to a descriptive message to the user like:"New CardTwo: Enter its wallet amount ..."
    pOut->PrintMessage("New CardTwo: Enter its wallet amount ...");
    walletAmount = pIn->GetInteger(pOut);

    // [ Note ]:
    // In CardTwo, the only parameter of CardTwo is the "walletAmount" value to decrease from player
    // Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
    // to be able to perform his Apply() action

    // 3- Clear the status bar
    pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

    ///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


    // == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
    Card::Apply(pGrid, pPlayer);
    // 1- Call Apply() of the base class Card to print the message that you reached this card number
  
    int playWall = pPlayer->GetWallet() + walletAmount;
    pPlayer->SetWallet(playWall);

    // 2- Decrement the wallet of pPlayer by the walletAmount data member of CardTwo

}

void CardTwo::Save(ofstream& OutFile, Type type)
{
    if (type == CARD) {
        Card::Save(OutFile, type); // to save postition and card number
        OutFile << walletAmount << endl;
    }
}
void CardTwo::Load(ifstream& Infile)
{

    Card::Load(Infile);
    Infile >> walletAmount;
}