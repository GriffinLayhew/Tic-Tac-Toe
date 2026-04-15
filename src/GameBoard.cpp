#include "GameBoard.hpp"

// Constructor Definition
    GameBoard::GameBoard() : hasWinner{0}, gameRound{1}
    {
    
        for (int i=1; i<=9; i++)
        {
            int row =    (i)/3;
            int column = (i)%3;
            GridSpace thisGridSpace({column,row});
            boardData.push_back(thisGridSpace);
        }
            
    } 

// Member Function Definitions

    void GameBoard::printGameBoard()
    {
        std::cout << "        " << 7 << "   " << 8 << "   " << 9 << "   " <<  "        " << this->getBoardData()[6].thisSpaceMarker() << "   " << this->getBoardData()[7].thisSpaceMarker() << "   " << this->getBoardData()[8].thisSpaceMarker() << "   " << std::endl;
        std::cout << "        " << 4 << "   " << 5 << "   " << 6 << "   " <<  "        " << this->getBoardData()[3].thisSpaceMarker() << "   " << this->getBoardData()[4].thisSpaceMarker() << "   " << this->getBoardData()[5].thisSpaceMarker() << "   " << std::endl;
        std::cout << "        " << 1 << "   " << 2 << "   " << 3 << "   " <<  "        " << this->getBoardData()[0].thisSpaceMarker() << "   " << this->getBoardData()[1].thisSpaceMarker() << "   " << this->getBoardData()[2].thisSpaceMarker() << "   " << std::endl;
    }

    void GameBoard::updateBoard(Position thisPos,char newMarker)
    {
        int vecPosition = this->getVecFromPos(thisPos);
        this->changeBoardData()[vecPosition].setMarker(newMarker);
        this->changeBoardData()[vecPosition].setFilled(true);

    }

    int GameBoard::getVecFromPos(Position targetPos)
    {
        for (int i=0; i<=9; i++)
        {
            Position thisPos = this->getBoardData()[i].thisSpacePosition();
            if ((thisPos.x == targetPos.x) && (thisPos.y == targetPos.y))
                return i;
        }

        return -1;
    }

    void GameBoard::setNewWinner()
    {
        hasWinner = true;
    }

// Overloaded Operators


// Helper Functions
