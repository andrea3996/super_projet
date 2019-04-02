#include "unit.h"
#include <iostream>

Unit::Unit(int nx,int ny, Player* ow) {
        x=nx;
        y=ny;
        this->owner=ow;
        pointsDeVie=10;
        maxPointsDeVie=10;
        identity = "";
}


Unit::Unit(){


}

int Unit :: getMoveType(){
    return this->moveType;
}

std::string Unit :: getIdentity(){
    return this->identity;
}

bool Unit::getActionnable() const
{
    return actionnable;
}

void Unit::setActionnable(bool value)
{
    actionnable = value;
}

int Unit::get_x (){
    return x;
}


int Unit::get_y() {
    return y;
}

int Unit :: getValueMP(){
    return valueMP;
}


void Unit::seDeplacer(int x, int y)
{
    this->x= x;
    this->y= y;
}






AntiAir::AntiAir(int x, int y, Player* ow){
    Unit(x,y, ow);
    cost=3000;
    valueMP=6;
    this->identity = "AntiAir";
    //std:: string T;
    //moveType = string T;


}



Bazooka::Bazooka(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    cost=3000;
    valueMP=3;
    this->identity = "Bazooka";

    //moveType = string F;

}


// Unités aeriennes:

BCopter::BCopter(int x, int y, Player* ow){
    Unit(x,y, ow);
    valueMP = 6;
    cost=9000;
    this->identity = "BCopter";

    //moveType = string A;

}

Bomber::Bomber(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 7;
    cost=22000;
    this->identity = "Bomber";

    //moveType = string A;
}

Fighter::Fighter(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 9;
    cost=20000;
    this->identity = "Fighter";

   // moveType =;
}

// Unités terrestres d'infantrie:

Infantry::Infantry(int x, int y, Player* ow)
{
    // Infantery = Bazooka ?

    Unit(x,y, ow);
    valueMP = 3;
    cost=1000;
    this->identity = "Infantry";
    //moveType = string F;
}


// Unités terrestres non infantrie :

Recon::Recon(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 8;
    cost=4000;
    this->identity = "Recon";

    //moveType = string W;
}



Tank::Tank(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 6;
    cost=7000;
    this->identity = "Tank";

    //moveType = string T;
}

TankM::TankM(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 5;
    cost=16000;
    this->identity = "TankM";
    //moveType = string T;
}

MegaTank::MegaTank(int x, int y, Player *ow)
{
    Unit(x,y, ow);
    valueMP = 4;
    cost=28000;
    this->identity = "MegaTank";
    //moveType = string T;
}

NeoTank::NeoTank(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 6;
    cost=22000;
    this->identity = "NeoTank";
    //moveType = string T;
}




