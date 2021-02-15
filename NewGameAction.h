#pragma once
#include "action.h"
#include"Grid.h"
#include"Player.h"
class NewGameAction :
	public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	NewGameAction(ApplicationManager *pApp);
	~NewGameAction(void);
};

