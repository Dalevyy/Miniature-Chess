#include <iostream>
#include "chessPiece.h"
#include "queenType.h"
#include "rookType.h"
#include "bishopType.h"
#include "knightType.h"

#define RESET "\033[0m"
#define RED "\033[31m"

void outputBoard(chessPiece***);
void clearBoard(chessPiece***);

int main()
{
	chessPiece *** board;

	board = new chessPiece**[8];

	for (int i = 0; i < 8; i++)
		board[i] = new chessPiece*[8];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = nullptr;


	//place the black chess pieces onto
	//the board
	board[0][3] = new knightType(false);
	board[1][0] = new rookType(false);
	board[1][2] = new bishopType(false);
	board[1][3] = new queenType(false);
	board[1][4] = new bishopType(false);
	board[1][6] = new rookType(false);
	board[2][3] = new knightType(false);

	//place the red chess pieces onto
	//the board
	board[5][4] = new knightType(true);
	board[6][1] = new rookType(true);
	board[6][3] = new bishopType(true);
	board[6][4] = new queenType(true);
	board[6][5] = new bishopType(true);
	board[6][7] = new rookType(true);
	board[7][4] = new knightType(true);	

	outputBoard(board);

	char row1, row2;
	int col1, col2;

	int redPieces = 7;
	int blackPieces = 7;

	bool turn = true;

	//While loop to run until either red or black have no pieces left
	while (redPieces > 0 && blackPieces > 0)
	{
		//Outputting which player is able to move
		if(turn)
		{
			std::cout << "Enter starting coordinates (Red Turn): ";
		}
		else
		{
			std::cout << "Enter starting coordinates (Black Turn): ";
		}
		std::cin >> row1 >> col1;

		//Checks to see if a valid row/column was inputted by user
		if(row1 < 'A' || row1 > 'H' || col1 < 1 || col1 > 8)
		{	
			//Any error, will clear/ignore input and loop back 
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid piece selected.\n\n";
			continue;
		}

		/*
		Then checks to see if there isn't a chess piece present at the 
		starting coordinate the user inputted
		*/ 
		if(board[int(row1) - 65][col1 - 1] == nullptr)
		{	
			//Any error, will clear/ignore input and loop back 
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Starting coordinate is empty!\n\n";
			continue;
		}

		/*
		Then checks to see if the user chose the correct piece 
		that represents their color 
		*/
		if(board[static_cast<int>(row1) - 65][col1 - 1] -> 
		getPlayerType() != turn)
		{
			//Any error, will clear/ignore input and loop back 
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid piece selected.\n\n";
			continue;
		}

		//If all good, get ending coordinates next
			std::cout << "Enter ending coordinates: ";
			std::cin >> row2 >> col2;

			//Calling chess piece's corresponding move function to see if it can move or not
			if(board[static_cast<int>(row1) - 65][col1 - 1] -> move(row1, col1, row2, col2, board))
			{
				//Checking to see if position is storing a chess piece or not
				if(board[static_cast<int>(row2) - 65][col2 - 1])
				{	
					//Will decrease black pieces if it's currently red's turn
					if(turn)
					{
						blackPieces--;
					}
					//Will decrease red pieces if it's currently black's turn
					else
					{
						redPieces--;
					}
				}
				//Moving the player's piece into the new space 
				board[static_cast<int>(row2) - 65][col2 - 1] = board[static_cast<int>(row1) - 65][col1 - 1];
				//Making previous space empty
				board[static_cast<int>(row1) - 65][col1 - 1] = nullptr;
				
				outputBoard(board);

				//Checking to see if black has any pieces left, indicating red wins
				if(blackPieces == 0)
				{
					std::cout << "Red wins!\n";
				}
				//Checking to see if red has any pieces left, indicating black wins
				if(redPieces == 0)
				{
					std::cout << "Black wins\n";
				}

				//If game isn't over, change which player gets to move next
				if(turn)
				{
					turn = false;
				}
				else
				{
					turn = true;
				}
			}
			//If an invalid move is made
			else
			{
				std::cout << "Invalid move!\n\n";
				continue;
			}

	}

	clearBoard(board);

	return 0;
}

/*
Description: Will output the board at the start of each chess game
and after a player moves a piece
Parameters: Passing the triple chessPiece pointer board 
Return Type: None 
*/
void outputBoard(chessPiece *** board)
{	
	//Char variable to keep track of current row that is outputted
	char row = 'A';

	//For loop to print out each column number
	for(int i = 1; i <= 8; i++)
	{
		std::cout << "  " << i;
	}
	std::cout << "\n";

	//Nested for loop to print out chess pieces onto the board
	for(int i = 0; i < 8; i++)
	{
		std::cout << row;
		for(int j = 0; j < 8; j++)
		{
			//Checks to see if no memory location is stored first
			if(board[i][j] == nullptr)
			{
				std::cout << " - " << RESET;
			}

			//Checks to see if board can be converted to a queenType
			else if(dynamic_cast<queenType*> (board[i][j]))
			{
				//Checks if chessPiece object is red
				if(board[i][j] -> getPlayerType())
				{
					std::cout << RED << " Q " << RESET;
				}
				else
				{
					std::cout << " Q " << RESET;
				}
			}

			//Checks to see if board can be converted to a rookType
			else if(dynamic_cast<rookType*> (board[i][j]))
			{
				//Checks if chessPiece object is red
				if(board[i][j] -> getPlayerType())
				{
					std::cout << RED << " R " << RESET;
				}
				else
				{
					std::cout << " R " << RESET;
				}
			}

			//Checks to see if board can be converted to a bishopType
			else if(dynamic_cast<bishopType*> (board[i][j]))
			{
				//Checks if chessPiece object is red
				if(board[i][j] -> getPlayerType())
				{
					std::cout << RED << " B " << RESET;
				}
				else
				{
					std::cout << " B " << RESET;
				}
			}

			//Checks to see if board can be converted to a knightType
			else if(dynamic_cast<knightType*> (board[i][j]))
			{
				//Checks if chessPiece object is red
				if(board[i][j] -> getPlayerType())
				{
					std::cout << RED << " K " << RESET;
				}
				else
				{
					std::cout << " K " << RESET;
				}
			}
		}
		std::cout << RESET << "\n";
		row++;
	}
	std::cout << "\n";
}

/*
Description: Deallocating memory from the board triple pointer once the game is over
Parameters: Passing the board triple pointer
Return Type: Void (no return type)
*/
void clearBoard(chessPiece *** board)
{
	//Row loop
	for(int i = 0; i < 8; i++)
	{
		//Column loop
		for(int j = 0; j < 8; j++)
		{
			//Checking to see if there are any chess pieces remaining on the board
			if(board[i][j] != nullptr)
			{
				//Deallocating memory that is storing any remaining chess pieces
				delete board[i][j];
			}
		}
		//Deallocating the column memory locations
		delete [] board[i];
	
	}
	//Deallocating the row memory locations
	delete [] board;
}