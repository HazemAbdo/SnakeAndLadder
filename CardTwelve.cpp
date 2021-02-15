#include "CardTwelve.h"
int CardTwelve::Fees = 0;
int CardTwelve::CardPrice = 0;
int CardTwelve::reserved = 0;
bool CardTwelve::Saved=false;  //the card parameters isn't saved yet 
bool CardTwelve :: Loaded=false; // the card parameters isn't loaded yet 


CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (12 here)
}

CardTwelve::~CardTwelve(void)
{
}
void CardTwelve::setReserved(int a)
{
	reserved = a;

}
void CardTwelve::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentiTwelved in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	if (reserved == 0 && !Loaded) // so if the card was loaded before it will not ask for parameters
	{
		pOut->PrintMessage("New CardTwelve: Enter its Price ...");
		int num6 = pIn->GetInteger(pOut);
		while (num6 <= 0)
		{
			pOut->PrintMessage("Invalid value,please enter positive value...");
			num6 = pIn->GetInteger(pOut);
		}
		CardPrice = num6;
		pOut->PrintMessage("New CardTwelve: Enter its Fees to pay by passing players ...");
		int num7 = pIn->GetInteger(pOut);
		while (num7 <= 0)
		{
			pOut->PrintMessage("Invalid value,please enter positive value...");
			num7 = pIn->GetInteger(pOut);
		}
		Fees = num7;
		reserved = 1;
	}
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiTwelved in the guideline steps (numbered below) below


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
			int x, y;
			pOut->PrintMessage("you have reached a station. Do you want to buy it? y/n");
			string Boolean = pIn->GetSrting(pOut);
			pOut->ClearStatusBar();
			if (Boolean == "y" || Boolean == "Y")
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
			pOut->ClearStatusBar();
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

void CardTwelve::Save(ofstream& OutFile, Type type)
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

void CardTwelve::Load(ifstream& Infile)
{
	Card::Load(Infile);

	if (!Loaded)//the card parameters isn't loaded yet 
	{
		Infile>>CardPrice>>Fees;
		Loaded=true;
		// loaded so it doesn't load it again
	}


}

void CardTwelve:: setSaved (bool isSaved )
{
	Saved=isSaved;
}

void CardTwelve:: setLoaded (bool isLoaded )
{
	Loaded=isLoaded;
}