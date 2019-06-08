#pragma once
#include "piece.h"

//Header file for the bishop piece
//Derived from piece class

class bishop : public piece
{
public:
	//Default constructor
	bishop();
	//Parameterised constructor
	bishop(int _player);
	//Virtual Destructor
	virtual ~bishop();
	//A function which returns a vector of vectors containing the possible moves for this piece.
	vector< vector<int> > getPossibleMoves(const int intialRow, const int initalCol);
};
