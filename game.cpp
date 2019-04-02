#include <iostream>
#include <vector>
#include "game.h"
#include "player.h"
#include "unit.h"
#include "gamemap.h"
#include "mainwindow.h"
#include <typeinfo>
using std::string;




Player* Game::getLp()
{
    return this->lp;
}

void Game::setLp( Player * value)
{
    this->lp = value;
}

GameMap *Game::getMap()
{
    return this->map;
}




Game::Game() : buildings(std::vector<Building>()), players(std::vector<Player*>()), units(std::vector<Unit>())
{
    greenPlayer = new Player("green");
    orangePlayer = new Player("orange");
    this->taille_cellule=30;
    this->rows = 17;
    this->column = 21;
    this->map = new GameMap(this);
    this->tour = 0;



    players.push_back(greenPlayer);
    players.push_back(orangePlayer);
    this->lp;
    this->unitSelected = nullptr;
}

Player* Game::getGreenPlayer()
{
    return this->greenPlayer;
}

Player* Game::getOrangePlayer()
{
    return this->orangePlayer;
}



Game::~Game()
{
    delete map;
}

void Game::setMainWindow(MainWindow *mw)
{
    this->mainWindow = mw;
}

std::string Game:: getCellType(int x, int y){
    return this->map->getCell(x,y)->getType();
}


std::string Game::getUnitType(int x, int y){
    Unit * u = this->map->getCell(x,y)->getUnit();
    std::string f = "";
    if ( u != nullptr){
        f = u->getIdentity();
    }
    return f;
}

int Game::getRows()
{
    return rows;
}
int Game::getTailleCellule()
{
    return taille_cellule;
}

int Game::getColums()
{
    return column;
}

int Game::getUnitCost(std::string type)
{
    //TODO: en fonction du type retourner la bonne valeur
    return 1000;
}


std::pair<int,int> calculer_unit(int x, int y){ //Plus besoin

}


void Game::buy(std::string type, Cellule* cell){
    int cost = this->getUnitCost(type);
    Unit* u = nullptr;
    if (cost <= this->lp->getMoney()) {
        if (type == "Infantry") {

            u = new Infantry(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "Recon") {
            u = new Recon(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "Tank") {
            u = new Tank(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else  if (type == "TankM") {
            u = new TankM(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "AntiAir") {
            u = new AntiAir(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "BCopter") {
            u = new BCopter(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "BCopter") {
            u = new BCopter(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "Bomber") {
            u = new Bomber(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "Fighter") {
            u = new Fighter(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "MegaTank") {
            u = new MegaTank(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "NeoTank") {
            u = new NeoTank(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }
        else if (type == "Bazooka") {
            u = new Bazooka(cell->getX(), cell->getY(), lp);
            cell->setUnit(u);
        }

    }
    else{
            std::cout << "Vous n'avez pas assez d'argent pour acheter cette unité "<<std::endl;
    }
}

std:: pair<int,int>  Game::calculer_cellule(int xPixel, int yPixel) {

    this->lp = players[this->tour];
    std::pair<int,int> cell;
    int x = xPixel/taille_cellule;
    int y= yPixel/taille_cellule;
    cell.first= -1;
    cell.second= -1;

    if (x >= 0 and  x < this->rows  and y >= 0 and y < this->column)
    {

        cell.first= x;
        cell.second= y;
        Unit* unitClic = this->map->getCell(x,y)->getUnit();
        Building* buildingClic=this->map->getCell(x,y)->getBuilding();
        if( unitClic != nullptr){
            if (unitClic->getActionnable()){
                this->unitSelected = unitClic;
            }
        }else if(buildingClic != nullptr){
            if (buildingClic->getOwner() == this->lp && buildingClic->getType() == "base" ) {
                this->mainWindow->openShopWindow(this->map->getCell(x,y));
            }
            /* else if( buildingClic->getOwner() != players[this->tour])
                if( buildingClic is in caseDispo)//TODO
                    attaque();//TODO */
        }else{
            if(this->unitSelected != NULL){
                if (this->map->getCell(x,y)->getDeplacement()){
                        this->deplacement(x,y);
                    }
                else{
                    std :: cout << "Cette case n'est pas disponible !" << std :: endl;
                }

            }else{
                std :: cout << "Il convient à ce stade, de sélectionner une unité" << std :: endl;
            }
        }

    }
    return cell;

}

void Game::deplacement(int x, int y){

    std::cout << unitSelected << std::endl;
    std::cout << unitSelected->get_x() << " --- " << unitSelected->get_y() << std::endl;

    this->map->getCell(x,y)->setUnit(unitSelected);
    this->map->getCell(unitSelected->get_x(),unitSelected->get_y())->setUnit(nullptr);
    this->unitSelected->seDeplacer(x,y);
    std::cout << this->map->getCell(unitSelected->get_x(),unitSelected->get_y())->getUnit() << std::endl;
    this->unitSelected = nullptr;

}

