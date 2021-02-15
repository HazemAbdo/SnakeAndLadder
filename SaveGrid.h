#pragma once
#include <fstream>
#include "action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"


class SaveGrid :
	public Action
{
	string fileName;
	ofstream OutFile; 

public:

	SaveGrid(ApplicationManager * );
	~SaveGrid(void);
	virtual void ReadActionParameters() ; // Reads parameters required for action to execute 
	virtual void Execute() ;  // Executes action (code depends on action type so virtual)


};

