#ifndef GRID_H
#define GRID_H
#include "creature.h"

const int MAX = 22;

class Grid
{
public:
    Grid();
    //~Grid();
    //Grid(const Grid& other);
    Grid operator =(const Grid& other);
    void show();
    void report();
    void step();
private:
    //Creature* world[MAX][MAX];
    int grid[MAX][MAX];
};

#endif // GRID_H
