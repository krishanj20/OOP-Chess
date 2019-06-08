#include "stdafx.h"
#include "square.h"

//Default constructor, sets piece to nullptr on default construction
square::square()
{
	pieceOnSquare = nullptr;
}

//Parametrised constructor
square::square(piece * _pieceOnSquare) {
	this->pieceOnSquare = _pieceOnSquare;
}
//Destructor
square::~square()
{
}

//Setter for the piece variable 
void square::setPieceOnSquare(piece *_piece) {
	pieceOnSquare = _piece;
}

//Getter for the piece variable
piece * square::getPieceOnSquare() {
	return pieceOnSquare;
}
