#pragma once

#include "GameBoard.hpp"
#include "Player.hpp"

class Game
{
    public:
        // Constructors
        Game();     // The Default Constructor

        // Non-Modifying Member Functions
        void        runGameLoop();
        bool        checkWinner();
        Position    getPosFromInt(int Index);
        GameBoard   getGameBoard()  const {return Board;}

        // Modifying Member Functions
        void processInput(int PlayerTurn);


    private:
        Player      P1, P2;
        GameBoard   Board;
};


// Helper Functions
int getVailidInput(Game& aGame);