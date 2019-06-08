#pragma once
#include "piece.h"

//Class for the rook derived from piece


class rook :
	public piece
{
public:
	//Default constructor
	rook();
	//Parameterised constructor
	rook(const int _player);
	//Virtual destructor
	virtual ~rook();
	//function returning a vector of vectors of possible moves for rook
	vector< vector<int> > getPossibleMoves(const int intialRow,const int initalCol);
};
