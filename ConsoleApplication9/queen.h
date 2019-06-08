#pragma once
#include "piece.h"

//class for queen derived from piece

class queen :
	public piece
{
public:
	//Default constructor
	queen();
	//Parameterised constructor
	queen(const int _player);
	//Virtual destructor
	virtual ~queen();
	vector< vector<int> > getPossibleMoves(const int intialRow, const int initalCol);
};


