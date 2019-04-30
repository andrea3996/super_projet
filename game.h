#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "unit.h"
#include "gamemap.h"
#include "cellule.h"

#include <vector>
#include <iostream>
using std::string;

class MainWindow;

class Game
{
    private:
        MainWindow* mainWindow = nullptr;
        GameMap * map;
        std::vector<Player*> players;
        std::vector<Unit> units;
        int taille_cellule;
        int rows;
        int column;
        Unit *unitSelected = nullptr;
        std::vector<Building> buildings;
        int tour;
        void deplacement(int x, int y);
        void nextPlayer();



    public:
        Game();
        ~Game();
        void setMainWindow(MainWindow* mw);
        std::pair<int,int> play(int x, int y);
        std::string getCellType(int x, int y);
        std::string getUnitType(int x, int y);
        int getRows();
        int getColums();
        std::pair<int,int> calculer_unit(int x, int y);
        int getTailleCellule();
        Player* lp;
        Player* orangePlayer;
        Player* greenPlayer;
        int getUnitCost(std::string type);


        void buy(std::string type, Cellule* cell);
        //Building *getBuiling(int x, int y );
        // Verifie si Builidng sur (x,y)

        Player* getLp();
        void setLp(Player * value);

        GameMap* getMap();
        Player* getOrangePlayer();
        Player* getGreenPlayer();
};
// variable reste ; fonction constructeur redefinir
#endif // GAME_H

// Dimensionner fenetre
