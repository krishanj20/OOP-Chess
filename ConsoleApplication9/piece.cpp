#include "stdafx.h"
#include "piece.h"
#include<string>
//File declaring functions used in piece class


//Default constructor
piece::piece()
{
	this->firstMove = true;
	this->pieceName = ' ';
	this->player = 0;
}

//Parameterised constructor
piece::piece(char _name, const int _player) {
	this->firstMove = true;
	this->pieceName = _name;
	this->player = _player;
}

//Default destructor
piece::~piece()
{
}

//Getter for piecename variable
char piece::getPieceName() {
	if (player == 2) {
		return tolower(pieceName);
	}
	else { return pieceName; }
}

//Getter for player variable
int piece::getPlayer() {
	return player;
}

//Setter for firstmove variable
void piece::setFirstMove(bool _firstMove) {
	firstMove = _firstMove;
}

bool piece::getFirstMove() {
	return firstMove;
}