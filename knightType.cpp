#include "knightType.h"
#include <iostream>

/*
Description: Constructor for the knightType class 
Parameters: Passing a bool representing the color of the chess piece
Return Type: No Return Type
*/
knightType::knightType(bool color) : chessPiece(color)
{ 
    // chessPiece class constructor being called in heading
}

/*
Description: Will see if the player is allowed to move a knight or not
Parameters: Passing the starting row/col, ending row/col, and the board
Return Type: Bool (true if move can be made, false if not)
*/
bool knightType::move(char startRow, int startCol, char endRow,
 int endCol, chessPiece*** board)
{
	/*
    The knight piece is the only weird piece in chess 

    It can either move two rows and then one column OR 
    two columns and then one row

    Good news is that it jumps over pieces, so don't need to check
    if pieces are in its way or not
    */
    
    //Making my life easier LOL
    int sRow, eRow, sCol, eCol, moveRow, moveCol;
    sRow = static_cast<int>(startRow) - 65;
    eRow = static_cast<int>(endRow) - 65;
    sCol = startCol - 1;
    eCol = endCol -1;

    moveRow = abs(eRow - sRow);
    moveCol = abs(eCol - sCol);

    //Checks if rows aren't moved by 2/columns by 1
    if(moveRow != 2 && moveRow != 1)
    {
        return false;
    }
    //Checks then if rows aren't moved by 1/columns by 2
    if(moveCol != 2 && moveCol != 1)
    {
        return false;
    }
    if(moveCol == moveRow)
    {
        return false;
    }

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

/*
Description: Destructor for the knightType class
Parameters: None
Return Type: No return type
*/
knightType::~knightType()
{
	std::cout << "\nKnight Taken.\n\n";
}
