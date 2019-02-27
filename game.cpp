#include <iostream>
#include <vector>
#include "game.h"
#include "player.h"
#include "unit.h"
#include "gamemap.h"
#include <typeinfo>
using std::string;




Game::Game()
{
    this->taille_cellule=30;    //TODO
    this->rows = 17;
    this->column = 21;
    this->map = new GameMap(this->rows,this->column);
    //this->players; //TODO = createPlayersga();
    std::vector<Player> * players = new std::vector<Player>();
    players->push_back(*new Player());

    // player possede +ieurs units
    this->unitSelected = nullptr;
    //this->units;
}

std::string Game:: getCellType(int x, int y){
    return this->map->getCell(x,y).getType();
}


std::string Game::getUnitType(int x, int y){
    Unit * u = this->map->getCell(x,y).getUnit();
    std::string f;
    if ( u == nullptr){
        f= "";
    }else{
        f = u->getIdentity();

    }
    return f;
}


int Game::getRows()
{
    return rows;
}

int Game::getColums()
{
    return column;
}

std:: pair<int,int>  Game::calculer_cellule(int xPixel, int yPixel) {

    // Indique si on clique sur une unité ou non et si on peut se deplacer
    //Calcul la position du clic


    std::pair<int,int> cell;
    int x = xPixel/taille_cellule;
    int y= yPixel/taille_cellule;
    cell.first= -1;
    cell.second= -1;
    if (x >= 0 and  x < this->column  and y >= 0 and y < this->rows)
    {
        cell.first= x;
        cell.second= y;
        Unit *unitClic = this->map->getCell(x,y).getUnit();

        Building *buildingClic=this->map->getCell(x,y).getBuilding();


        if(buildingClic != NULL){
            //TODO openShopWindow() open a shopWindow

        }
        else if( unitClic != NULL){ // si on a cliqué sur une unité, si il y a un unit à l'endroit (x,y)
            this->unitSelected = unitClic;  // assigner l'unité cliquée à l'attribut unitSelected de Game
        //  std :: cout << this->unitSelected << std :: endl;// TODO send to MainWIndow afficher case dispo
        }
        else{                   // si on n'a pas cliqué sur une unit

            if(this->unitSelected != NULL)// si le clic précédent était une unité
            {
                if (this->map->getCell(x,y).getDeplacement()) // et si la case sur laquelle on a cliqué (x,y) est une case disponible au déplacement
                    {
                    // this->unitSelected->seDeplacer(x,y); // déplacer l'unité en question en (x,y)
                    }
                else
                {
                    std :: cout << "Cette case n'est pas disponible !" << std :: endl;
                }

            }
            else
            {
                std :: cout << "Il convient à ce stade, de sélectionner une unité" << std :: endl;
            }
        }

    }
    return cell;
}


/*
  void seDeplacer(int x, int y)
{
    map.getCell(this->x, this->y).casesDispo(this, this->mp, 5);
    if (map.getCell(x,y).deplacement)
    {
        this->x = x;
        this->y = y;
    }
}
*/
