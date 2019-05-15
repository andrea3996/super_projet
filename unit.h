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
        void seDeplacer(int x, int y);
        Unit(int nx,int ny, Player* ow);
        Unit();
        int getMoveType();
        int getValueMP();
        std::string getIdentity();


        bool getActionnable() const;
        void setActionnable(bool value);
        Player* getOwner();

protected:
        int x;
        int y;
        int cost;
        int range;
        int pointsDeVie;
        int maxPointsDeVie;
        int Attacking = false ;
        int moveType;
        int valueMP;

        bool actionnable = true;

        std::string identity = std::string("");

        Player* owner;
};


class AntiAir : public Unit { //essai heritage
    public:
        AntiAir(int x, int y, Player* ow);
};


class Bazooka: public Unit{
    public:
        Bazooka(int x, int y, Player* ow);
};


class BCopter: public Unit{
    public:
        BCopter(int x, int y, Player* ow);
};

class Bomber: public Unit
{
    public:
        Bomber(int x, int y, Player* ow);
};

class Fighter: public Unit
{
    public:
        Fighter(int x, int y, Player* ow);
};

class Infantry: public Unit
{
public:
    Infantry(int x, int y, Player* ow);
};

class MegaTank: public Unit
{
public:
    MegaTank(int x, int y, Player* ow);
};

class NeoTank: public Unit
{
public:
    NeoTank(int x, int y, Player* ow);
};

class Recon: public Unit
{
public:
    Recon(int x, int y, Player* ow);
};

class Tank: public Unit
{
public:
    Tank(int x, int y, Player* ow);
};


class TankM: public Unit
{
public:
    TankM(int x, int y, Player* ow);
};

#endif // UNITS_H
