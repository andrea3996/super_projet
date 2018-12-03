#include <iostream>
#include <vector>
#include "game.h"
#include "player.h"
#include "unit.h"
#include "gamemap.h"


Game::Game()
{
    this->taille_cellule=30;    //TODO
    this->rows = 17;
    this->column = 21;
    //this->map = new GameMap(this->rows,this->column);
    this->players; //TODO = createPlayers();
    this->unitSelected;
    this->units;

}



std:: pair<int,int>  Game::calculer_cellule(int xPixel, int yPixel) {
    std::pair<int,int> cell;
    int x = xPixel/taille_cellule;
    int y= yPixel/taille_cellule;
    cell.first= -1;
    cell.second= -1;
    if (x > 0 and  x < this->column  and y > 0 and y < this->rows)
    {
        cell.first= x;
        cell.second= y;
    }
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
