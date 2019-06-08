#pragma once
#include "piece.h"

//Class for pawn derived from piece

class pawn : public piece
{
public:
	//Default constructor
	pawn();
	//parametrised constuctor
	pawn(const int _player);
	//Default virtual destructor
	virtual ~pawn();

	//function returning a vector of vectors of possible moves for pawn
	vector< vector<int> > getPossibleMoves(const int intialRow,const int initalCol);
};


