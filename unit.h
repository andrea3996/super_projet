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
    Bazooka();
};


class BCopter
{
public:
    BCopter();
};

class Bomber
{
public:
    Bomber();
};

class Fighter
{
public:
    Fighter();
};

class Infantery
{
public:
    Infantery();
};

class MegaTank
{
public:
    MegaTank();
};

class NeoTank
{
public:
    NeoTank();
};

class Recon
{
public:
    Recon();
};

class Tank
{
public:
    Tank();
};


class TankM
{
public:
    TankM();
};

#endif // UNITS_H
