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




Cellule::Cellule(std::string type, std::vector<int> value, int x, int y)
{
    this->type = type;
    this->value= value;
    this->x = x;
    this->y = y;
    this->deplacement = true;
    this->pointsRestants = -1;

}


std:: string  Cellule :: getType()
{
    return this->type;
}


bool Cellule :: getDeplacement()
{
    return this->deplacement;
}

Unit* Cellule :: getUnit()
{
   return this->unit;
}


void Cellule::setUnit(Unit *unit){
    this->unit = unit;
}

void Cellule::clearUnit(){
    if(this->unit != nullptr){
        this->unit = nullptr;
    }

}


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
std::string Cellule::getLocation() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

void Cellule:: setBuilding(Building *building){
    this->building=building;
}

Building* Cellule::getBuilding(){
    return this->building;
}

int Cellule::getX() const
{
    return x;
}

int Cellule::getY() const
{
    return y;
}

void Cellule::resetPointsRestants()
{
    this->pointsRestants = -1;
}

void Cellule::setPointsRestants(int points)
{
    // points restants doit être maximum pour garder le chemin de moindre cout
    if(points > pointsRestants){
        pointsRestants = points;
    }
}

int Cellule::getPointsRestants()
{
    return pointsRestants;
}



    // pour les erreurs en bas, on supprime le dossier "build"
