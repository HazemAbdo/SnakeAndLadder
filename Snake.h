#pragma once

#include "GameObject.h"


class Snake : public GameObject // inherited from GameObject
{
    // Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

    CellPosition startcellpos; // here is the Snake's Start Cell Position


public:
    static int SnakeNum; // to count ladders in the grid

    Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

    virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

    virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

    virtual void Save(ofstream& OutFile, Type type); // saves ladder info to text file

    virtual void Load(ifstream& Infile); // loads ladder info from text file

	virtual bool IsOverLapping(GameObject * newObj) const;
    CellPosition GetEndPosition() const; // A getter for the endCellPos data member

    virtual ~Snake(); // Virtual destructor
};