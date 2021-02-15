#pragma once
#include "Action.h"
class DeleteGameObjectAction :public Action
{
	CellPosition Position;
public:
	DeleteGameObjectAction(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); // Reads parameters required for  DeleteGameObjectAction to execute 
											 // (code depends on action type so virtual)

	virtual void Execute();  // Executes  DeleteGameObjectAction

	virtual ~DeleteGameObjectAction();  // Virtual Destructor
};

