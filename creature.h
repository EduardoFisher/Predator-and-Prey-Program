#ifndef CREATURE_H
#define CREATURE_H
#include "location.h"
#include "grid.h"

class Creature
{
public:
    Creature();
    Creature(Location l, char face);
    void move();
    void breed();
    void move_to();
    //Return a location* of valid spaces.
    Location* find_creature(int grid[][MAX], char face);
private:
    char _face;
    Location location;
};

#endif // CREATURE_H
