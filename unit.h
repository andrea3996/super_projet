#ifndef UNITS_H
#define UNITS_H

#include "player.h"


class Unit
{
public:
    Unit(int nx,int ny);
    int get_x();
    int get_y();
private:
    int x;
    int y;
};


#endif // UNITS_H
