#include "cellule.h"
#include <map>


Cellule::Cellule(std::string type)
{
    //std:: map <std::string,std::vector<int>> my_map ={"grass", std::vector <int> ({1,1,1,2,1,0,0,0})};
    this->difficulte=1;
    this->location="/Resources/hpipe.gif";




}

int Cellule::getDifficulte()
{
    return this->difficulte;
}


std::string Cellule::getLocation(){
    return ""; // TODO
}

