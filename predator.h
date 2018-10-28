#ifndef PREDATOR_H
#define PREDATOR_H
#include "creature.h"

class predator: public Creature
{
public:
    predator();
    predator(int i, int j, char face);
    void move_hunters(Creature* world[][MAX]);
    void move(Creature* world[][MAX]);
    void breed(Creature* world[][MAX]);
    void Dead(Creature* world[][MAX]);
    void resetFed();
    int get_fed();
    int get_breed();
private:
    int stepsFed;
    int stepsBreed;
};

#endif // PREDATOR_H
