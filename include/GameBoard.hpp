#pragma once

#include "Utilities.hpp"
#include "GridSpace.hpp"



class GameBoard
{
    public:
    // Constructors
        GameBoard();      // Only one Default Constructor
    
    // Non-Modifying Member Functions
        std::vector<GridSpace>  getBoardData() const    {return boardData;}
        void                    printGameBoard();
        bool                    isThereaWinner() const  {return hasWinner;}

    // Modifying Member Functions
        void                     updateBoard(Position,char);
        int                      getVecFromPos(Position);
        std::vector<GridSpace>&  changeBoardData()       {return boardData;}
        void                     setNewWinner();



    private:
        bool                        hasWinner;
        int                         gameRound;
        std::vector<GridSpace>      boardData;


};

