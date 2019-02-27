#include "cellule.h"
#include "Building.h"
#include <map>

#include <vector>
#include <ostream>
#include <iostream>
#include <QDebug>
using std::map;
using std::pair;
using std::string;
using std::vector;




Cellule::Cellule(std::string type, std::vector<int> value)
{
        this->type = type;
        this->value= value;

       //for (std::map<string, vector<int> >::iterator it = liste.begin(); it != liste.end(); it++){
       //  std::cout << it ->first << ":"<< std::endl;
}


std:: string  Cellule :: getType()
{
    return this->type;
}


bool Cellule :: getDeplacement()
{
    return this->deplacement;
}

Unit *Cellule :: getUnit()
{
    return unit;
}
// Probleme

void Cellule :: setUnit(Unit *unit)
{
    this->unit= unit;
}



/*

int Cellule :: getValueMP(Unit *unit) // s'applique à une cellule. l'unite qui est dessus
{
    return this->valueMP(unit);
}
*/
// /////////////////////////////////////////////////////////////////Attention


void Cellule :: setDeplacement(bool a)
  {
       this->deplacement = a;
  }


bool Cellule :: getDisponible()
  {
       return this->disponible;
  }



int Cellule::getDifficulte()
{
    return this->difficulte;
}

int Cellule::test()
{
    std::map<string,vector<int> > liste;
    liste.insert({"plain",{1,2,3,4,5}});
    std::cout << it ->first << ":"<< std::endl;
    std::cout << "HALO" << std::endl;
    return 0 ;
}
std::string Cellule::getLocation(){
    return ""; // TODO

}


void Cellule:: setBuilding(Building *building){
    this->building=building;
}


/*
void attaquer::attaquer() {
   rect x = position x ;
   rect y = position y ;
   if attacking ;
    positionOriginalUnit;
   else
    positionOriginalUnit=vector(position x,position y);
    direction x = rect x - position x;
    direction y = rect y - position y;
}
*/


    // pour les erreurs en bas, on supprime le dossier "build"



