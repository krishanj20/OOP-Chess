#include "stdafx.h"
#include "board.h"
#include "piece.h"
#include "square.h"
#include "queen.h"
#include "gameFunctions.h"

using namespace std;


board board1; //global board variable

int main()
{
	//Booleans for cheack and checkmate
	bool check = false;
	bool checkmate = false;

	//Stores the number of the opposition

	int whosTurn = 1; // variable decvlaring which players turn it is, to start it is player 1's turn
	int oppo = 2;
	//Starts the game and gives an introdction
	board1.start(); 
	introduction();


	while (checkmate == false) {


		board1.display();
		bool movedone = false;
		//Boolean above checks if user has finished move, and while loop below keeps loop going until they have made a move
		while (movedone == false) {
			movedone = playTurn(whosTurn);
		}

		//Changes the player
		if (whosTurn == 1) { whosTurn = 2; }
		else { whosTurn = 1; }
		//Changes the opposition
		if (whosTurn == 1) { oppo = 2; }
		else { oppo = 1; }

		//Check for check and checkmate here
		//Variables for check and checkmate
		//Vectors to store the possible moves of the opponent and your possible moves
		std::vector< std::vector<int> > allPossibleMoves; //Stores opponents possible moves
		std::vector< std::vector<int> > yourPossibleMoves; //Stores your own
		allPossibleMoves = board1.getOppoPossibleMoves(whosTurn);
		yourPossibleMoves = board1.getOppoPossibleMoves(oppo);

		if (board1.check(allPossibleMoves, whosTurn)) {
			cout << "IT IS CHECK" << endl;
			check = true;
			checkmate = board1.checkmate(whosTurn,yourPossibleMoves);
			
			if (checkmate) {
				board1.display();
				cout << "Player " << whosTurn << " you have been checkmated!" << endl;
			}
		}

		//Check for stalemate
		if (allPossibleMoves.size() == 0) {
			cout << "It is stalemate! The person who's turn it is has no possible moves to make." << endl;
			checkmate = true;
		}

	}

	return 0;
}