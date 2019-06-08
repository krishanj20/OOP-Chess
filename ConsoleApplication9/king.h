#pragma once
#include "piece.h"

//Class for the king derived from piece


class king :
	public piece
{
public:
	//Default constructor
	king();
	//parameterised constructor
	king(const int _player);
	//Virtual destructor
	virtual ~king();
	//Function returning vector of vectors of possible moves for king
	vector< vector<int> > getPossibleMoves(const int intialRow, const int initalCol);
};