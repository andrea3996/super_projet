#include "cellule.h"


Cellule::Cellule(std::string type)
{
    this->difficulte=1;
    this->location="/Resources/hpipe.gif";


}

int Cellule::getDifficulte()
{
    return this->difficulte;
}


std::string Cellule::getLocation()
{

}
