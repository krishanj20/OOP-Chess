#pragma once
#include "piece.h"

//This class is for each square of the board.
//It contains a pointer to the piece on the quare, and is a nullptr if there is no piece.

class square {
private:
	piece * pieceOnSquare;	//pointer to piece on the square. void if no piece is present.

public:
	//Default constructor
	square();
	//Parameterised constuctor
	square(piece *);
	//Default destuctor
	~square();
	//Piece setter
	void setPieceOnSquare(piece *piece);
	//Piece getter
	piece* getPieceOnSquare();

	//A getter and setter are being used
	//this allows access to protected/private variables
};




