#ifndef CELLULE_H
#define CELLULE_H
#include <iostream>
#include <map>

class Cellule
{
public:
    Cellule(std::string type);
    int getDifficulte();
    std::string getLocation();
private:

    //int pointsDeCapture;
    int nombre;
    int difficulte;
    std::string location;
};

#endif // CELLULE_H
