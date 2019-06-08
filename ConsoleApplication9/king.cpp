#include "stdafx.h"
#include "king.h"
#include <vector>
#include "board.h"
//File with functions declared in king class.

//Declaring board1 is a global variable
extern board board1;

//Default constructor
king::king()
{
}

//Parameterised constructor
king::king(const int _player) {
	this->player = _player;
	this->pieceName = 'K';
}

//Destructor
king::~king()
{
}


//#########################################################################################
//Returning a vector containing all possible final positions for the King.
//Check one square in each direction. As long as it's not your own piece and 
//doesn't result in check, its a possible move.
//The check condition is found by iterating over allpossiblemoves and
//checking the square the king can move to is not in allpossiblemoves.
//Check checking is also done in the main function.
//#########################################################################################
vector< vector<int> > king::getPossibleMoves(const int initalRow,const int initalCol) {
	vector< vector<int> > possibleMoves;
	//Find out who the player is
	int whosTurn = board1(initalRow, initalCol).getPieceOnSquare()->getPlayer();
	bool checkSquare = false;

	//Should probably possiblemoves for opponent
	std::vector< std::vector<int> > allPossibleMoves = board1.getOppoPossibleMoves(whosTurn);

	//Check each move doesnt move into an opponents possiblemoves

	//Position one up
	//if position is one up is not off board
	if (initalRow + 1 < 8) {
		//if it doesnt contain a piece
		if (board1(initalRow + 1, initalCol).getPieceOnSquare() == nullptr) {
			vector<int> pos{ initalRow + 1 ,initalCol };
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is in all possiblemoves
				if (allPossibleMoves[i][0] == initalRow + 1 && allPossibleMoves[i][1] == initalCol) {
					checkSquare = true;
					
				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}

		}
		//Or if it does, and that piece isnt one of your own
		else if (board1(initalRow + 1, initalCol).getPieceOnSquare()->getPlayer() !=
			board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
			vector<int> pos{ initalRow + 1 ,initalCol };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow + 1 && allPossibleMoves[i][1] == initalCol) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
	}

	//Position one up one to the right
	if (initalRow + 1 < 8 && initalCol + 1 < 8) {
		//if it doesnt contain a piece
		if (board1(initalRow + 1, initalCol + 1).getPieceOnSquare() == nullptr) {
			checkSquare = false;
			vector<int> pos{ initalRow + 1 ,initalCol + 1 };
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow + 1 && allPossibleMoves[i][1] == initalCol + 1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
		//Or if it does, and that piece isnt one of your own
		else if (board1(initalRow + 1, initalCol + 1).getPieceOnSquare()->getPlayer() !=
			board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
			vector<int> pos{ initalRow + 1 ,initalCol + 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow + 1 && allPossibleMoves[i][1] == initalCol +1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
	}

	//Position right one
	//if position is one up is not off board
	if (initalCol + 1 < 8) {
		//if it doesnt contain a piece
		if (board1(initalRow, initalCol + 1).getPieceOnSquare() == nullptr) {
			vector<int> pos{ initalRow ,initalCol + 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow && allPossibleMoves[i][1] == initalCol + 1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}

		}
		//Or if it does, and that piece isnt one of your own
		else if (board1(initalRow, initalCol + 1).getPieceOnSquare()->getPlayer() !=
			board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
			vector<int> pos{ initalRow,initalCol + 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow && allPossibleMoves[i][1] == initalCol +1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
	}

	//Position one down one to the right
	if (initalRow - 1 >-1 && initalCol + 1 < 8) {
		//if it doesnt contain a piece
		if (board1(initalRow - 1, initalCol + 1).getPieceOnSquare() == nullptr) {
			vector<int> pos{ initalRow - 1 ,initalCol + 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow - 1 && allPossibleMoves[i][1] == initalCol + 1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
		//Or if it does, and that piece isnt one of your own
		else if (board1(initalRow - 1, initalCol + 1).getPieceOnSquare()->getPlayer() !=
			board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
			vector<int> pos{ initalRow - 1 ,initalCol + 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is NOT in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow - 1 && allPossibleMoves[i][1] == initalCol + 1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
	}
	//Position one down
	//if position is one up is not off board
	if (initalRow - 1 > -1) {
		//if it doesnt contain a piece
		if (board1(initalRow - 1, initalCol).getPieceOnSquare() == nullptr) {
			vector<int> pos{ initalRow - 1 ,initalCol };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is NOT in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow - 1 && allPossibleMoves[i][1] == initalCol) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
		//Or if it does, and that piece isnt one of your own
		else if (board1(initalRow - 1, initalCol).getPieceOnSquare()->getPlayer() !=
			board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
			vector<int> pos{ initalRow - 1 ,initalCol };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is NOT in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow - 1 && allPossibleMoves[i][1] == initalCol) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
	}

	//Position one down one to the left
	if (initalRow - 1 >-1 && initalCol - 1 >-1) {
		//if it doesnt contain a piece
		if (board1(initalRow - 1, initalCol - 1).getPieceOnSquare() == nullptr) {
			vector<int> pos{ initalRow - 1 ,initalCol - 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is NOT in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow - 1 && allPossibleMoves[i][1] == initalCol -1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
		//Or if it does, and that piece isnt one of your own
		else if (board1(initalRow - 1, initalCol - 1).getPieceOnSquare()->getPlayer() !=
			board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
			vector<int> pos{ initalRow - 1 ,initalCol - 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is NOT in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow - 1 && allPossibleMoves[i][1] == initalCol -1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
	}

	//Position left one
	//if position is one up is not off board
	if (initalCol - 1 > -1) {
		//if it doesnt contain a piece
		if (board1(initalRow, initalCol - 1).getPieceOnSquare() == nullptr) {
			vector<int> pos{ initalRow ,initalCol - 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow + 1 && allPossibleMoves[i][1] == initalCol -1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
		//Or if it does, and that piece isnt one of your own
		else if (board1(initalRow, initalCol - 1).getPieceOnSquare()->getPlayer() !=
			board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
			vector<int> pos{ initalRow,initalCol - 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is NOT in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow && allPossibleMoves[i][1] == initalCol -1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
	}

	//Position one up one to the left
	if (initalRow + 1 <8 && initalCol - 1 >-1) {
		//if it doesnt contain a piece
		if (board1(initalRow + 1, initalCol - 1).getPieceOnSquare() == nullptr) {
			vector<int> pos{ initalRow + 1 ,initalCol - 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is NOT in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow + 1 && allPossibleMoves[i][1] == initalCol -1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
		//Or if it does, and that piece isnt one of your own
		else if (board1(initalRow + 1, initalCol - 1).getPieceOnSquare()->getPlayer() !=
			board1(initalRow, initalCol).getPieceOnSquare()->getPlayer()) {
			vector<int> pos{ initalRow + 1 ,initalCol - 1 };
			checkSquare = false;
			for (unsigned int i = 0; i < allPossibleMoves.size(); i++) {
				//If this position is NOT in allpossiblemoves
				if (allPossibleMoves[i][0] == initalRow + 1 && allPossibleMoves[i][1] == initalCol -1) {
					checkSquare = true;

				}

			}
			if (checkSquare == false) {
				possibleMoves.push_back(pos);
			}
		}
	}

	return possibleMoves;
}
