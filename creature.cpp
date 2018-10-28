#include "creature.h"
#include <iostream>//for testing purposes only!
#include <ctime>
#include <cstdlib>

using namespace std;//for testing purposes only!



Creature::Creature()
{
    this->location._i = -1;
    this->location._j = -1;

    this->_face = '@';
}

Creature::Creature(int i, int j, char face)
{
    this->location._i = i;
    this->location._j = j;

    this->_face = face;
}

char Creature::get_face()
{
    return _face;
}

bool Creature::get_hasMoved()
{
    return has_moved;
}

void Creature::set_hasMoved()
{
    has_moved = false;
}

void Creature::move(Creature* world[][MAX])
{
    //This function will be virtual used in inheritance,
    //so nothing needs to be here.
    cout << "If you see this you done fucked up\n";
}

void Creature::breed(Creature* world[][MAX])
{
    //This function will be virtual used in inheritance,
    //so nothing needs to be here.
    cout << "If you see this you done fucked up\n";
}

void Creature::move_to(Creature *world[][MAX], Location loca)
{

    if((world[loca._i][loca._j] != NULL) && (world[loca._i][loca._j]->get_face() == 'p'))
    {
        delete world[loca._i][loca._j];
        world[loca._i][loca._j] = world[this->location._i][this->location._j];
        world[this->location._i][this->location._j] = NULL;
        this->location._i = loca._i;
        this->location._j = loca._j;
        this->has_moved = true;
    }
    else
    {
        world[loca._i][loca._j] = world[this->location._i][this->location._j];
        world[this->location._i][this->location._j] = NULL;
        this->location._i = loca._i;
        this->location._j = loca._j;
        this->has_moved = true;
    }

}

Location Creature::find_prey(Creature* world[][MAX])
{
    srand(time(NULL));
    Location* available = new Location[8];
    Location* walker = available;
    Location place;
    int random = 0;
    int size = 0;
    for(int i = this->location._i - 1; i <= this->location._i + 1; i++)
    {
        for(int j = this->location._j - 1; j <= this->location._j + 1; j++)
        {

            if(world[i][j] != NULL)
            {
                if(world[i][j]->get_face() == 'o')
                {
                    size++;
                    walker->_i = i;
                    walker->_j = j;
                    walker++;
                }
            }
        }
    }
    //checking to see if we have any avaiable spaces.
    if(size != 0)
    {
        random = rand() % size;
        walker = available;
        for(int i = 0; i < random; i++)
        {
            walker++;
        }
        place._i = walker->_i;
        place._j = walker->_j;
    }
    else
    {
        place._i = -1;
        place._j = -1;
    }
    return place;
}

Location Creature::find_blank(Creature* world[][MAX])
{
    srand(time(NULL));
    Location* available = new Location[9];
    int size = 0;
    int iStart = this->location._i - 1;
    int iEnd = this->location._i + 1;
    int jStart = this->location._j - 1;
    int jEnd = this->location._j + 1;
    int random = 0;
    Location* walker = available;
    Location place;

    //looking at the surrounding spaces.
    for(int i = iStart; i <= iEnd; i++)
    {
        for(int j = jStart; j <= jEnd; j++)
        {
            if(world[i][j] == NULL)
            {
                size++;
                walker->_i = i;
                walker->_j = j;
                walker++;
            }
        }
    }
    //checking to see if we have any avaiable spaces.
    if(size != 0)
    {
        random = rand() % size;
        walker = available;
        for(int i = 0; i < random; i++)
        {
            walker++;
        }
        place._i = walker->_i;
        place._j = walker->_j;
    }
    else
    {
        place._i = -1;
        place._j = -1;
    }
    return place;
}

Location Creature::get_location()
{
    return this->location;
}
