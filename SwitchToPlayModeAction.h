#pragma once
#include "action.h"
#include"Grid.h"

class SwitchToPlayModeAction :
	public Action
{
public:
	SwitchToPlayModeAction(ApplicationManager * pApp);
	~SwitchToPlayModeAction(void);
	virtual void ReadActionParameters();
	virtual void Execute();
};

