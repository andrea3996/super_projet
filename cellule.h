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
    std:: vector<int> v(int l); //pas sure
    //std::string "s";
    std:: map <std::string,std::vector<int>> m; //={std::string s, std::vector<int> v};

private:

    //int pointsDeCapture;
    int nombre;
    int difficulte;
    std::string location;
    static int myints;

};

#endif // CELLULE_H
