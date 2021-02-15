#include "CardEleven.h"
int CardEleven::Fees = 0;
int CardEleven::CardPrice = 0;
int CardEleven::reserved = 0;
bool CardEleven::Saved=false;  //the card parameters isn't saved yet 
bool CardEleven :: Loaded=false; // the card parameters isn't loaded yet 

CardEleven::CardEleven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (11 here)
}

CardEleven::~CardEleven(void)
{
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentiElevend in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	
	
	if (reserved == 0 && !Loaded) // so if the card was loaded before it will not ask for parameters
	{
		pOut->PrintMessage("New CardEleven: Enter its Price ...");
		int num9 = pIn->GetInteger(pOut);
		while (num9 <= 0)
		{
			pOut->PrintMessage("Invalid value,please enter positive value...");
			num9 = pIn->GetInteger(pOut);
		}
		CardPrice = num9;
		pOut->PrintMessage("New CardEleven: Enter its Fees to pay by passing players ...");
		int num0 = pIn->GetInteger(pOut);
		while (num0 <= 0)
		{
			pOut->PrintMessage("Invalid value,please enter positive value...");
			num0 = pIn->GetInteger(pOut);
		}
		Fees = num0;
		reserved = 1;
	}
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiElevend in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	if (pPlayer->GetTurnCount() != 0)
	{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	static Player* ptrPlayer = NULL;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

		if (ptrPlayer == NULL)
		{
			pOut->PrintMessage("you have reached a station. Do you want to buy it? y/n");
			string Boolean = pIn->GetSrting(pOut);
			pOut->ClearStatusBar();
			if (Boolean == "y"||Boolean=="Y")
			{
				ptrPlayer = pPlayer;
				pPlayer->SetCell(pGrid->GetCurrentPlayer()->GetCell());
				int bought = ptrPlayer->GetWallet() - CardPrice;
				if (bought > 0)
					ptrPlayer->SetWallet(bought);
				else

				{
					pOut->PrintMessage("You don't have money to buy it");
					ptrPlayer = NULL;
				}
			}
		}
		if (ptrPlayer != NULL && ptrPlayer != pPlayer)
		{

			pOut->PrintMessage("You have to pay fees");
			int pw = pPlayer->GetWallet() - Fees;
			pPlayer->SetWallet(pw);
			int pw2 = ptrPlayer->GetWallet() + Fees;
			ptrPlayer->SetWallet(pw2);

		}
		if (ptrPlayer == pPlayer)
		{
		}

	}
}

void CardEleven::setReserved(int a)
{
	reserved = a;

}
void CardEleven::Save(ofstream& OutFile, Type type)
{
	if(type== CARD)
	{
		Card::Save(OutFile,type);

		if(!Saved){//the card parameters isn't saved yet 
			OutFile<<CardPrice<<' '<<Fees;
			Saved=true;
			// saved so it doesn't save it again
		}
		OutFile<<endl;
	}
}

void CardEleven::Load(ifstream& Infile)
{
	Card::Load(Infile);

	if (!Loaded)//the card parameters isn't loaded yet 
	{
		Infile>>CardPrice>>Fees;
		Loaded=true;
		// loaded so it doesn't load it again
	}


}
void CardEleven:: setSaved (bool isSaved )
{
	Saved=isSaved;
}

void CardEleven:: setLoaded (bool isLoaded )
{
	Loaded=isLoaded;
}