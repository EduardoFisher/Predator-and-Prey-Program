#include <iostream>
#include "grid.h"

using namespace std;

int main()
{
    Grid g;
    while(true)
    {
        g.show();
        g.step();
        g.report();
        cin.get();
    }

    return 0;
}
