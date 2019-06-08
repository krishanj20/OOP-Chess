#pragma once
#include "piece.h"

//class for the knight derived from piece

class knight : public piece
{
public:
	//Default constructor
	knight();
	//Parameterised constructor
	knight(const int _player);
	//Virtual destructor
	virtual ~knight();
	//function returning a vector of vectors of possible moves for knight
	vector< vector<int> > getPossibleMoves(const int intialRow,const int initalCol);
};
