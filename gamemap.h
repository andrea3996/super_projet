#ifndef MAP_H
#define MAP_H
#include <vector>
#include<iostream>
#include <fstream>
#include "cellule.h"
#include "unit.h"

class GameMap
{
public:
    GameMap();
    Cellule getCell(int x, int y);
    void casesDispo(Unit unit, int mp,int a, int x, int y);
private:
    std::vector<int> listeMap(std::ifstream & fichier);  // attention, fichier n'est pas copiable
    int rows;
    int column;
    std::vector<std::vector<int>> v;

    std :: vector< std :: vector<Cellule>> plateau;




};

#endif // MAP_H



