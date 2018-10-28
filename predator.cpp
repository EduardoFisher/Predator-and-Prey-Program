#include "predator.h"
#include "grid.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

predator::predator():Creature()
{
    //nothing needs to be here.
}

predator::predator(int i, int j, char face):Creature(i, j, face)
{
    stepsFed = 0; // until 3 then die.
    stepsBreed = 0; // until 8 then reset.
}

void predator::move(Creature* world[][MAX])
{
    Location new_location = find_prey(world);

    if(new_location._i != -1)
    {
        move_to(world, new_location);
        resetFed();
    }
    else
    {
         new_location = find_blank(world);
         if(new_location._i != -1)
         {
            move_to(world, new_location);
         }
    }
    this->stepsFed++;
    this->stepsBreed++;
    if(stepsBreed > 8)
    {
        breed(world);
    }
    if(stepsFed > 3)
    {
        Dead(world);
    }
}

void predator::Dead(Creature *world[][MAX])
{
    delete world[this->get_location()._i][this->get_location()._j];
    world[this->get_location()._i][this->get_location()._j] = NULL;
}

void predator::breed(Creature *world[][MAX])
{
    Location new_location = find_blank(world);
    if(new_location._i != -1)
    {
        world[new_location._i][new_location._j] = new predator(new_location._i, new_location._j, 'H');
    }
    this->stepsBreed = 0;
}

int predator::get_fed()
{
    return this->stepsFed;
}

int predator::get_breed()
{
    return this->stepsBreed;
}

void predator::resetFed()
{
    this->stepsFed = 0;
}
