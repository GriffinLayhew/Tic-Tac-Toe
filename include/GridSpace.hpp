#pragma once

#include "Utilities.hpp"

typedef struct
{
    int x;
    int y;
} Position;
 

class GridSpace
{
    public:
    // Constructors
        GridSpace(Position Pos);            // Typical Constructor
    
    // Non-Modifying Member Functions
    bool        thisSpaceFilled()   const {return isFilled; }
    char        thisSpaceMarker()   const {return fillMarker; }
    Position    thisSpacePosition() const {return myPosition; }

    void        printSpace()        const;       

    // Modifying Member Functions
    void        setMarker(char);
    void        setFilled(bool);

    private:
        bool        isFilled;
        char        fillMarker;
        Position    myPosition;

};

bool            operator==(GridSpace&, GridSpace&);         // Equality Check
GridSpace&      operator++(GridSpace&);                     // Set as 'X'
GridSpace&      operator--(GridSpace&);                     // Set as 'O'