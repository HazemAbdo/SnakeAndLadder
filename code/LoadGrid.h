#pragma once
#include <fstream>
#include "action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include"CellPosition.h"

class LoadGrid :
	public Action

{	
	string fileName;
	ifstream InFile;
public:
	LoadGrid(ApplicationManager *pApp);
	~LoadGrid(void);
	virtual void ReadActionParameters() ; // Reads parameters required for action to execute 
	virtual void Execute() ;  // Executes action (code depends on action type so virtual)
};

