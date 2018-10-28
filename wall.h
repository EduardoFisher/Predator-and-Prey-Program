#ifndef WALL_H
#define WALL_H
#include "creature.h"


class wall: public Creature
{
public:
    wall();
    wall(int i, int j, char face);
};

#endif // WALL_H
