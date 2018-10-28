#include "creature.h"

Creature::Creature()
{
    this->location._i = -1;
    this->location._j = -1;

    this->_face = '@';
}

Creature::Creature(Location l, char face)
{
    this->location._i = l._i;
    this->location._j = l._j;

    this->_face = face;
}

void Creature::move()
{
    //This function will be virtual used in inheritance,
    //so nothing needs to be here.
}

void Creature::breed()
{
    //This function will be virtual used in inheritance,
    //so nothing needs to be here.
}

Location* Creature::find_creature(int grid[][MAX], char face)
{
    Location* available = new Location[8];
    Location* walker = available;
    for(int i = this->location._i - 1; i < this->location._i + 1; i++)
    {
        for(int j = this->location._j - 1; j < this->location._j + 1; j++)
        {
            if(i != this->location._i && j != this->location._j)
            {
                if(grid[i][j] == 0)
                {
                    walker->_i = i;
                    walker->_j = j;
                    walker++;
                }
            }
        }
    }
    return available;
}
