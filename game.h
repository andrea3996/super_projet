#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "unit.h"
#include "gamemap.h"
#include "cellule.h"

#include <vector>
#include <iostream>
using std::string;

class Game
{
    private:
        GameMap * map;
        std::vector<Player> players;
        std::vector<Unit> units;
        int taille_cellule;
        int rows;
        int column;
        Unit *unitSelected;

    public:
        Game();
        std::pair<int,int> calculer_cellule(int x, int y);
        std::string getCellType(int x, int y);
};


// variable reste ; fonction constructeur redefinir
#endif // GAME_H
