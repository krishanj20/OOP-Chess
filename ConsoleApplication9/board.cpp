#include "stdafx.h"
#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include<iostream>
#include<memory>

extern board board1;

//Default constructor
board::board()
{
}

//Destructor
board::~board()
{
	//Cleanup pointers remaining on board
	//if there is a piece on a position on the board, delete this piece.
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//update display board pieces to match the real board
			if (theBoard[i][j].getPieceOnSquare() != nullptr) {
				delete theBoard[i][j].getPieceOnSquare();
			}
		}
	}
}


//#########################################################################################
//Positions the pieces on the board
//Using new and parametised constructors
//Use try and catch to check for good memory allocation
//#########################################################################################
void board::start() {
	try {
		//Pieces for player 1
		theBoard[0][0].setPieceOnSquare(new rook(1));
		theBoard[0][1].setPieceOnSquare(new knight(1));
		theBoard[0][2].setPieceOnSquare(new bishop(1));
		theBoard[0][3].setPieceOnSquare(new queen(1));
		theBoard[0][4].setPieceOnSquare(new king(1));
		theBoard[0][5].setPieceOnSquare(new bishop(1));
		theBoard[0][6].setPieceOnSquare(new knight(1));
		theBoard[0][7].setPieceOnSquare(new rook(1));

		theBoard[1][0].setPieceOnSquare(new pawn(1));
		theBoard[1][1].setPieceOnSquare(new pawn(1));
		theBoard[1][2].setPieceOnSquare(new pawn(1));
		theBoard[1][3].setPieceOnSquare(new pawn(1));
		theBoard[1][4].setPieceOnSquare(new pawn(1));
		theBoard[1][5].setPieceOnSquare(new pawn(1));
		theBoard[1][6].setPieceOnSquare(new pawn(1));
		theBoard[1][7].setPieceOnSquare(new pawn(1));


		//Pieces for player 2
		theBoard[7][0].setPieceOnSquare(new rook(2));
		theBoard[7][1].setPieceOnSquare(new knight(2));
		theBoard[7][2].setPieceOnSquare(new bishop(2));
		theBoard[7][3].setPieceOnSquare(new queen(2));
		theBoard[7][4].setPieceOnSquare(new king(2));
		theBoard[7][5].setPieceOnSquare(new bishop(2));
		theBoard[7][6].setPieceOnSquare(new knight(2));
		theBoard[7][7].setPieceOnSquare(new rook(2));


		theBoard[6][0].setPieceOnSquare(new pawn(2));
		theBoard[6][1].setPieceOnSquare(new pawn(2));
		theBoard[6][2].setPieceOnSquare(new pawn(2));
		theBoard[6][3].setPieceOnSquare(new pawn(2));
		theBoard[6][4].setPieceOnSquare(new pawn(2));
		theBoard[6][5].setPieceOnSquare(new pawn(2));
		theBoard[6][6].setPieceOnSquare(new pawn(2));
		theBoard[6][7].setPieceOnSquare(new pawn(2));
	}
	catch (bad_alloc memFail)
	{
		//If there is a problem with memory allocation, it will be caught here
		cout << "Memory Allocation problem!" << endl;
	}

	
}


//#########################################################################################
//A displayboard, uses chars to display the pieces on the board
//#########################################################################################
void board::display() {

	char displayBoard[38][53] = {

	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', '8', ' ', '|', ' ', ' ', 'R', ' ', ' ', '|', ' ', ' ', 'N', ' ', ' ', '|', ' ', ' ', 'B', ' ', ' ', '|', ' ', ' ', 'Q', ' ', ' ', '|', ' ', ' ', 'K', ' ', ' ', '|', ' ', ' ', 'B', ' ', ' ', '|', ' ', ' ', 'N', ' ', ' ', '|', ' ', ' ', 'R', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', '7', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', '6', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', '5', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', '4', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', '3', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', '2', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', '1', ' ', '|', ' ', ' ', 'R', ' ', ' ', '|', ' ', ' ', 'N', ' ', ' ', '|', ' ', ' ', 'B', ' ', ' ', '|', ' ', ' ', 'Q', ' ', ' ', '|', ' ', ' ', 'K', ' ', ' ', '|', ' ', ' ', 'B', ' ', ' ', '|', ' ', ' ', 'N', ' ', ' ', '|', ' ', ' ', 'R', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
	{ ' ', ' ', ' ', ' ', '|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|' },


	};
	//Each position on the vector corresponds to what character along the position is
	const int rows[8] = { 31,27,23,19,15,11,7,3 };
	const int columns[8] = { 7,13,19,25,31,37,43,49 };

	//updates real piece locations on the "display board"
	for (int i = 0; i < 8; i++) {
		//Positions of the rows
		int row = rows[i];

		for (int j = 0; j < 8; j++) {

			int col = columns[j];
			//update display board pieces to match the real board
			if (theBoard[i][j].getPieceOnSquare() == nullptr)
				displayBoard[row][col] = ' ';
			else
				displayBoard[row][col] = theBoard[i][j].getPieceOnSquare()->getPieceName();

		}
	}



	//Showing the board on console
	for (int i = 0; i < 34; i++) {
		cout << endl;
		for (int j = 0; j < 53; j++) {
			cout << displayBoard[i][j];
		}
	}
	cout << endl << endl;
}

//#########################################################################################
//Returns an integer corresponding to the player that piece belongs to
//#########################################################################################
int board::getPiecePlayer(const int intialRow,const int initalCol) {
	if (theBoard[intialRow][initalCol].getPieceOnSquare() != nullptr) {
		return theBoard[intialRow][initalCol].getPieceOnSquare()->getPlayer();
	}
	else {
		return 3;
	}
}

//#########################################################################################
//Function which returns all possible moves on board (besides the king).
//King is essentially not required here, as it is being used to compute check and checkmate, and the king can never put itself in danger.
//In other words, it is not an offensive piece
//It stores these moves as a vector of vectors. 
//the style of each vector is:
//{finalrow,finalcol,initalrow, initalcol}
//#########################################################################################
std::vector< std::vector<int> > board::getOppoPossibleMoves(const int player) {
	std::vector< std::vector<int> > allPossibleMoves;
	//Iterate through squares on the board
	for (auto i = 0; i < 8; i++) {
		for (auto j = 0; j < 8; j++) {
			//If the square constains a piece
			if (theBoard[i][j].getPieceOnSquare() != nullptr) {
				//If the piece is not one of our own
				if (theBoard[i][j].getPieceOnSquare()->getPlayer() != player && tolower(theBoard[i][j].getPieceOnSquare()->getPieceName()) != 'k') {
					//GetPossibleMoves
					std::vector< std::vector<int> > piecePossibleMoves = theBoard[i][j].getPieceOnSquare()->getPossibleMoves(i, j);
					//for each vector in possiblemoves
					for (unsigned int k = 0; k < piecePossibleMoves.size(); k++) {
						//push_back initalrow
						piecePossibleMoves[k].push_back(i);
						//push_back initalcol
						piecePossibleMoves[k].push_back(j);
					}

					//Piecepossiblemoves has order [0] finalrow [1] finalcol [2] initalRow [3] initalcol

					//Add getPossibleMoves to AllPossiblemoves
					allPossibleMoves.insert(allPossibleMoves.end(), piecePossibleMoves.begin(), piecePossibleMoves.end());
				}
			}
		}
	}
	return allPossibleMoves;

}

//#########################################################################################
//Function which checks if player is in check
//It checks if the kings position is in allPossibleMoves.
//If it is, then function returns true.
//#########################################################################################
bool board::check(vector< vector<int> > allPossibleMoves,const int player) {
	for (auto i = 0; i < 8; i++) {
		for (auto j = 0; j < 8; j++) {
			//If the square constains a piece
			if (theBoard[i][j].getPieceOnSquare() != nullptr) {
				//If the piece is  our own and IS a king
				if (theBoard[i][j].getPieceOnSquare()->getPlayer() == player && tolower(theBoard[i][j].getPieceOnSquare()->getPieceName()) == 'k') {
					//Iterate through allpossiblemoves. Is the king position in this list? If so its check!
					for (unsigned int k = 0; k < allPossibleMoves.size(); k++) {
						if (allPossibleMoves[k][0] == i && allPossibleMoves[k][1] == j) {
							//damn we got check boi
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}


//#########################################################################################
//Calculates checkmate for a piece
//gets all the moves you can do
//Does any of these moves mean it is no longer check? 
//If such a move exists, then you're not in checkmate.
//It checks this by moving the piece from initial to final, then computing check
//#########################################################################################
bool board::checkmate(int player, vector< vector<int> > YourPossibleMoves) {
	for (auto i = 0; i < 8; i++) {
		for (auto j = 0; j < 8; j++) {
			//If the square constains a piece
			if (theBoard[i][j].getPieceOnSquare() != nullptr) {
				//If the piece is  our own and IS a king
				if (theBoard[i][j].getPieceOnSquare()->getPlayer() == player && tolower(theBoard[i][j].getPieceOnSquare()->getPieceName()) == 'k') {
					//Find out all the kings possible moves
					vector< vector<int> >possibleMoves = theBoard[i][j].getPieceOnSquare()->getPossibleMoves(i,j);
					if (possibleMoves.size() == 0) {

						//King cannot get away

						//Go through each item on allpossiblemoves
						for (unsigned int i = 0; i < YourPossibleMoves.size(); i++) {
							int initalRow = YourPossibleMoves[i][2];
							int initalCol = YourPossibleMoves[i][3];
							int finalRow = YourPossibleMoves[i][0];
							int finalCol = YourPossibleMoves[i][1];
							//Move the piece from inital to final position

							//Store the initial and final pieces, then move the piece, so we can revert the move if required

							//~
							piece * initalpiece = theBoard[initalRow][initalCol].getPieceOnSquare();
							piece * finalpiece = theBoard[finalRow][finalCol].getPieceOnSquare();


							theBoard[finalRow][finalCol].setPieceOnSquare(initalpiece);
							theBoard[initalRow][initalCol].setPieceOnSquare(nullptr);
							//~


							//If one of these moves stops check, then checkmate is false
							//need to recompute allpossiblemoves
							vector< vector<int> > allPossibleMoves = board1.getOppoPossibleMoves(player);
							if (!board1.check(allPossibleMoves, player)) {
								theBoard[finalRow][finalCol].setPieceOnSquare(finalpiece);
								theBoard[initalRow][initalCol].setPieceOnSquare(initalpiece);
								return false;
							}
							//Move the piece back
							theBoard[finalRow][finalCol].setPieceOnSquare(finalpiece);
							theBoard[initalRow][initalCol].setPieceOnSquare(initalpiece);
						}
						//If no move exists that gets the king away, it is checkmate.
						return true;
					}

				}
			}
		}
	}
	return false;
}


//#########################################################################################
//Overloaded function allowing () to return the square on the board
//#########################################################################################
square board::operator()(const int initalRow, const int initalCol) {
	return theBoard[initalRow][initalCol];
}



//#########################################################################################
//Shallow moves the piece from inital square to final square
//THis is because we want the same 'piece' just on a different square
//#########################################################################################
void board::movePiece(const int intialRow,const int initalCol,const int finalRow,const int finalCol) {

	//Delete the piece that is being taken
	if (theBoard[finalRow][finalCol].getPieceOnSquare() != nullptr) {
		delete theBoard[finalRow][finalCol].getPieceOnSquare();
	}

	theBoard[finalRow][finalCol].setPieceOnSquare(theBoard[intialRow][initalCol].getPieceOnSquare());
	theBoard[intialRow][initalCol].setPieceOnSquare(nullptr);
}


//#########################################################################################
//promotion checks if piece that has moved is a pawn, and if the pawn has made it to the other side of the board.
//If the piece has, it is converted to a queen.
//#########################################################################################
void board::promotion(const int finalRow,const int finalCol) {
	if (tolower(theBoard[finalRow][finalCol].getPieceOnSquare()->getPieceName()) == 'p') {
		int player = theBoard[finalRow][finalCol].getPieceOnSquare()->getPlayer();
		if (player == 1) //going up the board
		{
			//If the piece has made it the finalRow
			if (finalRow == 7) {
				delete theBoard[finalRow][finalCol].getPieceOnSquare();
				//theBoard[finalRow][finalCol].setPieceOnSquare(nullptr);
				theBoard[finalRow][finalCol].setPieceOnSquare(new queen(1));
			}
		}
		else if (player == 2) {
			//If the piece has made it the finalRow
			if (finalRow == 0) {
				delete theBoard[finalRow][finalCol].getPieceOnSquare();
				//theBoard[finalRow][finalCol].setPieceOnSquare(nullptr);
				theBoard[finalRow][finalCol].setPieceOnSquare(new queen(1));
			}
		}
	}
}