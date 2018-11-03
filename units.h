#ifndef UNITS_H
#define UNITS_H

#include "player.h"


class Units
{
public:
    Units(int nx,int ny);
    int get_x();
    int get_y();
private:
    int x;
    int y;
};


#endif // UNITS_H
