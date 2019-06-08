#include "stdafx.h"
#include "queen.h"
#include <vector>
#include "board.h"
//File defining functions declared in queen class


//Declaring global variable used in main function
extern board board1;

//Default constructor
queen::queen()
{
}

//Parameterised constructor
queen::queen(const int _player) {
	this->player = _player;
	this->pieceName = 'Q';
}

//Default destructor
queen::~queen()
{
}


//#########################################################################################
//Returning a vector containing all possible final positions for Queen.
//Effectively bombines the way you look for moves for rook and bishop.
//#########################################################################################
vector< vector<int> > queen::getPossibleMoves(const int initalRow,const int initalCol) {
	vector< vector<int> > possibleMoves;

	//Queen is effectively rook + bishop

	//Rook Moves


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
	//End of Rook Moves



	//Start of bishop moves
	pieceObstructing = false;
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
