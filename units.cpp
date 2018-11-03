#include "units.h"

Units::Units(int nx,int ny)
// faire constructeur
{
    x=nx;
    y=ny;


}

int Units::get_x (){
    //redefini la fini dans le header
    return x;
}


int Units::get_y() {
    return y;
}
