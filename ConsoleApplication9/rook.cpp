#include "stdafx.h"
#include "rook.h"
#include <vector>
#include "board.h"
//File declaring functions used in rook class

//Declaring global variable used in main function
extern board board1;
rook::rook()
{
}

rook::rook(const int _player) {
	this->player = _player;
	this->pieceName = 'R';
}


rook::~rook()
{
}


//#########################################################################################
//Returning a vector containing all possible final positions for Rook.
//Effectively search in each direction until the end of the board.
//If you hit a piece, and its not your own, you can capture it.
//If it isn't your own, you can move up to it.
//#########################################################################################
vector< vector<int> > rook::getPossibleMoves(const int initalRow,const int initalCol) {
	vector< vector<int> > possibleMoves;
	bool pieceObstructing = false;
	for (int i = 1; i < 8; i++) {
		//All the way to the right
		if (pieceObstructing == false) {
			if (initalCol + i < 8) {
				//Look at the square
				//Is it empty??

				if (board1(initalRow, initalCol + i).getPieceOnSquare() == nullptr) {
					//It IS empty! Lets add it to the list
					vector<int> pos{ initalRow,initalCol + i };
					possibleMoves.push_back(pos);

				}
				else {
					//Ah it contains a piece...
					//But is it one of their pieces!?
					if (board1(initalRow, initalCol + i).getPieceOnSquare()->getPlayer() !=
						board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

						vector<int> pos{ initalRow,initalCol + i };

						possibleMoves.push_back(pos);

						pieceObstructing = true;
					}
					else {
						pieceObstructing = true;
					}
				}
			}
		}
	}
	pieceObstructing = false;
	for (int i = 1; i < 8; i++) {
		//All the way to the left
		if (pieceObstructing == false) {
			if (initalCol - i > -1) {
				//Look at the square
				//Is it empty??
				if (board1(initalRow, initalCol - i).getPieceOnSquare() == nullptr) {
					//It IS empty! Lets add it to the list
					vector<int> pos{ initalRow,initalCol - i };

					possibleMoves.push_back(pos);

				}
				else {
					//Ah it contains a piece...
					//But is it one of their pieces!?
					if (board1(initalRow, initalCol - i).getPieceOnSquare()->getPlayer() !=
						board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

						vector<int> pos{ initalRow,initalCol - i };

						possibleMoves.push_back(pos);
						pieceObstructing = true;
					}
					else {
						pieceObstructing = true;
					}
				}
			}
		}
	}

	pieceObstructing = false;
	for (int i = 1; i < 8; i++) {
		//All the way up
		if (pieceObstructing == false) {
			if (initalRow + i < 8) {
				//Look at the square
				//Is it empty??
				if (board1(initalRow + i, initalCol).getPieceOnSquare() == nullptr) {
					//It IS empty! Lets add it to the list
					vector<int> pos{ initalRow + i,initalCol };

					possibleMoves.push_back(pos);

				}
				else {
					//Ah it contains a piece...
					//But is it one of their pieces!?
					if (board1(initalRow + i, initalCol).getPieceOnSquare()->getPlayer() !=
						board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

						vector<int> pos{ initalRow + i,initalCol };

						possibleMoves.push_back(pos);

						pieceObstructing = true;
					}
					else {
						pieceObstructing = true;
					}
				}
			}
		}
	}
	pieceObstructing = false;
	for (int i = 1; i < 8; i++) {
		//All the way down
		if (pieceObstructing == false) {
			if (initalRow - i > -1) {


				if (board1(initalRow - i, initalCol).getPieceOnSquare() == nullptr) {
					//It IS empty! Lets add it to the list
					vector<int> pos{ initalRow - i,initalCol };

					possibleMoves.push_back(pos);

				}
				else {
					//Ah it contains a piece...
					//But is it one of their pieces!?
					if (board1(initalRow - i, initalCol).getPieceOnSquare()->getPlayer() !=
						board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

						vector<int> pos{ initalRow - i,initalCol };

						possibleMoves.push_back(pos);

						pieceObstructing = true;
					}
					else {
						pieceObstructing = true;
					}
				}
			}
		}
	}
	return possibleMoves;
}