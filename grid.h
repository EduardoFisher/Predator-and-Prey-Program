#ifndef GRID_H
#define GRID_H
#include "creature.h"

class Grid
{
public:
    Grid();
    void show();
    void report();
    void step();
    void reverse();
    Creature* world[MAX][MAX];
};

#endif // GRID_H
