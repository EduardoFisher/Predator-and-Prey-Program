#include "grid.h"
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
                grid[i][j] = 8;
            }
            else
            {
                grid[i][j] = 0;
            }
        }
    }
}

//Grid::~Grid()
//{

//}

void Grid::show()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(i == 0 || j == 0 || i == 21 || j == 21)
            {

            }
            else
            {
                std::cout << grid[i][j] << " ";
            }
        }
        std::cout << endl;
    }
}

//Grid::Grid(const Grid &other)
//{

//}

//Grid::operator =(const Grid& other)
//{

//}
