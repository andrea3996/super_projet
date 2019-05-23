#ifndef MAP_H
#define MAP_H
#include <vector>
#include <map>
#include<iostream>
#include <fstream>
#include "cellule.h"
#include "unit.h"
using std::ifstream;

class Game;

struct Location {
    Location(int x, int y): xPosition(x), yPosition(y){}
    int xPosition;
    int yPosition;
};

class GameMap
{
    public:
        GameMap(Game* game);
        ~GameMap();
        Cellule* getCell(int x, int y);
        void casesDispo(Unit unit, int mp,int a, int x, int y);
        std::map<std::string, std::vector<int> > creationDico();
        void creationBoard();
        std::string intTypeToStringType(int value);
        std::vector< std :: vector<Cellule>> getBoard();
        void condCaseDispo(Unit unit,int mp, int x, int y, int a, int b, int c);
        // Cellule[][]
        void createBuilding(Cellule* cell,std::string type);
        void evaluerDeplacement(Cellule* source, Cellule* celluleCourante, int pointsActuels);
        Cellule* getCellIfExists(int x, int y);



    private:
        Game* game;
        //std::vector<int> listeMap(std::ifstream&  fichier);  // attention, fichier n'est pas copiable
        std::vector<std::vector<int>> v; // ?????????????????????
        std::vector<std::vector<Cellule*>> board;
        std::map<int, Cellule*> celluleBoard;
        std::map<std :: string, std :: vector<int> > dico;

        void continuerEvaluation(Cellule* source, int x_destination, int y_destination, Cellule* celluleCourante, int pointsActuels);



};

#endif // MAP_H






