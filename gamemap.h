#ifndef MAP_H
#define MAP_H
#include <vector>
#include<iostream>
#include <fstream>
using std::ifstream;
#include "cellule.h"
#include "unit.h"

class GameMap
{
    public:
        GameMap(int rows,int column);
        Cellule getCell(int x, int y);
        void casesDispo(Unit unit, int mp,int a, int x, int y);
        std::map<std::string, std::vector<int> > creationDico();
        void creationBoard();
        std::string intTypeToStringType(int value);
        std::vector< std :: vector<Cellule>> * getBoard();
        // Cellule[][]


    private:
        std::vector<int> listeMap(std::ifstream&  fichier);  // attention, fichier n'est pas copiable
        int rows;
        int column;
        std::vector<std::vector<int>> v;
        std :: vector< std :: vector<Cellule>> * board;




};

#endif // MAP_H



