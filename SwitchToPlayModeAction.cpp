#include "SwitchToPlayModeAction.h"


SwitchToPlayModeAction ::SwitchToPlayModeAction(ApplicationManager*pApp):Action(pApp)
{
}


SwitchToPlayModeAction::~SwitchToPlayModeAction(void)
{
}

void SwitchToPlayModeAction::ReadActionParameters(){}

void SwitchToPlayModeAction ::Execute()
{
	Grid* pGrid= pManager->GetGrid();
	Output * pOut=pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();

}