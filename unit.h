#ifndef UNITS_H
#define UNITS_H

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

};


class AntiAir
{
public:
    AntiAir();
};


class Bazooka
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
