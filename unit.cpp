#include "unit.h"


Unit::Unit(int nx,int ny, Player* ow) {
        x=nx;
        this->owner = ow;
        y=ny;
        pointsDeVie=10;
        maxPointsDeVie=10;

}



int Unit :: getMoveType()
{
    return this->moveType;
}


int Unit::get_x (){
    //redefini la fini dans le header
    return x;
}


int Unit::get_y() {
    return y;
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
} */

void seDeplacer(int x,int y)
{

}


Unit::Unit(){

}

AntiAir::AntiAir(int x, int y, Player* ow){
    Unit(x,y, ow);
    cost=3000;
    this->owner = ow;


}

void AntiAir::identite() {
    std::cout<< "Nous sommes l'unité AntiAir"<< std::endl;

}

Bazooka::Bazooka(int x, int y, Player* ow)
{
    Unit(x,y, ow);

}

BCopter::BCopter(int x, int y, Player* ow)
{
    Unit(x,y, ow);

}

Bomber::Bomber(int x, int y, Player* ow)
{
    Unit(x,y, ow);
}

Fighter::Fighter(int x, int y, Player* ow)
{
    Unit(x,y, ow);
}

Infantery::Infantery(int x, int y, Player* ow)
{
    Unit(x,y, ow);
}

MegaTank::MegaTank(int x, int y, Player *ow)
{
    Unit(x,y, ow);
}

NeoTank::NeoTank(int x, int y, Player* ow)
{
    Unit(x,y, ow);
}

Recon::Recon(int x, int y, Player* ow)
{
    Unit(x,y, ow);
}

Tank::Tank(int x, int y, Player* ow)
{
    Unit(x,y, ow);
}

TankM::TankM(int x, int y, Player* ow)
{
    Unit(x,y, ow);
}
