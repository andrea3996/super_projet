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




Game::Game() : buildings(std::vector<Building>()), players(std::vector<Player>()), units(std::vector<Unit>())
{
    this->taille_cellule=30;
    this->rows = 17;
    this->column = 21;
    this->map = new GameMap(this);

    players.push_back(Player("green"));
    players.push_back(Player("orange"));
    this->greenPlayer = &players.at(0);
    this->lp = &players.at(0); // green player is local player
    this->orangePlayer = &players.at(1);
    this->unitSelected = nullptr;
    this->map->getCell(1,4)->setUnit(new Recon(1,4, this->lp) );
    std::cout << this->lp << std::endl;
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
        std::cout << u->getIdentity() << std::endl;
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

/*
Building *Game::getBuiling(int x, int y)
{
    for( Building b : buildings){
        if (b.getX() == x && b.getY() == y)  {
            return &b;
            // Renvoit un pointeur vers le building afin de pouvoir le modifier par apres
        }

    }
    return nullptr;
    // Attention utilisation
}*/


std::pair<int,int> calculer_unit(int x, int y){

}




void Game::buy(std::string type, Cellule* cell){
    int cost = this->getUnitCost(type);
    // TODO: En fonction du type, vérifier si le cout est suffisant et construire l'unité en conséquence
    Unit* u;
    if (cost <= this->lp->getMoney()) {
        //Pq pas faire un switch ?
        if (type == "Infantry") {
            u = new Infantry(cell->getX(), cell->getY(), lp);
        }
        if (type == "Recon") {
            u = new Recon(cell->getX(), cell->getY(), lp);
        }
        if (type == "Tank") {
            u = new Tank(cell->getX(), cell->getY(), lp);
        }
        if (type == "TankM") {
            u = new TankM(cell->getX(), cell->getY(), lp);
        }
        if (type == "AntiAir") {
            u = new AntiAir(cell->getX(), cell->getY(), lp);
        }
        if (type == "BCopter") {
            u = new BCopter(cell->getX(), cell->getY(), lp);
        }
        if (type == "BCopter") {
            u = new BCopter(cell->getX(), cell->getY(), lp);
        }
        if (type == "Bomber") {
            u = new Bomber(cell->getX(), cell->getY(), lp);
        }
        if (type == "Fighter") {
            u = new Fighter(cell->getX(), cell->getY(), lp);
        }
        if (type == "MegaTank") {
            u = new MegaTank(cell->getX(), cell->getY(), lp);
        }
        if (type == "NeoTank") {
            u = new NeoTank(cell->getX(), cell->getY(), lp);
        }
        if (type == "Bazooka") {
            u = new Bazooka(cell->getX(), cell->getY(), lp);
        }

    }
    else{
            std::cout << "Vous n'avez pas assez d'argent pour acheter cette unité "<<std::endl;
        }
}

std:: pair<int,int>  Game::calculer_cellule(int xPixel, int yPixel) {
    std::cout << "calculer cellule appelé" << std::endl;
    // Indique si on clique sur une unité ou non et si on peut se deplacer
    //Calcul la position du clic


    std::pair<int,int> cell;
    int x = xPixel/taille_cellule;
    int y= yPixel/taille_cellule;
    cell.first= -1;
    cell.second= -1;
    if (x >= 0 and  x < this->rows  and y >= 0 and y < this->column) // /// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    {

        cell.first= x;
        cell.second= y;
        Unit* unitClic = this->map->getCell(x,y)->getUnit();

        Building* buildingClic=this->map->getCell(x,y)->getBuilding();
        std::cout << "type of cell : "<<this->getCellType(x,y) << std::endl;

        if(buildingClic != nullptr){
            std::cout << "building clic condition passé" << std::endl;
            std::cout << buildingClic->getOwner() << " " << this->lp << " " << buildingClic->getType() << std::endl;
            std::cout << buildingClic->getOwner() << " " << this->getOrangePlayer() << " " << buildingClic->getType() << std::endl;
            if (buildingClic->getOwner() == this->lp && buildingClic->getType() == "base" ) {
                // pas d'egalité gameMap cf

                this->mainWindow->openShopWindow(this->map->getCell(x,y)); //open a shopWindow
                std::cout << "Unit clic condition passé" << std::endl;
            }
        } else {
            std::cout << "buildingclic in nullptr" << std::endl;
        }
        if( unitClic != nullptr){ // si on a cliqué sur une unité, si il y a un unit à l'endroit (x,y)
            if (unitClic->getActionnable()){
                this->unitSelected = unitClic;  // assigner l'unité cliquée à l'attribut unitSelected de Game
                //this->mainWindow->showMovementOf(unitClic);
                //TODO
            }
        //  std :: cout << this->unitSelected << std :: endl;// TODO send to MainWIndow afficher case dispo
        }
        else{                   // si on n'a pas cliqué sur une unit

            if(this->unitSelected != NULL)// si le clic précédent était une unité
            {
                if (this->map->getCell(x,y)->getDeplacement()) // et si la case sur laquelle on a cliqué (x,y) est une case disponible au déplacement
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
    std::cout << "calucler cellule terminé " << std::endl;
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
