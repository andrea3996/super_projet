#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "unit.h"
#include "map.h"

#include <vector>
#include <iostream>

class Game
{
private:
    std::vector<Player> players;
    std::vector<Unit> units;
    int taille_cellule;

public:
    Game();
    void crier();
    void set_taille_cellule(int i);
    std::pair<int,int> calculer_cellule(int x, int y);

};


// variable reste ; fonction constructeur redefinir
#endif // GAME_H
