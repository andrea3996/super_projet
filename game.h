#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "units.h"
#include "map.h"

#include <vector>
#include <iostream>

class Game
{
private:
    std::vector<Player> players;
    std::vector<Units> units;
    int taille_cellule;

public:
    Game();
    void crier();
    void set_taille_cellule(int i);
    pair<int,int> calculer_cellule(int x, int y);

};


// variable reste ; fonction constructeur redefinir
#endif // GAME_H
