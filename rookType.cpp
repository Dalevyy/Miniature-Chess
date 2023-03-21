#include "rookType.h"
#include <iostream>

bool checkFinalPos(int, int, int, int, chessPiece***);
/*
Description: Constructor for the rookType class 
Parameters: Passing a bool representing the color of the chess piece
Return Type: No Return Type
*/
rookType::rookType(bool color) : chessPiece(color)
{ 
	// chessPiece class constructor being called in heading
}

/*
Description: Will see if the player is allowed to move a rook or not
Parameters: Passing the starting row/col, ending row/col, and the board
Return Type: Bool (true if move can be made, false if not)
*/
bool rookType::move(char startRow, int startCol, char endRow, 
	int endCol, chessPiece*** board)
{
	/*
	A rook can only move either up/down or left/right

	If it moves up/down, then it will stay in the same column, but 
	it will move to a different row

	If it moves left/right, then it will stay in the same row, but 
	it will move to a different column 
	*/

	//Converting start/end row parameters to ints 
	//Makes life easier LOL
	int sRow, eRow, sCol, eCol;
	sRow = static_cast<int>(startRow) - 65;
	eRow = static_cast<int>(endRow) - 65;

	sCol = startCol - 1; //Getting proper index
	eCol = endCol - 1;	//Getting proper index
	
	int moveRow, moveCol = 0;

	/*
	Checking to see if values equal 0 or not

	With a rook piece, either the moveRow or moveCol has to be equal
	to 0 to indicate it will stay in the same row/column
	*/
    moveRow = eRow - sRow;
    moveCol = eCol - sCol;

	//First checks to see if the move is valid based on how the piece can move
	//Invalid move if the rook is changing both its row/col at the same time
	if(moveRow != 0 && moveCol != 0)
	{
		return false;
	}
	if(moveRow == 0 || moveCol == 0)
	{	
		//Checks to see whether or not rook moves to a different row/col
		if(moveCol == 0)
		{	
			if(abs(moveRow) == moveRow)
			{
				//If col, loop through each row
				for(int i = 1; i <= abs(moveRow); i++)
				{	
				if((sRow + i) == eRow)
				{
					//Calling function to see if move is valid to final pos
					if(checkFinalPos(sRow,eRow,sCol,eCol,board))
					{
						return true;
					}
						return false;
				}
				//Checks if board space is empty or not
				if(board[sRow + i][sCol] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[sRow + i][sCol])
				{
					return false;
				}

					return false;
				}
			}
			else
			{
				//If col, loop through each row
				for(int i = 1; i <= abs(moveRow); i++)
				{	
				if((sRow - i) == eRow)
				{
					//Calling function to see if move is valid to final pos
					if(checkFinalPos(sRow,eRow,sCol,eCol,board))
					{
						return true;
					}

						return false;
				}
				//Checks if board space is empty or not
				if(board[abs(sRow-i)][sCol] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[abs(sRow-i)][sCol])
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
				//If row, loop through each col
				for(int i = 1; i <= abs(moveCol); i++)
				{
				//checks if staring/ending position are the same
				if((sCol + i) == eCol)
				{	
					//Calling function to see if move is valid to final pos
					if(checkFinalPos(sRow,eRow,sCol,eCol,board))
					{
						return true;
					}
						return false;
				}
				//Checks if board space is empty or not
				if(board[sRow][sCol + i] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[sRow][sCol + i])
					{
					return false;;
				}
					return false;
				}
			}
			else
			{
				//If row, loop through each col
				for(int i = 1; i <= abs(moveCol); i++)
				{
				//checks if staring/ending position are the same
				if((sCol - i) == eCol)
				{	
					//Calling function to see if move is valid to final pos
					if(checkFinalPos(sRow,eRow,sCol,eCol,board))
					{
						return true;
					}
		
						return false;
				}
				//Checks if board space is empty or not
				if(board[sRow][abs(sCol - i)] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[sRow][abs(sCol - i)])
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
Description: Destructor for the rookType class
Parameters: None
Return Type: No return type
*/
rookType::~rookType()
{
	std::cout << "\nRook Taken.\n\n";
}

/*
Description: Will check to see if the rook can move into selected final pos
Parameters: Passing start/end row, start/end col, and board pointer
Return Type: Bool (true if valid move, false if not)
*/
bool checkFinalPos(int sRow, int eRow, int sCol, int eCol, chessPiece*** board)
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

