#include "SwitchToDesignModeAction.h"


SwitchToDesignModeAction ::SwitchToDesignModeAction(ApplicationManager*pApp):Action(pApp)
{
}


SwitchToDesignModeAction::~SwitchToDesignModeAction(void)
{
}

void SwitchToDesignModeAction::ReadActionParameters(){}

void SwitchToDesignModeAction ::Execute()
{
	Grid* pGrid= pManager->GetGrid();
	Output * pOut=pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();

}