#ifndef CELLULE_H
#define CELLULE_H
#include <iostream>
#include <ostream>
#include <map>
#include "unit.h"
#include <vector>
#include <string>
using std:: pair;


class Cellule
{
public:
    Cellule(std::string type);
    Cellule(int x, int y);

    int getDifficulte();
    std::string getLocation();
    std:: vector<int> v(int l); //pas sure
    std:: map <std::string,std::vector<int>> m; //={std::string s, std::vector<int> v};
    pair<std:: map <std::string,std::vector<int>>,bool> ret;
    bool getDisponible();
    void setDeplacement(bool a);


private:

    int pointsDeCapture;
    int nombre;

    std ::string type;
    bool deplacement;
    bool disponible;

    int difficulte;
    std::string location;
    static int myints;
    Unit *unit;

    int valueMP(Unit *unit);



};




#endif // CELLULE_H
