#include "prey.h"

prey::prey():Creature()
{
    //Nothing needs to be here.
}

prey::prey(int i, int j, char face):Creature(i, j, face)
{
    //Nothing needs to be here.
}

void prey::move(Creature *world[][MAX])
{
    Location new_location = find_blank(world);
    if(new_location._i != -1)
    {
        move_to(world, new_location);
    }
    this->stepsBreed++;
    if(this->stepsBreed > 3)
    {
        breed(world);
    }
}

void prey::breed(Creature *world[][MAX])
{
    Location new_location = find_blank(world);
    if(new_location._i != -1)
    {
         world[new_location._i][new_location._j] = new prey(new_location._i,new_location._j, 'o');
    }
    this->stepsBreed = 0;
}
