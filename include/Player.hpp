#pragma once

#include "GameBoard.hpp"

class Player
{
    public:
    // Constructors
        Player(int NUM, char MARK) : playerNumber{NUM}, myMarker{MARK}  // Typical Constructor
        {
            
        }        
    
    // Non-Modifying Member Functions
        int     getPlayerNumber() const   {return playerNumber;}
        int     getPlayerMarker() const   {return myMarker;}



    // Modifying Member Functions
        void    placeMarker(GameBoard& ticTacToe, Position thisPos);
        void    setMarker(char marker);

    private:
        int     playerNumber;
        char    myMarker;



};
