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


Player* Unit::getOwner(){
    return owner;
}

std::vector<CaseDispo *> Unit::getListCasesDispo() const
{
    return listCasesDispo;
}

void Unit::setListCasesDispo(const std::vector<CaseDispo *> &value)
{
    listCasesDispo = value;
}







AntiAir::AntiAir(int x, int y, Player* ow) : Unit(x,y, ow){
    cost=3000;
    valueMP=6;
    this->identity = "AntiAir";
    //std:: string T;
    moveType = 2;


}



Bazooka::Bazooka(int x, int y, Player* ow): Unit(x,y, ow)
{

    cost=3000;
    valueMP=3;
    this->identity = "Bazooka";
//F
    moveType = 0;
    printf("owner of this Bazooka is %s\n", owner->getTeamColor().c_str());

}


// Unités aeriennes:

BCopter::BCopter(int x, int y, Player* ow): Unit(x,y, ow){
    valueMP = 6;
    cost=9000;
    this->identity = "BCopter";
//A
    moveType = 4;

}

Bomber::Bomber(int x, int y, Player* ow): Unit(x,y, ow)
{
    valueMP = 7;
    cost=22000;
    this->identity = "Bomber";
//A
    moveType = 4;
}

Fighter::Fighter(int x, int y, Player* ow): Unit(x,y, ow)
{

    valueMP = 9;
    cost=20000;
    this->identity = "Fighter";
//A
   moveType = 4;
}

// Unités terrestres d'infantrie:

Infantry::Infantry(int x, int y, Player* ow): Unit(x,y, ow)
{
    // Infantery = Bazooka ?


    valueMP = 3;
    cost=1000;
    this->identity = "Infantry";
    moveType = 0; // (F)
}


// Unités terrestres non infantrie :

Recon::Recon(int x, int y, Player* ow): Unit(x,y, ow)
{

    valueMP = 8;
    cost=4000;
    this->identity = "Recon";
// W
    moveType = 3;
}



Tank::Tank(int x, int y, Player* ow): Unit(x,y, ow)
{

    this->valueMP = 6;
    cost=7000;
    this->identity = "Tank";
//T
    moveType = 2;
}

TankM::TankM(int x, int y, Player* ow): Unit(x,y, ow)
{
    valueMP = 5;
    cost=16000;
    this->identity = "TankM";
  //T
    moveType = 2;
}

MegaTank::MegaTank(int x, int y, Player *ow): Unit(x,y, ow)
{
    valueMP = 4;
    cost=28000;
    this->identity = "MegaTank";
    //T
    moveType = 2;
}

NeoTank::NeoTank(int x, int y, Player* ow): Unit(x,y, ow)
{
    valueMP = 6;
    cost=22000;
    this->identity = "NeoTank";
//T
    moveType = 2;
}






