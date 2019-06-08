#pragma once
#include <vector>
#include "square.h"
#include "piece.h"

//This is the board class
//it will initialise the board as well as store the current state in an array of arrays of type 'square'

class board
{
private:
	square theBoard[8][8]; //This is the 8x8 board RUNNING FROM 0 TO 7 in index!
public:
	board(); //Default constructor should produce an empty board

	//Start fills the board with the default layout of pieces
	void start(); 

	//displays the board on the terminal
	void display();

	//Get pieceplayer protects against trying to find what player a blank piece on the board is!
	int getPiecePlayer(const int intialRow, const int initalCol);

	//This overloaded operator is simply a getter for the private square variable on theBoard
	square operator()(const int initalRow, const int initalCol);

	//This gets all possible moves for opponent
	std::vector< std::vector<int> > getOppoPossibleMoves(int player);

	//This returns whether the player is in check
	bool check(vector< vector<int> > allPossibleMoves,const int player);

	//This returns whether the player is in checkmate
	bool checkmate(const int player, vector< vector<int> > yourPossibleMoves);

	//This shallow moves a piece from the initial to final position
	void movePiece(const int intialRow, const int initalCol,const int finalRow,const int finalCol);

	//This checks if pawn on board can be promoted
	void promotion(const int finalRow,const int finalCol);

	~board(); // destructor
};



