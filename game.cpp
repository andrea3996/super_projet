#include <iostream>
#include <vector>
#include "game.h"
#include "player.h"
#include "unit.h"
#include "gamemap.h"
#include "mainwindow.h"
#include <typeinfo>
#include <QDebug> // bon pour les qpoint + mieux que cout

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
    this->attaqueMode = false;


    players.push_back(greenPlayer);
    players.push_back(orangePlayer);
    this->lp = greenPlayer;
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


    Cellule* cellule = this->map->getCell(x,y);


    return cellule->getType();
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






/**
 * @brief Game::buy
 * @param type type of object bought
 * @param cell cellule sur laquelle se trouve l'usine quoi !
 */
void Game::buy(std::string type, Cellule* cell){
    //
    int price = this->getUnitCost(type);
    Unit* u = nullptr;
    if (this->lp->hasEnoughMoney(price)) {
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
        } else {
            printf("JE NE DEVRAIS JAMAIS ETRE ICI\n");
            std::cout << std::flush;
        }


        //printf("unite[%s] achete par %s\n", cell->getUnit()->getIdentity().c_str(), cell->getUnit()->getOwner()->getTeamColor().c_str());
        std::cout << std::flush;

        this->lp->buy(price);
        nextPlayer();


    }
    else{
            std::cout << "Vous n'avez pas assez d'argent pour acheter cette unité "<<std::endl;
    }
}
Unit* Game::getUnitSelected(){
    return this->unitSelected;
}

std:: pair<int,int>  Game::play(int xPixel, int yPixel) {

    this->lp = players.at(this->tour);
    std::pair<int,int> cell;
    int x = xPixel / taille_cellule;
    int y = yPixel / taille_cellule;
    cell.first= -1;
    cell.second= -1;

    printf("selected block [%d, %d]\n", x, y);
    std::cout << std::flush;

    if (x >= 0 and  x < this->column  and y >= 0 and y < this->rows)
    {

        cell.first= x;
        cell.second= y;
        Unit* unitClic = this->map->getCell(x,y)->getUnit();
        Building* buildingClic=this->map->getCell(x,y)->getBuilding();
        std::string me = this->lp->getTeamColor();

        if( unitClic != nullptr){


            if(unitClic->getOwner() != this->lp){
                if(this->attaqueMode == true) {
                    unitClic->attaquer();
                    qDebug() << "Unit has been under attack";
                    nextPlayer();

                } else {
                    qDebug() << "It's not your turn to play \n";
                }
            } else {
                if (unitClic->getActionnable()){
                    this->unitSelected = unitClic;
                    if ( true ){
                            this->unitSelected->getListCasesDispo().clear();
                            Cellule* cell = this->map->getCell(this->unitSelected->get_x(), this->unitSelected->get_y());
                            // rajouter la cell aux cases dispos
                            qDebug() << "begin evaluerDeplacement";
                            this->map->evaluerDeplacement(cell,cell, 0);//TODO
                            qDebug() << "user selected an actionable unit";
                            for(CaseDispo* c : this->unitSelected->getListCasesDispo()) {
                                //qDebug() << c->getCelluleDispo() << c->getDistance();
                            }

                    }
                    qDebug() << "user selected a unit \n";
                } else {
                    qDebug() << "yser selected a NON selectable unit\n";
                }
            }






        } else if(buildingClic != nullptr){
            if (buildingClic->getOwner() == this->lp && buildingClic->getType() == "base" ) {
                this->mainWindow->openShopWindow(this->map->getCell(x,y));

            }
            /* else if( buildingClic->getOwner() != players[this->tour])rt
                if( buildingClic is in caseDispo)//TODO
                    attaque();//TODO */
        }else{
            if(this->unitSelected != nullptr && this->attaqueMode == false){ // deplacement

                bool found = false;
                int x2, y2;
                for(std::size_t i = 0; i < unitSelected->getListCasesDispo().size(); i++){
                    if ( unitSelected->getListCasesDispo()[i]->getCelluleDispo().first == cell.first && unitSelected->getListCasesDispo()[i]->getCelluleDispo().second == cell.second  ){
                        x2 = unitSelected->getListCasesDispo()[i]->getCelluleDispo().first;
                        y2 = unitSelected->getListCasesDispo()[i]->getCelluleDispo().second;
                        found = true;
                        break;
                    }
                }
                if(found) {


                    bool userCanAttack = false;
                    for (std::size_t i = 0; i < unitSelected->getListCasesDispo().size(); i++) {
                        int x3 = unitSelected->getListCasesDispo()[i]->getCelluleDispo().first;
                        int y3 = unitSelected->getListCasesDispo()[i]->getCelluleDispo().second;

                        if(this->getMap()->getCell(x3, y3)->getUnit() != nullptr && this->getMap()->getCell(x3, y3)->getUnit()->getOwner() != this->lp){
                            userCanAttack = true;
                        }

                    }

                    this->deplacement(x2,y2);



                    if(userCanAttack){
                        this->mainWindow->openAttaqueWindow();

                    } else {
                        nextPlayer();

                    }
                }
            } else {
                std :: cout << "select a location" << std :: endl;
            }
        }


    }

    return cell;

}

void Game::nextPlayer(){

    this->tour = (this->tour + 1) % static_cast<int>(players.size());
    this->lp = players.at(this->tour);
    this->unitSelected = nullptr;

    this->attaqueMode = false;
    this->mainWindow->update();
}

void Game::deplacement(int x, int y){
    // action se deplacer
    std::cout << unitSelected << std::endl;
    std::cout << unitSelected->get_x() << " --- " << unitSelected->get_y() << std::endl;

    Cellule* destinationCell = this->map->getCell(x,y);
    Cellule* sourceCell = this->map->getCell(unitSelected->get_x(),unitSelected->get_y());
    //1.

    destinationCell->setUnit(unitSelected);
    //    sourceCell->setUnit(nullptr);
    sourceCell->clearUnit();
    this->unitSelected->seDeplacer(x,y);
    std::cout << this->map->getCell(unitSelected->get_x(),unitSelected->get_y())->getUnit() << std::endl;
    this->unitSelected = nullptr;

}

void Game::setAttaqueMode(bool attaqueSelected) {
    this->attaqueMode = attaqueSelected;
    if(this->attaqueMode == false) {
        nextPlayer();
    }
}
