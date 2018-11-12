#ifndef CELLULE_H
#define CELLULE_H
#include <iostream>
#include <map>
#include <vector>

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
    static int myints;
    std:: vector<int> v(int myints);
};

#endif // CELLULE_H
