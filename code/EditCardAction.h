#pragma once
#include "Action.h"
class EditCardAction :public Action
{
	CellPosition CardPosition;
	Card* pCard;
public:
	EditCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~EditCardAction();
};

