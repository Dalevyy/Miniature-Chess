#include <iostream>
#include "chessPiece.h"

/*
Description: Constructor for the chessPiece class 
Parameters: Passing a bool representing the color of the chess piece
Return Type: No Return Type
*/
chessPiece::chessPiece(bool color)
{
    /*
    Setting the color of current chessPiece object based on the parameter
    True means red piece
    False means black piece
    */
    this -> color = color;
}

/*
Description: Accessor function that will return the player's color
Parameters: No parameters
Return Type: Bool (Returns true if red, false if black)
*/
bool chessPiece::getPlayerType() const
{
    return this -> color;
}

/*
Description: Destructor for the chessPiece class
Parameters: None
Return Type: No return type
*/
chessPiece::~chessPiece()
{
    std::cout << "Piece removed from board.\n\n";
}
