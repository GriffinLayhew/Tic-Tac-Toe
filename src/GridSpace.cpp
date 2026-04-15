#include "GridSpace.hpp"

// Constructor Definition
    GridSpace::GridSpace(Position Pos) : myPosition{Pos}
    {
        isFilled    = 0;
        fillMarker  = '*';
    }


// Member Function Definitions
    void GridSpace::printSpace() const
    {
        std::cout << this->thisSpaceMarker();
    }    

    void GridSpace::setMarker(char Marker)
    {
        fillMarker = Marker;
    }

    void GridSpace::setFilled(bool filled)
    {
        isFilled = filled;
    }


// Overloaded Operators

    // Equality
    bool operator==(GridSpace& Space1, GridSpace& Space2)
    {
        char Marker1 = Space1.thisSpaceMarker();
        char Marker2 = Space2.thisSpaceMarker();

        if (Marker1 == Marker2)
            return true;
        else    
            return false;
    }

    // Mark with X
    GridSpace& operator++(GridSpace& Space)
    {
        if (Space.thisSpaceFilled() == true)
            return Space;
        
        Space.setFilled(true);
        Space.setMarker('X');
        return Space;
    }

    // Mark with O
    GridSpace& operator--(GridSpace& Space)
    {
        if (Space.thisSpaceFilled() == true)
            return Space;
        
        Space.setFilled(true);
        Space.setMarker('O');
        return Space;
    }
