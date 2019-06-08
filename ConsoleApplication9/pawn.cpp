#include "stdafx.h"
#include "pawn.h"
#include <iostream>
#include <vector>
#include "board.h"
//File with functions declared in  Pawn class


//Declaring global variable used in main function
extern board board1;


//Default constructor
pawn::pawn()
{
}


//Parametrised constructor
pawn::pawn(const int _player) {
	player = _player;
	pieceName = 'P';
	firstMove = true;
}

//Destructor
pawn::~pawn()
{
}


//#########################################################################################
//Returning a vector containing all possible final positions for pawn.
//Checks what players piece it is, which determines whether its moving up or down
//Check piece ahead doesnt contain a piece, is it doesnt it is a viable move.
//If its the pawns first move, it checks the piece two ahead is empty.
//Also checks whether diagonals are occupied by opponents piece, if so, capturing these is also viable.
//#########################################################################################
vector< vector<int> > pawn::getPossibleMoves(const int initalRow,const int initalCol) {
	int move1, move2;
	vector<vector <int>> possibleMoves;
	if (player == 1) {
		//Player 1 can move up
		move1 = 1;
		move2 = 2;
	}
	else {
		//Player 2 can move down
		move1 = -1;
		move2 = -2;
	}

	//If its the firstmove they can move two, so append a vector with move2 added to colun
	if (this->firstMove == true) {
		if (board1(initalRow + move2, initalCol).getPieceOnSquare() == nullptr) {
			vector<int> pos{ initalRow + move2 ,initalCol };
			possibleMoves.push_back(pos);

		}
	}
	//If its not firstmove they can move 1, provided theres no pieces there
	if (board1(initalRow + move1, initalCol).getPieceOnSquare() == nullptr) {
		vector<int> pos{ initalRow + move1 ,initalCol };
		possibleMoves.push_back(pos);

	}
	//If piece on diagonal & it is not going off the board
	if (initalCol + 1 < 8) {
		if (board1(initalRow + move1, initalCol + 1).getPieceOnSquare() != nullptr) {
			//If piece is not one of your own
			if (board1(initalRow + move1, initalCol + 1).getPieceOnSquare()->getPlayer() !=
				board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

				vector<int> pos{ initalRow + move1 ,initalCol + 1 };
				possibleMoves.push_back(pos);
			}
		}
	}
	if (initalCol - 1 > -1) {
		if (board1(initalRow + move1, initalCol - 1).getPieceOnSquare() != nullptr) {
			//If piece is not one of your own
			if (board1(initalRow + move1, initalCol - 1).getPieceOnSquare()->getPlayer() !=
				board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

				vector<int> pos{ initalRow + move1 ,initalCol - 1 };
				possibleMoves.push_back(pos);
			
			}
		}
	}
	return possibleMoves;
}


