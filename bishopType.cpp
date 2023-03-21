#include "bishopType.h"
#include <cmath>
#include <iostream>

/*
Description: Constructor for the bishopType class 
Parameters: Passing a bool representing the color of the chess piece
Return Type: No Return Type
*/
bishopType::bishopType(bool color) : chessPiece(color)
{
    // chessPiece class constructor being called in heading
}

/*
Description: Will see if the player is allowed to move a bishop or not
Parameters: Passing the starting row/col, ending row/col, and the board
Return Type: Bool (true if move can be made, false if not)
*/
bool bishopType::move(char startRow, int startCol, char endRow, 
	int endCol, chessPiece*** board)
{
	/*
	A bishop will mvoe diagonally only.

	This means that a bishop is guaraneteed to move the same number of 
	rows and columns at the same time, and then you just have to account
	for the direction it moves in
	*/

	int sRow, eRow, sCol, eCol, moveRow, moveCol;

	//Doing all of this to make code easier to read lol
	sRow = static_cast<int>(startRow) - 65;
	eRow = static_cast<int>(endRow) - 65;
	sCol = startCol - 1;
	eCol = endCol - 1;

	//abs of both moveRow AND moveCol need to equal each other for move to be valid
	moveRow = eRow - sRow;
	moveCol = eCol - sCol;

	//Checks to see if the same number of rows/columns are being changed
	if(abs(moveRow) != abs(moveCol))
	{
		return false;
	}
	if(abs(moveRow) == abs(moveCol))
	{
		if(abs(moveRow) == moveRow)
		{
			if(abs(moveCol) == moveCol)
			{
				//If col, loop through each row
				for(int i = 1; i <= abs(moveCol); i++)
				{	
				if(board[sRow + i][sCol + i] == board[eRow][eCol])
				{
					//First will check if the final position is empty or not
					if(board[eRow][eCol] == nullptr)
					{
						//Valid move if that's the case 
						return true;
						}
					//If it's not empty, then it will check if the ending coordinate contains an enemy piece
					if(board[eRow][eCol] -> getPlayerType() != board[sRow][sCol] -> getPlayerType())
					{
						//Deallocate the chessPiece object and continue
						delete board[eRow][eCol];
						return true;
					}
					return false;
				}
				//Checks if board space is empty or not
				if(board[sRow + i][sCol + i] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[sRow + i][sCol + i])
				{
					return false;
				}
					return false;
				}
			}
			else
			{
				//If col, loop through each row
				for(int i = 1; i <= abs(moveCol); i++)
				{	
				if(board[sRow + i][sCol - i] == board[eRow][eCol])
				{
					//First will check if the final position is empty or not
					if(board[eRow][eCol] == nullptr)
					{
						//Valid move if that's the case 
						return true;
					}
					//If it's not empty, then it will check if the ending coordinate contains an enemy piece
					if(board[eRow][eCol] -> getPlayerType() != board[sRow][sCol] -> getPlayerType())
					{
						//Deallocate the chessPiece object and continue
						delete board[eRow][eCol];
						return true;
					}
					return false;
				}
				//Checks if board space is empty or not
				if(board[sRow + i][sCol - i] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[sRow + i][sCol - i])
				{
					return false;
				}
					return false;
				}
			}
		}
		else
		{
			if(abs(moveCol) == moveCol)
			{
				//If col, loop through each row
				for(int i = 1; i <= abs(moveCol); i++)
				{	
				if(board[sRow - i][sCol + i] == board[eRow][eCol])
				{
					//First will check if the final position is empty or not
					if(board[eRow][eCol] == nullptr)
					{
						//Valid move if that's the case 
						return true;
						}
					//If it's not empty, then it will check if the ending coordinate contains an enemy piece
					if(board[eRow][eCol] -> getPlayerType() != board[sRow][sCol] -> getPlayerType())
					{
						//Deallocate the chessPiece object and continue
						delete board[eRow][eCol];
						return true;
					}
						return false;
				}
				//Checks if board space is empty or not
				if(board[sRow - i][sCol + i] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[sRow - i][sCol + i])
				{
					return false;
				}

					return false;
				}
			}
			else
			{
				//If col, loop through each row
				for(int i = 1; i <= abs(moveCol); i++)
				{	
				if(board[sRow - i][sCol - i] == board[eRow][eCol])
				{
					//First will check if the final position is empty or not
					if(board[eRow][eCol] == nullptr)
					{
						//Valid move if that's the case 
						return true;
						}
					//If it's not empty, then it will check if the ending coordinate contains an enemy piece
					if(board[eRow][eCol] -> getPlayerType() != board[sRow][sCol] -> getPlayerType())
					{
						//Deallocate the chessPiece object and continue
						delete board[eRow][eCol];
						return true;
					}
						return false;
				}
				//Checks if board space is empty or not
				if(board[sRow - i][sCol - i] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[sRow - i][sCol - i])
				{
					return false;
				}
					return false;
				}
			}
		}
	}

	return false;
}

/*
Description: Destructor for the bishopType class
Parameters: None
Return Type: No return type
*/
bishopType::~bishopType()
{
	std::cout << "\nBishop Taken.\n\n";
}


