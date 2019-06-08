#pragma once
//Pragma once does the same thing as include guards
#include<string>
#include<vector>
#include <iostream>

using namespace std;
//Piece class
//This will be overloaded with finctions for each spiecific piece in the future.
//This is the generic class for the pieces in the game.

class piece
{
protected:
	char pieceName; //Contains the name of the piece
	int player; //Stores which player the piece belongs to
	bool firstMove; //This would be required for the king and rook (Castling)
					//It is also required for the pawn.

public:
	//Default constructor
	piece();
	//parameterised constructor
	piece(const char _name,const int _player);
	//virtual destructor to stop memory leaks
	virtual ~piece();
	//Getter for piecename variable
	char getPieceName();
	//Virtual function which will return possible moves in each of the child classes.
	virtual vector< vector<int> > getPossibleMoves(const int initalRow,const int initalCol) = 0;
	//Setter for firstMove
	void setFirstMove(bool _firstMove);

	//getter for firstmove
	bool getFirstMove();
	//Getter for player
	int getPlayer();
};


