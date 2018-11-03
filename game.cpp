#include <iostream>
#include <vector>
#include "game.h"
#include "player.h"
#include "unit.h"
#include "map.h"


Game::Game()
{

}

void Game::crier()
{
    std::cout << "yaaaaaaa" << std::endl;
}

void Game::set_taille_cellule(int i)
{
    taille_cellule = i;
}

std:: pair<int,int>  Game::calculer_cellule(int x, int y) {
    std::pair<int,int> cell;
    cell.first= x/taille_cellule;
    cell.second= y/taille_cellule;

    return cell;
}

