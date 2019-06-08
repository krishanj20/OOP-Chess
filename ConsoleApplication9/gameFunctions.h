#pragma once
#include "stdafx.h"
#include "board.h"
#include "piece.h"
#include "square.h"
#include "queen.h"
#include "gameFunctions.h"
#include <iostream>  
#include <algorithm>
//This is a function containing all functions utilised in the main portion of the code.

//External decalaration to global board varible
extern board board1;

//Forward declaration of functions, properly defined later in the header file
void introduction();
bool playTurn(int _whosTurn);
bool validateInput(std::string input);
int letterToColumn(std::string letter);
void printAllMoves(vector< vector<int> > possibleMoves);
std::string columnToLetter(int column);

using namespace std;

//#########################################################################################
//Introduction is the function that is run upon startup. 
//It shows a title, then 'Press enter to start',then the instructions outlining the meaning of each letter on the board
//#########################################################################################
void introduction() {
	cout << "#########################################" << endl;
	cout << "##                                     ##" << endl;
	cout << "## ##### #   # ######  ####### ####### ##" << endl;
	cout << "## #     #   # #       #       #       ##" << endl;
	cout << "## #     ##### ######  ####### ####### ##" << endl;
	cout << "## #     #   # #             #       # ##" << endl;
	cout << "## ##### #   # ######  ####### ####### ##" << endl;
	cout << "##                                     ##" << endl;
	cout << "#########################################" << endl << endl;

	cout << "Welcome to chess!" << endl << endl;
	cout << "Press [enter] to start" << endl << endl;

	//Waits for user input
	std::cin.ignore();

	//Prints instructions
	cout << "Player one, you are the white pieces. You start, and your pieces are the capital letters" << endl;
	cout << "Each piece is identified by the letters:" << endl;
	cout << "[P]awn, [R]ook, [B]ishop, K[N]ight, [Q]ueen, [K]ing" << endl;
}




//#########################################################################################
//Playturn is used each turn. 
//It takes the users initial position, and finds the piece on it.
//It then asks for where you would like to move your chosen piece
//It also contains the castling area, which is a separate set of questions etc
//#########################################################################################
bool playTurn(const int _whosTurn) {

	//Local Variable declaration for the function

	//Strings to take in user input
	std::string initalPos, finalPos;


	//Booleans for checking the input is of the correct form and is the correct piece
	bool inputCorrect{ false };
	bool pieceCorrect{ false };


	//Variables storing the initial and final positions of the piece
	int initialColumn, initalRow, finalColumn, finalRow;


	//A vector of vectors storing the possible moves for the chosen piece
	vector< vector<int> > possibleMoves;
	vector< vector<int> > allPossibleMoves = board1.getOppoPossibleMoves(_whosTurn);


	cout << "It is player " << _whosTurn << "'s turn!" << endl;

	//Start getting the input for inital position
	while (!inputCorrect || !pieceCorrect ) {

		//needs to be redefined as false here in case user inputs correct format but no valid piece on that square
		inputCorrect = false;

		cout << endl;
		//Ask for input from user, and put into lowercase form
		cout << "What piece would you like to move?" << endl;
		cout << "If you would like to perform castling, please type 'castling'" << endl;
		cin >> initalPos;
		cout << endl;
		std::transform(initalPos.begin(), initalPos.end(), initalPos.begin(), ::tolower);




		//#########################################################################################
		//START OF CASTLING
		//check king and rook havent moved, and the fina positions are not vulnerable
		//Used find here instead of usual interation for some variety
		//#########################################################################################
		if (initalPos == "castling") {
			//Player 1
			string whichRook;
			if (_whosTurn == 1) {
				//Check if king at inital pos
				if (board1(0, 4).getPieceOnSquare() != nullptr) {
					if (board1(0, 4).getPieceOnSquare()->getPieceName() == 'K' && board1(0, 4).getPieceOnSquare()->getFirstMove() == true) {
						//The king has not moved, has the rook moved?

						//Bottom left
						if (board1(0, 0).getPieceOnSquare() != nullptr) {
							if (board1(0, 0).getPieceOnSquare()->getPieceName() == 'R' && board1(0, 0).getPieceOnSquare()->getFirstMove() == true) {
								//the rook hasnt moved either.
								//are all the squares in betweem free?
								if (board1(0, 1).getPieceOnSquare() == nullptr  && board1(0, 2).getPieceOnSquare() == nullptr && board1(0, 3).getPieceOnSquare() == nullptr) {
									//are the squares in oppopossiblemoves?
									vector<int> position1 = { 0,2 };
									vector<int> position2 = { 0,3 };
									vector<int> position3 = { 0,4 };
									vector<vector<int>>::iterator isvalid1 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position1);
									vector<vector<int>>::iterator isvalid2 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position2);
									vector<vector<int>>::iterator isvalid3 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position3);

									if (isvalid1 == allPossibleMoves.end() && isvalid2 == allPossibleMoves.end() && isvalid3 == allPossibleMoves.end()) {
										//allpositions are available
										cout << "swap with bottom left rook?" << endl;
										cin >> whichRook;
										std::transform(whichRook.begin(), whichRook.end(), whichRook.begin(), ::tolower);
										
										//transform to lower
										if (whichRook == "y") {
											//set rooks firstmove to false
											board1(0, 0).getPieceOnSquare()->setFirstMove(false);
											//move rook
											board1.movePiece(0, 0, 0, 3);
											//sets kings firstmove to false
											board1(0, 4).getPieceOnSquare()->setFirstMove(false);
											//move king
											board1.movePiece(0, 4, 0, 2);

											return true;
										}

									}
									else {
										cout << "Castling to bottom left rook not possible" << endl;
									}

								}
								else {
									cout << "Castling to bottom left rook not possible" << endl;
								}

							}
							else {
								cout << "Castling to bottom left rook not possible" << endl;
							}
						}

						//END OF BOTTOM LEFT 

						//Bottom right
						if (board1(0, 7).getPieceOnSquare() != nullptr) {
							if (board1(0, 7).getPieceOnSquare()->getPieceName() == 'R' && board1(0, 7).getPieceOnSquare()->getFirstMove() == true) {
								//the rook hasnt moved either.
								//are all the squares in betweem free?
								if (board1(0, 6).getPieceOnSquare() == nullptr  && board1(0, 5).getPieceOnSquare() == nullptr) {
									//are the squares in oppopossiblemoves?
									vector<int> position1 = { 0,6 };
									vector<int> position2 = { 0,5 };
									vector<int> position3 = { 0,4 };
									vector<vector<int>>::iterator isvalid1 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position1);
									vector<vector<int>>::iterator isvalid2 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position2);
									vector<vector<int>>::iterator isvalid3 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position3);

									if (isvalid1 == allPossibleMoves.end() && isvalid2 == allPossibleMoves.end() && isvalid3 == allPossibleMoves.end()) {
										//allpositions are available
										cout << "swap with bottom right rook?" << endl;
										cin >> whichRook;
										std::transform(whichRook.begin(), whichRook.end(), whichRook.begin(), ::tolower);

										//transform to lower
										if (whichRook == "y") {
											//set rooks firstmove to false
											board1(0, 7).getPieceOnSquare()->setFirstMove(false);
											//move rook
											board1.movePiece(0, 7, 0, 5);
											//set kings firstmove to false
											board1(0, 4).getPieceOnSquare()->setFirstMove(false);
											//move king
											board1.movePiece(0, 4, 0, 6);
											return true;
										}

									}
									else {
										cout << "Castling to bottom right rook not possible" << endl;
									}

								}
								else {
									cout << "Castling to bottom right rook not possible" << endl;
								}

							}
							else {
								cout << "Castling to bottom right rook not possible" << endl;
							}
						}
					}
					else {
						cout << "Your king has already moved!" << endl;
					}
				}
				else {
					cout << "Your king has already moved!" << endl;
				}
				
			}
			

			//Player 2 

			if (_whosTurn == 2) {
				//Check if king at inital pos
				if (board1(7, 4).getPieceOnSquare() != nullptr) {
					if (board1(7, 4).getPieceOnSquare()->getPieceName() == 'k' && board1(7, 4).getPieceOnSquare()->getFirstMove() == true) {
						//The king has not moved, has the rook moved?

						//top left
						if (board1(7, 0).getPieceOnSquare() != nullptr) {
							if (board1(7, 0).getPieceOnSquare()->getPieceName() == 'r' && board1(7, 0).getPieceOnSquare()->getFirstMove() == true) {
								//the rook hasnt moved either.
								//are all the squares in betweem free?
								if (board1(7, 1).getPieceOnSquare() == nullptr  && board1(7, 2).getPieceOnSquare() == nullptr && board1(7, 3).getPieceOnSquare() == nullptr) {
									//are the squares in oppopossiblemoves?
									vector<int> position1 = { 7,2 };
									vector<int> position2 = { 7,3 };
									vector<int> position3 = { 7,4 };

									vector<vector<int>>::iterator isvalid1 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position1);
									vector<vector<int>>::iterator isvalid2 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position2);
									vector<vector<int>>::iterator isvalid3 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position3);

									if (isvalid1 == allPossibleMoves.end() && isvalid2 == allPossibleMoves.end() && isvalid3 == allPossibleMoves.end()) {
										//allpositions are available
										cout << "swap with bottom left rook?" << endl;
										cin >> whichRook;
										std::transform(whichRook.begin(), whichRook.end(), whichRook.begin(), ::tolower);

										//transform to lower
										if (whichRook == "y") {
											//set rooks firstmove to false
											board1(7, 0).getPieceOnSquare()->setFirstMove(false);
											//move rook
											board1.movePiece(7, 0, 7, 3);
											//set kings firstmove to false
											board1(7, 4).getPieceOnSquare()->setFirstMove(false);
											//move king
											board1.movePiece(7, 4, 7, 2);
											return true;
										}

									}
									else {
										cout << "Castling to top left rook not possible" << endl;
									}

								}
								else {
									cout << "Castling to top left rook not possible" << endl;
								}

							}
							else {
								cout << "Castling to top left rook not possible" << endl;
							}
						}

						//END OF TOP LEFT 

						//top right
						if (board1(7, 7).getPieceOnSquare() != nullptr) {
							if (board1(7, 7).getPieceOnSquare()->getPieceName() == 'r' && board1(7, 7).getPieceOnSquare()->getFirstMove() == true) {
								//the rook hasnt moved either.
								//are all the squares in betweem free?
								if (board1(7, 6).getPieceOnSquare() == nullptr  && board1(7, 5).getPieceOnSquare() == nullptr) {
									//are the squares in oppopossiblemoves?
									vector<int> position1 = { 7,6 };
									vector<int> position2 = { 7,5 };
									vector<int> position3 = { 7,4 };

									
									vector<vector<int>>::iterator isvalid1 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position1);
									vector<vector<int>>::iterator isvalid2 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position2);
									vector<vector<int>>::iterator isvalid3 = find(allPossibleMoves.begin(), allPossibleMoves.end(), position3);


									if (isvalid1 == allPossibleMoves.end() && isvalid2 == allPossibleMoves.end() && isvalid3 == allPossibleMoves.end()) {
										//allpositions are available
										cout << "swap with top right rook?" << endl;
										cin >> whichRook;
										std::transform(whichRook.begin(), whichRook.end(), whichRook.begin(), ::tolower);

										//transform to lower
										if (whichRook == "y") {
											//set rooks firstmove to false
											board1(7, 7).getPieceOnSquare()->setFirstMove(false);
											//move rook
											board1.movePiece(7, 7, 7, 5);
											//set rooks firstmove to false
											board1(7, 4).getPieceOnSquare()->setFirstMove(false);
											//move king
											board1.movePiece(7, 4, 7, 6);
											return true;
										}

									}
									else {
										cout << "Castling to top right rook not possible" << endl;
									}

								}
								else {
									cout << "Castling to top right rook not possible" << endl;
								}

							}
							else {
								cout << "Castling to top right rook not possible" << endl;
							}
						}
					}
					else {
						cout << "Your king has already moved!" << endl;
					}
				}
				else {
					cout << "Your king has already moved!" << endl;
				}

			}

		}
		//#########################################################################################
		//END OF CASTLING
		//#########################################################################################



		//#########################################################################################
		//If usual input, go through this set of code
		//check input is the right type, and then check the piece is the right type.
		//Find this pieces possible moves
		//#########################################################################################
		inputCorrect = validateInput(initalPos);
		if (inputCorrect == true) {

			//Convert input to integers that can be utilised by program
			initialColumn = letterToColumn(initalPos.substr(0, 1));
			initalRow = stoi(initalPos.substr(1, 2)) - 1;

			//Check user has not picked an empty square
			if (board1(initalRow, initialColumn).getPieceOnSquare() != nullptr) {

				//Check the user has picked one of their own pieces
				if (board1.getPiecePlayer(initalRow, initialColumn) == _whosTurn) {

					//Find the pieces possible moves, making sure it can make a move
					possibleMoves = board1(initalRow, initialColumn).getPieceOnSquare()->getPossibleMoves(initalRow, initialColumn);
					if (possibleMoves.size() != 0) {

						//The piece has moves it can make
						pieceCorrect = true;
					}
					else {
						cout << "That piece cannot make any moves, please pick a different one." << endl;
					}
				}
				else
				{
					cout << "This piece does not belong to you." << endl;
				}
			}
			else {
				cout << "There is no piece on that square! " << endl;
			}
		}
	}

	//Print confirmation of the move that has been made
	cout << "You have picked: " << board1(initalRow, initialColumn).getPieceOnSquare()->getPieceName() << endl;


	//ask user for where they want to move it
	//Booleans for input and move validation
	inputCorrect = false;
	bool moveAllowed = false;


	//Start getting the input for final position
	while (!inputCorrect) {

		inputCorrect = false;

		cout << endl;
		//Ask for input from user, and put into lowercase form
		cout << endl;
		cout << "Where would you like to move your piece?" << endl;
		cout << "(Type 'Help' to see the possible moves for this piece or 'reset' to pick a different piece to move)" << endl;
		cin >> finalPos;
		std::transform(finalPos.begin(), finalPos.end(), finalPos.begin(), ::tolower);
		cout << endl;


		//If user is not sure where they can move the piece
		if (finalPos == "help") {

			//Print the possible moves, and allow the user to pick a position
			cout << endl << "The possible moves for this piece are:" << endl;
			printAllMoves(possibleMoves);
			cout << "Where would you like to move your piece?" << endl;
			cin >> finalPos;
			std::transform(finalPos.begin(), finalPos.end(), finalPos.begin(), ::tolower);
			cout << endl;
		}



		//#########################################################################################
		//check input is the right type, and then check this is a possible move for the piece to make
		//check this move doesnt expose your own king
		//Find this pieces possible moves
		//#########################################################################################

		//Validate input
		inputCorrect = validateInput(finalPos);
		if (inputCorrect) {

			//Convert user input into integers
			finalColumn = letterToColumn(finalPos.substr(0, 1));
			finalRow = stoi(finalPos.substr(1, 2)) - 1;

			for (unsigned int i = 0; i < possibleMoves.size(); i++) {


				//Checks users move is a possible move
				if (finalColumn == possibleMoves[i][1] && finalRow == possibleMoves[i][0]) {


					piece * initalpiece = board1(initalRow, initialColumn).getPieceOnSquare();
					piece * finalpiece = board1(finalRow, finalColumn).getPieceOnSquare();
					//Does moving this piece cause check?
					board1.movePiece(initalRow, initialColumn, finalRow, finalColumn);

					//check allPossiblemoves with  the piece moved
					allPossibleMoves = board1.getOppoPossibleMoves(_whosTurn);

					//Chck if this causes check
					if (board1.check(allPossibleMoves, _whosTurn)) {
						//the move causes check
						board1(finalRow, finalColumn).setPieceOnSquare(finalpiece);
						board1(initalRow, initialColumn).setPieceOnSquare(initalpiece);
						cout << "Cannot make this move. It puts your king in check. " << endl;
						inputCorrect = false;
					}
					else {
						//move does not cause check
						//Move is allowed
						moveAllowed = true;

						//Check  if it is a pawn ready for promotion
						board1.promotion(finalRow, finalColumn);

						//edit the pieces firstmove
						//particular importance to rook and king
						board1(finalRow, finalColumn).getPieceOnSquare()->setFirstMove(false);
						
						return true;
					}

				}
			}
		}
		if (moveAllowed == false) {
			cout << "The position you picked was not an option!" << endl;
			inputCorrect = false;
		}
		else {
			if (finalPos == "reset") {
				//restart turn
				return false;
			}
		}


	}
	return false;
}


//#########################################################################################
//validateInput checks the input by the user and makes sure it is of the correct form.
//The form is ALL it checks, not whether the position contains a piece or anything like that.
//#########################################################################################

bool validateInput(const std::string input) {

	//Check length of user input corresponds to letter then number
	if (input.length() != 2) {
		cout << "Please input a letter on the board, followed by a number on the board" << endl;
		return false;
	}

	//Check first character is a letter
	else if (input.substr(0, 1) != "a" &&  input.substr(0, 1) != "b" && input.substr(0, 1) != "c"
		&& input.substr(0, 1) != "d" && input.substr(0, 1) != "e" && input.substr(0, 1) != "f"
		&& input.substr(0, 1) != "g" && input.substr(0, 1) != "h") {
		cout << "Please type a letter on the board" << endl;
		return false;
	}


	//Check second character is a number
	else if (isdigit(input[1]) == 0) {
		cout << "Looks like the second digit is not a number!" << endl;
		return false;
	}

	//Check second character is a number on the board.
	else if (stoi(input.substr(1, 2)) != 1 && stoi(input.substr(1, 2)) != 2 && stoi(input.substr(1, 2)) != 3 && stoi(input.substr(1, 2)) != 4 && stoi(input.substr(1, 2)) != 5
		&& stoi(input.substr(1, 2)) != 6 && stoi(input.substr(1, 2)) != 7 && stoi(input.substr(1, 2)) != 8) {
		cout << "Please type a number on the board" << endl;
		return false;
	}

	//If it passes all these tests, it is correct
	else {
		return true;
	}
}


//#########################################################################################
//printAllMoves is a function which retruns to console the list of moves input as an argument.
//#########################################################################################
void printAllMoves(const vector< vector<int> > possibleMoves) {

	for ( auto i = 0; i < possibleMoves.size(); i++) {
		cout << columnToLetter(possibleMoves[i][1]) << possibleMoves[i][0] + 1 << endl;
	}
}

//#########################################################################################
//letterToColumn converts the first character of the users input, a letter, to the 
//corresponding column.
//#########################################################################################
int letterToColumn(const std::string letter) {
	if (letter == "a") { return 0; }
	else if (letter == "b") { return 1; }
	else if (letter == "c") { return 2; }
	else if (letter == "d") { return 3; }
	else if (letter == "e") { return 4; }
	else if (letter == "f") { return 5; }
	else if (letter == "g") { return 6; }
	else if (letter == "h") { return 7; }
	else { return 8; }
	//Returns 8 on crazy eventuality that one of these letters arent pressed.
}

//#########################################################################################
//letterToColumn converts the column in integer form output by the program, to the letter
//which corresponds to its column
//#########################################################################################
std::string columnToLetter(const int column) {
	if (column == 0) { return "A"; }
	else if (column == 1) { return "B"; }
	else if (column == 2) { return "C"; }
	else if (column == 3) { return "D"; }
	else if (column == 4) { return "E"; }
	else if (column == 5) { return "F"; }
	else if (column == 6) { return "G"; }
	else if (column == 7) { return "H"; }
	else { return "I"; }
	//Returns I on crazy eventuality that one of these letters arent pressed.
}
