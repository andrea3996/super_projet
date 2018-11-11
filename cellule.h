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
<<<<<<< HEAD
    //int pointsDeCapture;
    int nombre;
=======
    int pointsDeCapture;
    int difficulte;
    std::string location;
>>>>>>> master

};

#endif // CELLULE_H
