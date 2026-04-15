#include "Player.hpp"

// Constructor Definition

// Member Function Definitions
    void    Player::placeMarker(GameBoard& ticTacToe, Position thisPos)
    {
        ticTacToe.updateBoard(thisPos,myMarker);
    }

    void    Player::setMarker(char marker)
    {
        myMarker = marker;
    }
// Overloaded Operators


// Helper Functions
