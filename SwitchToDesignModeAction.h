#pragma once
#include "action.h"
#include"Grid.h"

class SwitchToDesignModeAction :
	public Action
{
public:
	SwitchToDesignModeAction(ApplicationManager * pApp);
	~SwitchToDesignModeAction(void);
	virtual void ReadActionParameters();
	virtual void Execute();
};

