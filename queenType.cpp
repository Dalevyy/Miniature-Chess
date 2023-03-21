#include "queenType.h"
#include <iostream>

/*
Description: Constructor for the queenType class 
Parameters: Passing a bool representing the color of the chess piece
Return Type: No Return Type
*/
queenType::queenType(bool color) : chessPiece(color)
{ 
    // chessPiece class constructor being called in heading
}

/*
Description: Will see if the player is allowed to move the queen or not
Parameters: Passing the starting row/col, ending row/col, and the board
Return Type: Bool (true if move can be made, false if not)
*/
bool queenType::move(char startRow, int startCol, char endRow,
 int endCol, chessPiece*** board)
{
    /*
    Queen is the most powerful piece in chess as it acts as both a 
    rook and a bishop combined

    This means that the queen will either move as a rook or as a bishop
    */

    int sRow, eRow, sCol, eCol, moveRow, moveCol;

    //Life easier blah blah
    sRow = static_cast<int>(startRow) - 65;
    eRow = static_cast<int>(endRow) - 65;
    sCol = startCol - 1;
    eCol = endCol - 1;
    moveRow = eRow - sRow;
    moveCol = eCol - sCol;
	
	//Checks if queen moves like a rook 
    if(moveRow == 0 || moveCol == 0)
    {	
		//Checks to see whether or not queen moves to a different row/col
		if(moveCol == 0)
		{	
           // std::cout << "moveCol = 0\n";
			if(abs(moveRow) == moveRow)
			{
				//If col, loop through each row
				for(int i = 1; i <= abs(moveRow); i++)
				{	

				if((sRow + i) == eRow)
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
			    if(board[sRow + i][sCol] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[sRow + i][sCol] != nullptr)
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
				if((sCol+ i) == eCol)
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
				if(board[sRow][abs(sCol - i)] == nullptr)
				{
					continue;
				}
				//Checks if board space has a piece already and it's not the ending position
				if(board[sRow][abs(sCol - i)])
				{
					return false;;
				}

					return false;
				}
			}
		}
	}
	//If queen moves like a bishop
    else if (abs(moveRow) == abs(moveCol))
    {
        if(abs(moveRow) == moveRow)
		{
			if(abs(moveCol) == moveCol)
			{
				//If col, loop through each row
				for(int i = 1; i <= abs(moveCol); i++)
				{	
				//checks if board space 
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
				//checks if board space 
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
				//checks if board space 
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
				//checks if board space 
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
Description: Destructor for the queenType class
Parameters: None
Return Type: No return type
*/
queenType::~queenType()
{
    std::cout << "\nQueen Taken.\n\n";
}
