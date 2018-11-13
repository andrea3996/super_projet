#include "unit.h"


Unit::Unit(int nx,int ny, Player* ow) {
        x=nx;
        this->owner = ow;
        y=ny;
        pointsDeVie=10;
        maxPointsDeVie=10;

}

int Unit::get_x (){
    //redefini la fini dans le header
    return x;
}


int Unit::get_y() {
    return y;
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

/*Bazooka::Bazooka()
{
    Unit(x,y, ow);

}
*/
BCopter::BCopter()
{

}

Bomber::Bomber()
{

}

Fighter::Fighter()
{

}

Infantery::Infantery()
{

}

MegaTank::MegaTank()
{

}

NeoTank::NeoTank()
{

}

Recon::Recon()
{

}

Tank::Tank()
{

}

TankM::TankM()
{

}
