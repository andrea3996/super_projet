#include "unit.h"

Unit::Unit(int nx,int ny)
// faire constructeur
{
    x=nx;
    y=ny;


}

int Unit::get_x (){
    //redefini la fini dans le header
    return x;
}


int Unit::get_y() {
    return y;
}
