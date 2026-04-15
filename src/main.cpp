/*
    AUTHOR:                     Griffin Layhew

    DATE:                       03/28/26
    PROGRAM TITLE:              Tic Tac Toe Game
    PROGRAM DESCRIPTION:
            " This is the conventional Tic Tac Toe Game for 2 Players."


*/

#include "Utilities.hpp"
#include "GridSpace.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"
#include "Game.hpp"


            //===============================//
            //      MAIN STARTS HERE //
            //===============================//
int main(int argc, char* argv[])
{
    /*
    =============================================
            Initialize the Game Board & Run
    =============================================
    */
    Game theGame;
    theGame.runGameLoop();


   return 0;
}