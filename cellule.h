#ifndef CELLULE_H
#define CELLULE_H
#include <iostream>
#include <ostream>
#include <map>
#include "unit.h"
#include "building.h"
#include <vector>
#include <string>

using std:: pair;


class Cellule
{
public:

    Cellule(std::string type, std::vector<int> value, int x, int y);
    Cellule(int x, int y);
    std:: string getType();
    int getDifficulte();
    bool getDeplacement ();
    void clearUnit();

    std::string getLocation();
    //sstd:: vector<int> v(int l); //pas sure
    //std:: map <std::string,std::vector<int> > m; //={std::string s, std::vector<int> v};
    //pair<std:: map <std::string,std::vector<int> >,bool> ret;

    bool getDisponible();
    void setDeplacement(bool a);

    int getValueMP(Unit *unit);

    int test();
    Unit* getUnit();
    void setUnit(Unit *unit);
    //void imprimerLaLisste();

    void setBuilding(Building *building);
    Building* getBuilding();






    int getX() const;

    int getY() const;
    void resetPointsRestants();
    void setPointsRestants(int points);
    int getPointsRestants();

private:

    int x, y;
    int pointsDeCapture;
    int nombre;
    std::vector<int> value;
    std ::string type; //

    Building* building = nullptr;

    int difficulte;
    std::string location;
    static int myints;
    Unit *unit = nullptr;

    int valueMP(Unit *unit);

    bool deplacement;
    std::map<std::string, std::vector<int> >::iterator it;

    bool disponible; // indique si la case est occupé
    int pointsRestants; // points restant au joueur actif après capture

};




#endif // CELLULE_H
