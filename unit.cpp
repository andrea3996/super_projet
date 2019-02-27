#include "unit.h"


Unit::Unit(int nx,int ny, Player* ow) {
        x=nx;
        y=ny;
        this->owner=ow;
        pointsDeVie=10;
        maxPointsDeVie=10;
}


Unit::Unit(){


}

int Unit :: getMoveType(){
    return this->moveType;
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


/*
void seDeplacer(int x, int y)
{
    map.getCell(this->x, this->y).casesDispo(this, this->mp, 5);
    if (map.getCell(x,y).deplacement)
    {
        this->x = x;
        this->y = y;
    }
}
*/





AntiAir::AntiAir(int x, int y, Player* ow){
    Unit(x,y, ow);
    cost=3000;
    valueMP=6;
    //std:: string T;
    //moveType = string T;


}

void AntiAir::identite() {
    std::cout<< "Nous sommes l'unité AntiAir"<< std::endl;

}


Bazooka::Bazooka(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    cost=3000;
    valueMP=3;

    //moveType = string F;

}


// Unités aeriennes:

BCopter::BCopter(int x, int y, Player* ow){
    Unit(x,y, ow);
    valueMP = 6;
    cost=9000;

    //moveType = string A;

}

Bomber::Bomber(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 7;
    cost=22000;

    //moveType = string A;
}

Fighter::Fighter(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 9;
    cost=20000;

   // moveType =;
}

// Unités terrestres d'infantrie:

Infantery::Infantery(int x, int y, Player* ow)
{
    // Infantery = Bazooka ?

    Unit(x,y, ow);
    valueMP = 3;
    cost=1000;
    //moveType = string F;
}


// Unités terrestres non infantrie :

Recon::Recon(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 8;
    cost=4000;

    //moveType = string W;
}



Tank::Tank(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 6;
    cost=7000;

    //moveType = string T;
}

TankM::TankM(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 5;
    cost=16000;
    //moveType = string T;
}

MegaTank::MegaTank(int x, int y, Player *ow)
{
    Unit(x,y, ow);
    valueMP = 4;
    cost=28000;
    //moveType = string T;
}

NeoTank::NeoTank(int x, int y, Player* ow)
{
    Unit(x,y, ow);
    valueMP = 6;
    cost=22000;
    //moveType = string T;
}




