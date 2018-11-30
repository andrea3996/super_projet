#include <iostream>
#include <vector>
#include "game.h"
#include "player.h"
#include "unit.h"
#include "gamemap.h"


Game::Game()
{
    this->taille_cellule=30;    //TODO
    this->rows = 21;
    this->column = 17;
    //this->map = new GameMap(this->rows,this->column);
    this->players; //TODO = createPlayers();
    this->units;

}



std:: pair<int,int>  Game::calculer_cellule(int x, int y) {
    std::pair<int,int> cell;
    cell.first= x/taille_cellule;
    cell.second= y/taille_cellule;
    // attention aux bords !
    return cell;
}


/*
 * void seDeplacer(int x, int y)
{
    map.getCell(this->x, this->y).casesDispo(this, this->mp, 5);
    if (map.getCell(x,y).deplacement)
    {
        this->x = x;
        this->y = y;
    }
}
 *
*/
