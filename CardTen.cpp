#include "CardTen.h"
int CardTen::Fees = 0;
int CardTen::CardPrice = 0;
int CardTen::reserved = 0;
bool CardTen::Saved=false;  //the card parameters isn't saved yet 
bool CardTen :: Loaded=false; // the card parameters isn't loaded yet 

CardTen::CardTen(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 10; // set the inherited cardNumber data member with the card number (11 here)
}

CardTen::~CardTen(void)
{
}
void CardTen::ReadCardParameters(Grid* pGrid)
{
	///TODO: Implement this function as mentiTend in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	if (reserved == 0 && !Loaded) // so if the card was loaded before it will not ask for parameters
	{
		pOut->PrintMessage("New CardTen: Enter its Price ...");
		int num = pIn->GetInteger(pOut);
		while (num <= 0)
		{
			pOut->PrintMessage("Invalid value,please enter positive value...");
			num = pIn->GetInteger(pOut);
		}
		CardPrice = num;
		pOut->PrintMessage("New CardTen: Enter its Fees to pay by passing players ...");
		int num1 = pIn->GetInteger(pOut);
		while (num1 <= 0)
		{
			pOut->PrintMessage("Invalid value,please enter positive value...");
			num1 = pIn->GetInteger(pOut);
		}
		Fees = num1;
		reserved = 1;
	}

	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiTend in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	if (pPlayer->GetTurnCount() != 0)
	{
		Card::Apply(pGrid, pPlayer);
		static Player* ptrPlayer = NULL;
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();

		if (ptrPlayer == NULL)
		{
			pOut->PrintMessage("you have reached a station. Do you want to buy it? y/n");
			string Boolean = pIn->GetSrting(pOut);
			pOut->ClearStatusBar();
			if (Boolean == "y" || Boolean == "Y")
			{
				ptrPlayer = pPlayer;
				pPlayer->SetCell(pGrid->GetCurrentPlayer()->GetCell());
				int bought = ptrPlayer->GetWallet() - CardPrice;
				if (bought >= 0)
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
			int x, y;
			if (pPlayer->GetWallet() > 0)
			{
				pOut->PrintMessage("you have reached a bought station. Click to continue");
				pIn->GetPointClicked(x, y);
				int pw = pPlayer->GetWallet() - Fees;
				pPlayer->SetWallet(pw);
				int pw2 = ptrPlayer->GetWallet() + Fees;
				ptrPlayer->SetWallet(pw2);
			}
		}
		if (ptrPlayer == pPlayer)
		{
		}

	}
}



void CardTen::setReserved(int a)
{
	reserved = a;

}

void CardTen::Save(ofstream& OutFile, Type type)
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

void CardTen::Load(ifstream& Infile)
{
	Card::Load(Infile);

	if (!Loaded)//the card parameters isn't loaded yet 
	{
		Infile>>CardPrice>>Fees;
		Loaded=true;
		// loaded so it doesn't load it again
	}


}

void CardTen:: setSaved (bool isSaved )
{
	Saved=isSaved;
}

void CardTen:: setLoaded (bool isLoaded )
{
	Loaded=isLoaded;
}