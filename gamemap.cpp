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


#include"QFile"

#include "QString"
#include "QChar"
#include "QMessageBox"
#include "QTextStream"

using namespace std;
using std::ifstream;
using std::string;
using std::stoi;


GameMap::GameMap(){ // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

    this->board = new std::vector< std :: vector<Cellule>>();
    this->creationBoard();
    // modifier attribut board
}

GameMap::~GameMap()
{

}

std::map<string, vector<int> > GameMap::creationDico(){
    std::map<string, vector<int> > dico;
    dico.insert({"plain", {1,1,1,2,1,0,0,0} });
    dico.insert({"mountain", {2,1,0,0,1,0,0,0}});
    dico.insert({"wood",{1,1,2,3,1,0,0,0}});
    dico.insert({"hpipe", {0,0,0,0,0,0,0,1}});
    dico.insert({"river", {2,1,0,0,1,0,0,0}});
    dico.insert({"hroad",{1,1,1,1,1,0,0,0}});
    dico.insert({"sea",{2,1,0,0,1,0,0,0}}); // Verifier valeur
    dico.insert({"hsoal",{0,0,0,0,0,0,0,0}});
    dico.insert({"reef",{0,0,0,0,1,2,2,0}});
    dico.insert({"hbridge",{0,0,0,0,1,2,2,0}});


    dico.insert({"city", {1,1,1,1,1,0,0,0}}); //
    dico.insert({"airport",{1,1,1,1,1,0,0,0}});
    dico.insert({"base",{1,1,1,1,1,0,0,1}});

    dico.insert({"greenearthcitycity", {1,1,1,1,1,0,0,0}}); //
    dico.insert({"greenearthbase", {0,0,0,0,0,0,0,0}}); //
    dico.insert({"greenearthairport", {0,0,0,0,0,0,0,0}}); //

    dico.insert({"orangestarcity", {0,0,0,0,0,0,0,0}}); //
    dico.insert({"orangestarbase", {0,0,0,0,0,0,0,0}}); //
    dico.insert({"orangestarairport", {0,0,0,0,0,0,0,0}}); //

    return dico;
}



void GameMap::creationBoard()
//envoit ref de l'objet donc utilise comme un objet
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
    std::vector<Cellule> * cells = new vector<Cellule>();

    while(! flux.atEnd())
    {
            // TODO: Trouver un moyen de connaître la position des cellules et les donner dans le constructeur de cell

            flux >> mot;
           // std :: cout << mot.toLatin1()<< endl;
            if (mot == ',')  // en python: chr(mot) != ',' mais en c, char c'est un byte, donc ',' = code unicode (ascii) de ',' = ord(',') = 44
            {

                int typeInteger = stoi(type); // traduction en entier ex : stoi("10") = 10
                string stringType = this->intTypeToStringType(typeInteger); // traduction d'un entier à son équivalent type (forêt, montagne, etc)
                std::vector<int> value = dico[stringType]; // liste des difficultés associée au type (stringType)
                x += 1 ;
                Cellule cell( stringType, value, x, y); // construction de la cellule
                createBuilding(&cell, stringType);
                cells->push_back(cell); // la cellule est rentrée dans le vecteur
                type = "";



            }
            else if(mot == '\n')
            {
                int typeInteger = stoi(type);
                string stringType = this->intTypeToStringType(typeInteger);
                std::vector<int> value = dico[stringType];

                x =0;
                y += 1 ;
                //std::cout<< y << std::endl;

                Cellule cell( stringType, value,x,y);
                createBuilding(&cell, stringType);
                cells->push_back(cell);
                // vector -> tableau 17 21
                // Pb de switch
                this->board->push_back(*cells);
                cells = new vector<Cellule>();
                type = "";
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

    }/**
    for (int i = 0; i < this->board->size(); i++) {
        for (int j = 0; j < this->board->at(0).size(); j++) {
            std::cout << (*this->board)[i][j].getType()[0] << (*this->board)[i][j].getType()[1] <<  " ";
        }
        std::cout << std::endl; // nouvelle ligne
    }**/

}


void GameMap::createBuilding(Cellule* cell,std::string type){
    if(type == "airport") {
        std::cout<<"airport : " <<type <<std::endl;
        cell->setBuilding(new Airport());
    } else if (type=="base") {
        std::cout<< "base : "<<type <<std::endl;
        cell->setBuilding(new Base());
    } else if (type=="city") {
        std::cout<< "city : "<<type <<std::endl;
        cell->setBuilding(new City());
    } else if (type=="orangestarcity") {
        City* city = new City();
        //city->setOwner(//TODO chercher dans le game le joueur orange);
    }
    // if type =
    // setPlayer ...
}



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
    return &(*this->board)[x][y]; // le premier = ligne
}


std::vector< std :: vector<Cellule>> * GameMap::getBoard(){
    return this->board;
 }


void GameMap :: casesDispo(Unit unit, int mp,int a, int x, int y)
{
  if (mp>0)
  {
    this->condCaseDispo(unit, mp,x+1, y, a, 3, 4);
    this->condCaseDispo(unit, mp,x-1, y, a ,4, 3);
    this->condCaseDispo(unit, mp,x, y+1 ,a ,1, 2);
    this->condCaseDispo(unit, mp,x, y-1 ,a ,2, 1);

  }
}


void GameMap :: condCaseDispo(Unit unit,int mp, int x, int y, int a, int b, int c){
    if ((this->getCell(x,y)->getDisponible()) && a != b){
        mp = mp - this->getCell(x,y)->getUnit()->getValueMP();
        a = c;
        this->getCell(x,y)->setDeplacement(true);
        this->casesDispo(unit,mp,a, x, y);
    }

}
