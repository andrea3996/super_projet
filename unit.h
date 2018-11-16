#ifndef UNITS_H
#define UNITS_H
#include <iostream>
#include "player.h"
//polymorphisme = tableau d'objets


class Unit{
public:

    int get_x();
    int get_y();

    void attaquer();
    void attendre();
    void grouper();
    void seDeplacer();
    Unit(int nx,int ny, Player* ow);
    Unit();


protected:
    int x;
    int y;
    int cost;
    int range;
    int pointsDeVie;
    int maxPointsDeVie;
    int vector = (0,0);
    int Position =  (x,y);
    int Rect = (x,y);
    int PositionOriginalUnit = (0,0);
    int Attacking = false ;

    Player* owner;
};


class AntiAir : public Unit { //essai heritage
public:
    AntiAir(int x, int y, Player* ow);
    void identite();
};


class Bazooka: public Unit
{
public:
    Bazooka(int x, int y, Player* ow);
};


class BCopter
{
public:
    BCopter(int x, int y, Player* ow);
};

class Bomber
{
public:
    Bomber(int x, int y, Player* ow);
};

class Fighter
{
public:
    Fighter(int x, int y, Player* ow);
};

class Infantery
{
public:
    Infantery(int x, int y, Player* ow);
};

class MegaTank
{
public:
    MegaTank(int x, int y, Player* ow);
};

class NeoTank
{
public:
    NeoTank(int x, int y, Player* ow);
};

class Recon
{
public:
    Recon(int x, int y, Player* ow);
};

class Tank
{
public:
    Tank(int x, int y, Player* ow);
};


class TankM
{
public:
    TankM(int x, int y, Player* ow);
};

#endif // UNITS_H
