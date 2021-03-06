#include <iostream>
#include<fstream>
#include <string>
#include <set>
#include <vector>
#include <sstream>

//#include <windows.h>
#include "gamemap.h"
#include "cellule.h"
#include "building.h"
#include "game.h"

#include"QFile"

#include "QString"
#include "QChar"
#include "QMessageBox"
#include "QTextStream"

using namespace std;
using std::ifstream;
using std::string;
using std::stoi;


GameMap::GameMap(Game* game){ // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    this->game = game;
    this->board = {};
    this->celluleBoard = {};
    this->creationBoard();
    this->dico = this->creationDico();
    // modifier attribut board
}

GameMap::~GameMap()
{

}

/* Création du dictionnaire dont la clef est un type
 * de case et la valeur une liste d'entiers.
 *
 * L'indice des éléments de la liste correspond à un
 * type de mouvement d'unités (moveType,
 * attribut int).
 *
 * L'élément de la liste correspond au nombre de points
 * de déplacement retranchés quand une unité de moveType
 * égale à l'indice de l'élément, traverse une case décrite
 * par la clef de cette liste.
 *
 * Exemple : Si une unité de moveType = 0 traverse une
 * case "plain", elle se voit retrancher 1 point de movePoint.
 *
 *           Si une unité de moveType = 3 traverse une
 * case "wood", elle se voit retrancher 3 points de movePoints.
 *
 **/
std::map<string, vector<int> > GameMap::creationDico(){
    std::map<string, vector<int> > dico;
    dico.insert({"plain", {1,1,1,2,1,0,0,0} });
    dico.insert({"mountain", {2,1,0,0,1,0,0,0}});
    dico.insert({"wood",{1,1,2,3,1,0,0,0}});
    dico.insert({"hpipe", {0,0,0,0,0,0,0,1}});
    dico.insert({"river", {2,1,0,0,1,0,0,0}});
    dico.insert({"hroad",{1,1,1,1,1,0,0,0}});
    dico.insert({"sea",{2,1,0,0,1,0,0,0}}); // Verifier valeur
    dico.insert({"hshoal",{0,0,0,0,0,0,0,0}});
    dico.insert({"reef",{0,0,0,0,1,2,2,0}});
    dico.insert({"hbridge",{0,0,0,0,1,2,2,0}});


    dico.insert({"city", {1,1,1,1,1,0,0,0}}); //
    dico.insert({"airport",{1,1,1,1,1,0,0,0}});
    dico.insert({"base",{1,1,1,1,1,0,0,1}});

    dico.insert({"greenearthcity", {1,1,1,1,1,0,0,0}}); //
    dico.insert({"greenearthbase", {1,1,1,1,1,0,0,0}}); //
    dico.insert({"greenearthairport", {1,1,1,1,1,0,0,0}}); //

    dico.insert({"orangestarcity", {1,1,1,1,1,0,0,0}}); //
    dico.insert({"orangestarbase", {1,1,1,1,1,0,0,0}}); //
    dico.insert({"orangestarairport", {1,1,1,1,1,0,0,0}}); //

    return dico;
}


int GameMap::identifier(int x, int y){
    return x * 1000 + y;
}


/* Lit le fichier texte caractère après caractère.
 *
 * Concatène les caractères séparés d'une virgule,
 * traduit le résultat en Cell et ajoute chacun dans
 * un vecteur de Cell.
 *
 * Chaque fois qu'une ligne du fichier est lue, traduite
 * et inclue dans un vecteur de Cell, ce vecteur est alors
 * ajouté dans un vecteur de vecteur de Cell.
 *
 * C'est un tableau d'un jeu.
 */
void GameMap::creationBoard()

{
    std::map<string, vector<int> > dico = this->creationDico();

    QString fileName = ":/maps/map1.txt";
    QFile fichier(fileName);

    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QChar mot;
    string intType="";
    std::string type;
    type = "";
    int x=0;
    int y=0;
    std::vector<Cellule*> * cells = new vector<Cellule*>();


    while(! flux.atEnd())
    {
            flux >> mot;
            if (mot == ',')
            {
                x += 1 ;

                int typeInteger = stoi(type);
                string stringType = this->intTypeToStringType(typeInteger);
                std::vector<int> value = dico[stringType];
                Cellule* cell = new Cellule( stringType, value, x, y);
                createBuilding(cell, stringType);

                celluleBoard[identifier(x,y)] = cell;

                cells->push_back(cell);
                type = "";

            }
            else if(mot == '\n')
            {
                // cout << "max columns (x) = " << x << endl;
                x = 0;

                int typeInteger = stoi(type);
                string stringType = this->intTypeToStringType(typeInteger);
                std::vector<int> value = dico[stringType];
                Cellule* cell = new Cellule( stringType, value,x,y);
                createBuilding(cell, stringType);
                cells->push_back(cell);
                celluleBoard[identifier(x,y)] = cell;

                this->board.push_back(*cells);
                cells = new vector<Cellule*>();
                type = "";
                y += 1 ;

            }
            else if (mot == -1)
            {
                break;
            }
            else
            {
                int a = mot.toLatin1();
                intType = a;
                type += intType;

             }



        //fichier.close(); //TODO

    }
    // printf("max rows (y) = %d\n", y);

    bool error = false;
    for (int x = 0; x < 21; x++) {
        for (int y = 0; y < 17; y++) {
            if(celluleBoard.find(identifier(x, y)) == celluleBoard.end()){
                // printf("cellule [%d,%d] is not loaded\n", x, y);
                // std::cout << std::flush;
                error = true;
            }
        }
    }

    if(error){
        exit(4);
    }
}


void GameMap::createBuilding(Cellule* cell,std::string type){
    if(type == "airport") {
        cell->setBuilding(new Airport());

    } else if (type=="base") {
        cell->setBuilding(new Base());

    } else if (type=="city") {
        cell->setBuilding(new City());

    } else if (type == "orangestarcity") {
        City* city = new City();
        city->setOwner(this->game->getOrangePlayer());
        cell->setBuilding(city);

    } else if (type == "orangestarairport") {
        Airport* airport = new Airport();
        airport->setOwner(this->game->getOrangePlayer());
        cell->setBuilding(airport);

    } else if (type=="greenearthcity") {
        City* city = new City();
        city->setOwner(this->game->getGreenPlayer());
        cell->setBuilding(city);

    } else if (type=="greenearthairport") {
        Airport* airport = new Airport();
        airport->setOwner(this->game->getGreenPlayer());
        cell->setBuilding(airport);

    } else if (type=="greenearthbase") {
        Base* base = new Base();
        base->setOwner(this->game->getGreenPlayer());
        cell->setBuilding(base);

    } else if (type=="orangestarbase") {
        Base* base = new Base();
        base->setOwner(this->game->getOrangePlayer());
        cell->setBuilding(base);

    }


}


// Convertit les entiers qui se réfèrent à un type de case (Cell) en un String
string GameMap::intTypeToStringType(int value)
{
    string type = "";
    switch(value){
        case 1:
            type = "plain";
            break;

        case 2:
            type = "mountain";
            break;

        case 3:
            type = "wood";
            break;

        case 4: case 5: case 7: case 8: case 9: case 10:
           type = "river";
           break;

        case 101: case 104: case 102: case 106: case 107: case 108: case 109: case 110:
            type = "hpipe";
            //hpipe Cellule(3,"hpipe.gif")
            break;

        case 95: case 91:
            type = "greenearthcity";
            break;
        case 92:
            type = "greenearthbase";
            break;
        case 93:
            type = "greenearthairport";
            break;
        case 15: case 16: case 18: case 19: case 20: case 21: case 22: case 23: case 24: case 25:
            type = "hroad";
            break;
        case 30: //28
            type = "sea";
            break;
        case 29:
            type = "hshoal";
            break;
        case 33:
            type = "reef";
            break;
        case 35: // neutral ////////////////
            type = "base";
            break;
        case 36: // neutral
            type = "airport";
            break;
        case 34:
            type = "city";
            // neutral city
            break;
        case 125: case 124: // Os city /////////////
            type = "orangestarcity";
            break;
        case 123: //
            type = "orangestarbase";
            break;
        case 122:
            type = "orangestarairport";
            break;

        case 26:
            type = "hbridge";
            break;
        /*case 125:
            type = "city";
        break;*/

        default:
            type= "hpipe";
    }
    if (type=="") {
        std::cout << "cellule mal définie pour id " << value << std::endl;
    }
    return type;
}






Cellule* GameMap::getCell(int x, int y){
    //std::cout << "Ca fait:"<<x+1 <<" "<< y+1 << std::endl;

    if(celluleBoard.find(identifier(x,y)) == celluleBoard.end()){
        cout << "cellule does not exist at location [" << x << ", " << y << "] for a size =" << celluleBoard.size() << endl;
        exit(0);
    }

    return celluleBoard.find(identifier(x,y))->second;


    //return (this->board)[x][y]; // le premier = colonne
}



void GameMap::continuerEvaluation(Cellule* source, int x_destination, int y_destination, Cellule* celluleCourante, int distanceCourante)
// check if case available
{
    if(x_destination >= 0 && y_destination >= 0 && x_destination < game->getColums() && y_destination < game->getRows()){

        Cellule* prochaineCelluleCourante = getCell(x_destination, y_destination);

        std::cout  << " " << prochaineCelluleCourante->getType() << " " << source->getUnit()->getMoveType() << endl;;
        if(this->dico.count(prochaineCelluleCourante->getType()) == 0){
            std::cerr << "dico ne contient pas " << prochaineCelluleCourante->getType() << endl;
        }
        int movePoint = this->dico[prochaineCelluleCourante->getType()][source->getUnit()->getMoveType()];
        if(movePoint == 0) {
            return;
        }
        std::cout << "(" << x_destination << ", " << y_destination << ") movepoint:" << movePoint << std::endl;

        if(source->getX() != x_destination || source->getY() != y_destination){ // if la destination n'existe pas déjà dans la liste des cases dispos
            int distanceDestination = distanceCourante + movePoint;
            std::pair <int, int > destination = {x_destination,y_destination};

            if(distanceDestination <= source->getUnit()->getValueMP()){
                bool isInList = false;
                for (std::size_t i = 0; i < source->getUnit()->getListCasesDispo().size(); ++i){
                    // vector<CaseDispo> !! logique
                    if ( source->getUnit()->getListCasesDispo()[i]->getCelluleDispo() == destination ){
                        isInList = true;
                        if(distanceDestination < source->getUnit()->getListCasesDispo()[i]->getDistance()){
                            std::cout << "size" << source->getUnit()->getListCasesDispo().size()<< std::endl;
                             source->getUnit()->getListCasesDispo()[i]->getCelluleDispo()= {prochaineCelluleCourante->getX(),prochaineCelluleCourante->getY()};
                             source->getUnit()->getListCasesDispo()[i]->getCellulePrecedente()= { celluleCourante->getX(), celluleCourante->getY()};
                             source->getUnit()->getListCasesDispo()[i]->setDistance(distanceDestination);
                             evaluerDeplacement(source, prochaineCelluleCourante, distanceDestination);
                        } // NOT ELSE, chemin plus court déjà rencontré
                        break;
                    }
                 }

                 if (not isInList){
                        std::cout << "size " << source->getUnit()->getListCasesDispo().size()<< std::endl;
                        CaseDispo * caseDispo = new CaseDispo(); //TODO allocation mémoire

                        caseDispo->getCelluleDispo() = {prochaineCelluleCourante->getX(),prochaineCelluleCourante->getY()};
                        caseDispo->getCellulePrecedente() = { celluleCourante->getX(), celluleCourante->getY()};
                        caseDispo->setDistance(distanceDestination);
                        source->getUnit()->getListCasesDispo().push_back(caseDispo);
                        std::cout << "size ---------" << source->getUnit()->getListCasesDispo().size()<< std::endl;
                        evaluerDeplacement(source, prochaineCelluleCourante, distanceDestination);
                  }

            } //NOT ELSE, on n'est pas capable d'atteindre la case convoitée
            else{
                cout << ("condition d'arret distanceDestination dépassé") << endl;;
            }
        } else {
             cout << ("condition d'arret meme case") << endl;;
        }
    } else {
        cout << ("condition d'arret hors case") << endl;
    }
}


Cellule* GameMap::getCellIfExists(int x, int y)
{
    if(x > 0 && y > 0 && x < game->getColums() && y < game->getRows()){
        return getCell(x, y);
    }
    else {
        return nullptr;
    }

}

void GameMap::evaluerDeplacement(Cellule* source, Cellule* celluleCourante, int distanceCourante){
// faire circuler/explore ds les differentes directions si les cases sont dispo

    // si la cellule n'est pas disponible

    if(celluleCourante == source){

    }
    else if(celluleCourante->getUnit() != nullptr || celluleCourante->getBuilding() != nullptr){// TODO Building disponible!
        return;
    }


    // rajouter la case dans les cases dispos

    int distanceMax = source->getUnit()->getValueMP();
    std::cout << " distanceMax "<< distanceMax << std::endl;


    if( distanceCourante < distanceMax){

        int x = celluleCourante->getX();
        int y = celluleCourante->getY();

        //evaluer en haut
        std::cout << distanceCourante << " haut " << std::endl;

        int x_destination = x;
        int y_destination = y - 1;
        continuerEvaluation(source, x_destination, y_destination, celluleCourante, distanceCourante);


        //evaluer en bas
        std::cout << distanceCourante << " bas" << std::endl;

        x_destination = x;
        y_destination = y + 1;
        continuerEvaluation(source, x_destination, y_destination, celluleCourante, distanceCourante);


        //evaluer a gauche
        std::cout << distanceCourante << " gauche" << std::endl;

        x_destination = x - 1;
        y_destination = y;
        continuerEvaluation(source, x_destination, y_destination, celluleCourante, distanceCourante);


        //evaluer a droite
        std::cout << distanceCourante << " droite" << std::endl;

        x_destination = x + 1;
        y_destination = y;
        continuerEvaluation(source, x_destination, y_destination, celluleCourante, distanceCourante);

    } else {
        cout << ("condition d'arret pas assez de points") << endl;

    }
}
