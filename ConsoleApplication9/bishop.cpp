#include "stdafx.h"
#include "bishop.h"
#include <vector>
#include "board.h"
//Functions for bishop class

//Declaring global variable used in main function
extern board board1;

//Default constructor
bishop::bishop()
{
}

//Parameterised constructor
bishop::bishop(const int _player) {
	this->player = _player;
	this->pieceName = 'B';
}

//Destructor
bishop::~bishop()
{
}


//#########################################################################################
//Returning a vector containing all possible final positions for Bishop.
//Effectively search in each diagonal direction until the end of the board.
//If you hit a piece, and its not your own, you can capture it.
//If it isn't your own, you can move up to it.
//#########################################################################################
vector< vector<int> > bishop::getPossibleMoves(const int initalRow,const int initalCol) {
	vector< vector<int> > possibleMoves;
	bool pieceObstructing = false;
	for (int i = 1; i < 8; i++) {
		//All the way to the top right
		if (pieceObstructing == false) {
			if (initalCol + i < 8 && initalRow + i <8) {
				//Look at the square
				//Is it empty??

				if (board1(initalRow + i, initalCol + i).getPieceOnSquare() == nullptr) {
					//It IS empty! Lets add it to the list
					vector<int> pos{ initalRow + i,initalCol + i };

					possibleMoves.push_back(pos);

				}
				else {
					//Ah it contains a piece...
					//But is it one of their pieces!?
					if (board1(initalRow + i, initalCol + i).getPieceOnSquare()->getPlayer() !=
						board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

						vector<int> pos{ initalRow + i,initalCol + i };

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

	//Going to top left

	pieceObstructing = false;
	for (int i = 1; i < 8; i++) {
		//All the way to the left
		if (pieceObstructing == false) {
			if (initalCol - i > -1 && initalRow + i< 8) {
				//Look at the square
				//Is it empty??
				if (board1(initalRow + i, initalCol - i).getPieceOnSquare() == nullptr) {
					//It IS empty! Lets add it to the list
					vector<int> pos{ initalRow + i,initalCol - i };

					possibleMoves.push_back(pos);
				}
				else {
					//Ah it contains a piece...
					//But is it one of their pieces!?
					if (board1(initalRow + i, initalCol - i).getPieceOnSquare()->getPlayer() !=
						board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

						vector<int> pos{ initalRow + i,initalCol - i };

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

	for (int i = 1; i < 8; i++) {
		//All the way to the bottom right
		if (pieceObstructing == false) {
			if (initalCol + i < 8 && initalRow - i > -1) {
				//Look at the square
				//Is it empty??

				if (board1(initalRow - i, initalCol + i).getPieceOnSquare() == nullptr) {
					//It IS empty! Lets add it to the list
					vector<int> pos{ initalRow - i,initalCol + i };

					possibleMoves.push_back(pos);
					
				}
				else {
					//Ah it contains a piece...
					//But is it one of their pieces!?
					if (board1(initalRow - i, initalCol + i).getPieceOnSquare()->getPlayer() !=
						board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

						vector<int> pos{ initalRow - i,initalCol + i };

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

	//Going to bottom left

	pieceObstructing = false;
	for (int i = 1; i < 8; i++) {
		if (pieceObstructing == false) {
			if (initalCol - i > -1 && initalRow - i > -1) {
				//Look at the square
				//Is it empty??
				if (board1(initalRow - i, initalCol - i).getPieceOnSquare() == nullptr) {
					//It IS empty! Lets add it to the list
					vector<int> pos{ initalRow - i,initalCol - i };

					possibleMoves.push_back(pos);

				}
				else {
					//Ah it contains a piece...
					//But is it one of their pieces!?
					if (board1(initalRow - i, initalCol - i).getPieceOnSquare()->getPlayer() !=
						board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {

						vector<int> pos{ initalRow - i,initalCol - i };

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

