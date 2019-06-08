#include "stdafx.h"
#include "knight.h"
#include <vector>
#include "board.h"

//File with functions declared in knight class 


//Declaring global variable used in main function
extern board board1;

knight::knight()
{
}

knight::knight(const int _player) {
	this->player = _player;
	this->pieceName = 'N';
}


knight::~knight()
{
}

//#########################################################################################
//Returning a vector containing all possible final positions for knight
//Just checks the possible positions for the knight to move that arent off the board.
//As long as your own piece isn't on it, its viable move.
//#########################################################################################
vector< vector<int> > knight::getPossibleMoves(const int initalRow, const int initalCol) {
	vector< vector<int> > possibleMoves;

	//Moving to left two
	if (initalCol - 2 > -1) {
		//Moving up one
		if (initalRow + 1 < 8) {
			if (board1(initalRow + 1, initalCol - 2).getPieceOnSquare() != nullptr) {
				//Square contains piece
				if (board1(initalRow + 1, initalCol - 2).getPieceOnSquare()->getPlayer() !=
					board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
					//The piece is not one of our own
					vector<int> pos{ initalRow + 1, initalCol - 2 };
					possibleMoves.push_back(pos);
				}
			}
			else {
				//Square is empty
				vector<int> pos{ initalRow + 1, initalCol - 2 };
				possibleMoves.push_back(pos);
			}
		}
		//Moving down one
		if (initalRow - 1 > 0) {
			if (board1(initalRow - 1, initalCol - 2).getPieceOnSquare() != nullptr) {
				//Square contains piece
				if (board1(initalRow - 1, initalCol - 2).getPieceOnSquare()->getPlayer() !=
					board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
					//The piece is not one of our own
					vector<int> pos{ initalRow - 1, initalCol - 2 };
					possibleMoves.push_back(pos);
				}
			}
			else {
				//Square is empty
				vector<int> pos{ initalRow - 1, initalCol - 2 };
				possibleMoves.push_back(pos);
			}
		}
	}


	//Moving to right two

	if (initalCol + 2 < 8) {
		//Moving up one
		if (initalRow + 1 < 8) {
			if (board1(initalRow + 1, initalCol + 2).getPieceOnSquare() != nullptr) {
				//Square contains piece
				if (board1(initalRow + 1, initalCol + 2).getPieceOnSquare()->getPlayer() !=
					board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
					//The piece is not one of our own
					vector<int> pos{ initalRow + 1, initalCol + 2 };
					possibleMoves.push_back(pos);
				}
			}
			else {
				//Square is empty
				vector<int> pos{ initalRow + 1, initalCol + 2 };
				possibleMoves.push_back(pos);
			}
		}
		//Moving down one
		if (initalRow - 1 > 0) {
			if (board1(initalRow - 1, initalCol + 2).getPieceOnSquare() != nullptr) {
				//Square contains piece
				if (board1(initalRow - 1, initalCol + 2).getPieceOnSquare()->getPlayer() !=
					board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
					//The piece is not one of our own
					vector<int> pos{ initalRow - 1, initalCol + 2 };
					possibleMoves.push_back(pos);
				}
			}
			else {
				//Square is empty
				vector<int> pos{ initalRow - 1, initalCol + 2 };
				possibleMoves.push_back(pos);
			}
		}
	}

	//Moving up two
	if (initalRow + 2 < 8) {
		//Moving right one
		if (initalCol + 1 < 8) {
			if (board1(initalRow + 2, initalCol + 1).getPieceOnSquare() != nullptr) {
				//Square contains piece
				if (board1(initalRow + 2, initalCol + 1).getPieceOnSquare()->getPlayer() !=
					board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
					//The piece is not one of our own
					vector<int> pos{ initalRow + 2, initalCol + 1 };
					possibleMoves.push_back(pos);
				}
			}
			else {
				//Square is empty
				vector<int> pos{ initalRow + 2, initalCol + 1 };
				possibleMoves.push_back(pos);
			}
		}
		//Moving left one
		if (initalCol - 1 > -1) {
			if (board1(initalRow + 2, initalCol - 1).getPieceOnSquare() != nullptr) {
				//Square contains piece
				if (board1(initalRow + 2, initalCol - 1).getPieceOnSquare()->getPlayer() !=
					board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
					//The piece is not one of our own
					vector<int> pos{ initalRow + 2, initalCol - 1 };
					possibleMoves.push_back(pos);
				}
			}
			else {
				//Square is empty
				vector<int> pos{ initalRow + 2, initalCol - 1 };
				possibleMoves.push_back(pos);
			}
		}
	}

	//Moving down two
	if (initalRow - 2 > -1) {
		//Moving right one
		if (initalCol + 1 < 8) {
			if (board1(initalRow - 2, initalCol + 1).getPieceOnSquare() != nullptr) {
				//Square contains piece
				if (board1(initalRow - 2, initalCol + 1).getPieceOnSquare()->getPlayer() !=
					board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
					//The piece is not one of our own
					vector<int> pos{ initalRow - 2, initalCol + 1 };
					possibleMoves.push_back(pos);
				}
			}
			else {
				//Square is empty
				vector<int> pos{ initalRow - 2, initalCol + 1 };
				possibleMoves.push_back(pos);
			}
		}
		//Moving left one
		if (initalCol - 1 > -1) {
			if (board1(initalRow - 2, initalCol - 1).getPieceOnSquare() != nullptr) {
				//Square contains piece
				if (board1(initalRow - 2, initalCol - 1).getPieceOnSquare()->getPlayer() !=
					board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
					//The piece is not one of our own
					vector<int> pos{ initalRow - 2, initalCol - 1 };
					possibleMoves.push_back(pos);
				}
			}
			else {
				//Square is empty
				vector<int> pos{ initalRow - 2, initalCol - 1 };
				possibleMoves.push_back(pos);
			}
		}
	}

	return possibleMoves;
}