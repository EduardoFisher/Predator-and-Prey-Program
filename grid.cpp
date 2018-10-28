#include "grid.h"
#include "wall.h"
#include "predator.h"
#include "prey.h"
#include "creature.h"
#include <iostream>

using namespace std;

Grid::Grid()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(i == 0 || j == 0 || i == 21 || j == 21)
            {
                world[i][j] = new wall(i, j, 'w');
            }
            else
            {
                if((i > 5 && i < 16) && (j > 5 && j < 16))
                {
                    world[i][j] = new prey(i, j, 'o');
                }
                else
                {
                    world[i][j] = NULL;
                }
            }
        }
    }
    world[5][5] = new predator(5, 5, 'H');
    world[5][11] = new predator(5, 11, 'H');
    world[5][16] = new predator(5, 16, 'H');
    world[16][5] = new predator(16, 5, 'H');
    world[16][16] = new predator(16, 16, 'H');
}

void Grid::show()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(i == 0 || j == 0 || i == 21 || j == 21)
            {
                cout << world[i][j]->get_face() << " ";
            }
            else
            {
                if(world[i][j] == NULL)
                {
                    cout << "-" << " ";
                }
                else
                {
                    cout << world[i][j]->get_face() << " ";
                }
            }
        }
        std::cout << endl;
    }
}

void Grid::step()
{
    //turn 1 hunters.
    //turn 2 prey.
    int turn = 1;
    while(turn < 3)
    {
        for(int i = 1; i < 21; i++)
        {
            for(int j = 1; j < 21; j++)
            {
                if(world[i][j] != NULL)
                {
                    if(turn == 1)
                    {
                        if(world[i][j]->get_face() == 'H')
                        {
                            if(world[i][j]->get_hasMoved() == false)
                            {
                                world[i][j]->move(world);
                            }
                        }
                    }
                    else if(turn == 2)
                    {
                        if(world[i][j]->get_face() == 'o')
                        {
                            if(world[i][j]->get_hasMoved() == false)
                            {
                                world[i][j]->move(world);
                            }
                        }
                    }
                }
            }
        }
        turn++;
    }
    reverse();
}

void Grid::report()
{
    int Prey = 0;
    int Predator = 0;
    for(int i = 1; i < 21; i++)
    {
        for(int j = 1; j < 21; j++)
        {
            if(world[i][j] != NULL)
            {
                if(world[i][j]->get_face() == 'o')
                {
                    Prey++;
                }
                else if(world[i][j]->get_face() == 'H')
                {
                    Predator++;
                }
            }
        }
    }
    cout << "Predators: " << Predator << endl;
    cout << "Prey: " << Prey << endl;
}

void Grid::reverse()
{
    for(int i = 1; i < 21; i++)
    {
        for(int j = 1; j < 21; j++)
        {
            if(world[i][j] != NULL)
            {
                world[i][j]->set_hasMoved();
            }
        }
    }
}
