#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>

struct Location
{
    Location();
    Location(int i, int j);
    friend std::istream& operator >>(std::istream& is, Location& input);
    int _i;
    int _j;
};

#endif // LOCATION_H
