#ifndef PREY_H
#define PREY_H

#include "creature.h"

class prey: public Creature
{
public:
    prey();
    prey(int i, int j, char face);
    void move(Creature* world[][MAX]);
    void breed(Creature *world[][MAX]);
private:
    int stepsBreed; //until 3.
};

#endif // PREY_H
