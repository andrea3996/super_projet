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
    this->map = new GameMap(this->rows,this->column);
    this->players; //TODO = createPlayers();
    this->unitSelected = NULL;
    this->units;

}



std:: pair<int,int>  Game::calculer_cellule(int xPixel, int yPixel) {
    std::pair<int,int> cell;
    int x = xPixel/taille_cellule;
    int y= yPixel/taille_cellule;
    cell.first= -1;
    cell.second= -1;
    if (x >= 0 and  x < this->column  and y >= 0 and y < this->rows)
    {
        cell.first= x;
        cell.second= y;
        std::cout << "buongiorno" <<std::endl;
        std::cout << this->map->getCell(x,y).getType() <<std::endl;
        //std::cout << this->map->getCell(x,y).getType() <<std::endl;

        Unit unitClic = this->map->getCell(x,y).getUnit();

        if( &unitClic != NULL){ // si on a cliqué sur une unité
            this->unitSelected = &unitClic;   // assigner l'unité cliquée à l'attribut unitSelected de Game
            // TODO send to MainWIndow afficher case dispo
        }
        else{                   // si on n'a pas cliqué sur une unit

            if(this->unitSelected != NULL)// si le clic précédent était une unité
            {
                if (this->map->getCell(x,y).getDeplacement()) // et si la case sur laquelle on a cliqué (x,y) est une case disponible au déplacement
                    {
                    this->unitSelected->seDeplacer(x,y); // déplacer l'unité en question en (x,y)
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
