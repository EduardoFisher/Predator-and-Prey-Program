#ifndef CREATURE_H
#define CREATURE_H
#include "location.h"

const int MAX = 22;

class Creature
{
public:
    Creature();
    Creature(int i, int j, char face);
    virtual void move(Creature* world[][MAX]);
    virtual void breed(Creature* world[][MAX]);
    void move_to(Creature *world[][MAX], Location loca);
    char get_face();
    bool get_hasMoved();
    void set_hasMoved();
    void isBreeding(Creature* world[][MAX], int steps);
    Location find_blank(Creature* world[][MAX]);
    Location find_prey(Creature* world[][MAX]);
    Location get_location();
private:
    char _face;
    bool has_moved = false;
    Location location;
};

#endif // CREATURE_H
