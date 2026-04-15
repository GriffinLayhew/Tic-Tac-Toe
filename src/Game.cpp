#include "Game.hpp"

// Constructors
Game::Game() : P1{ Player(1, 'X')}, P2{ Player(2, 'O')}, Board{GameBoard()}
{
    
}

// Member Functions
void Game::runGameLoop()
{
    std::cout << "===============================" << std::endl;
    std::cout << "Hello! Welcome to Tic-Tac-Toe!!" << std::endl;
    std::cout << "===============================" << std::endl << std::endl << std::endl;

    
    int turn = 0;

    while (Board.isThereaWinner() == 0)
    {
        Board.printGameBoard();
        if(turn%2 == 0)
            std::cout << std::endl << "Player 1: Please Make a Move: " << std::endl;
        else 
            std::cout << std::endl << "Player 2: Please Make a Move: " << std::endl;

        this->processInput(turn);
        if (this->checkWinner())
        {
            this->Board.setNewWinner();
            std::cout << std::endl << "We Have a Winner!" << std::endl;
        }
            

        turn++;
    }
    std::cout << std::endl << std::endl;
    Board.printGameBoard();
    std::cout << "===============================" << std::endl;
    std::cout << "         Game Over!!!!!" << std::endl;
    std::cout << "===============================" << std::endl << std::endl << std::endl;
}

Position Game::getPosFromInt(int Index)
{
    Position myPos;

    int row =    (Index)/3;
    int column = (Index)%3;

    myPos.y = row;
    myPos.x = column;

    return myPos;
}

void Game::processInput(int PlayerTurn)
{
    int Location = getVailidInput(*this);

    Position myPos = getPosFromInt(Location);
    if(PlayerTurn%2 == 0)
    {
        P1.placeMarker(Board, myPos);
    }
    else
    {
        P2.placeMarker(Board, myPos);
    }

}

bool Game::checkWinner()
{

    if ( (Board.getBoardData()[6].thisSpaceMarker() == Board.getBoardData()[3].thisSpaceMarker() &&  Board.getBoardData()[6].thisSpaceMarker() == Board.getBoardData()[0].thisSpaceMarker()) && (Board.getBoardData()[6].thisSpaceMarker() != '*'))
        return true;
    if ( (Board.getBoardData()[7].thisSpaceMarker() == Board.getBoardData()[4].thisSpaceMarker() &&  Board.getBoardData()[7].thisSpaceMarker() == Board.getBoardData()[1].thisSpaceMarker()) && (Board.getBoardData()[7].thisSpaceMarker() != '*'))
        return true;
    if ( (Board.getBoardData()[8].thisSpaceMarker() == Board.getBoardData()[5].thisSpaceMarker() &&  Board.getBoardData()[8].thisSpaceMarker() == Board.getBoardData()[2].thisSpaceMarker()) && (Board.getBoardData()[8].thisSpaceMarker() != '*'))
        return true;

    if ( (Board.getBoardData()[0].thisSpaceMarker() == Board.getBoardData()[1].thisSpaceMarker() &&  Board.getBoardData()[0].thisSpaceMarker() == Board.getBoardData()[2].thisSpaceMarker()) && (Board.getBoardData()[0].thisSpaceMarker() != '*'))
        return true;
    if ( (Board.getBoardData()[3].thisSpaceMarker() == Board.getBoardData()[4].thisSpaceMarker() &&  Board.getBoardData()[3].thisSpaceMarker() == Board.getBoardData()[5].thisSpaceMarker()) && (Board.getBoardData()[3].thisSpaceMarker() != '*'))
        return true;
    if ( (Board.getBoardData()[6].thisSpaceMarker() == Board.getBoardData()[7].thisSpaceMarker() &&  Board.getBoardData()[6].thisSpaceMarker() == Board.getBoardData()[8].thisSpaceMarker()) && (Board.getBoardData()[6].thisSpaceMarker() != '*'))
        return true;

    if ( (Board.getBoardData()[6].thisSpaceMarker() == Board.getBoardData()[4].thisSpaceMarker() &&  Board.getBoardData()[6].thisSpaceMarker() == Board.getBoardData()[2].thisSpaceMarker()) && (Board.getBoardData()[6].thisSpaceMarker() != '*'))
        return true;
    if ( (Board.getBoardData()[0].thisSpaceMarker() == Board.getBoardData()[4].thisSpaceMarker() &&  Board.getBoardData()[0].thisSpaceMarker() == Board.getBoardData()[8].thisSpaceMarker()) && (Board.getBoardData()[0].thisSpaceMarker() != '*'))
        return true;

    return false;
}



// Helper Functions
int getVailidInput(Game& TheGame)
{
    int Location;
    bool isThisSpaceFilled = true;

    while(isThisSpaceFilled)
    {
        std::cin >> Location;
        

        isThisSpaceFilled = TheGame.getGameBoard().getBoardData()[Location-1].thisSpaceFilled();
        if(isThisSpaceFilled)
            std::cout << "Please Make Another Selection!" << std::endl;

    }

    return Location;
}