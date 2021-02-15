#include "NewGameAction.h"


NewGameAction::NewGameAction(ApplicationManager *pApp):Action(pApp)
{
}


NewGameAction::~NewGameAction(void)
{
}

void NewGameAction :: ReadActionParameters()
{

}

void NewGameAction:: Execute()
{

	Grid * pGrid = pManager->GetGrid();
	pGrid->SetEndGame(false);

	CellPosition firstCell(8,0);

	Player * pPlayer ;

	for (int i=0;i<MaxPlayerCount;i++)  // loop to make all player's wallet =100
										// and to reset their positions
											//and resets used actions
	{
		pPlayer=pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell( pPlayer, firstCell);
		pPlayer->ResetUsedActions();
		pGrid->GetCurrentPlayer()->SetWallet(100);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetCurrPlayerNumber(0);

}