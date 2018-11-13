#ifndef UNITS_H
#define UNITS_H

#include "player.h"


class Unit
{
public:
    Unit(int nx,int ny);
    int get_x();
    int get_y();

    void attaquer();
    void attendre();
    void grouper();
    void seDeplacer();

private:
    int x;
    int y;
    int cost;
    int range;
    int pointsDeVie;
#endif // UNITS_H
