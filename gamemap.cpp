#include <iostream>
#include<fstream>
#include <string>
#include <set>
#include <vector>
#include <sstream>

//#include <windows.h>
#include "gamemap.h"
#include "cellule.h"

#include"QFile"

#include "QString"
#include "QChar"
#include "QMessageBox"
#include "QTextStream"

using namespace std;
using std::ifstream;
using std::string;
using std::stoi;


GameMap::GameMap(int rows,int column){

    this->rows = rows;
    this->column= column;
    this->board = new std::vector< std :: vector<Cellule>>();
    std::cout << "xd" << std::endl;
    this->creationBoard();
    std::cout << "board $$$$$ " << (*this->board)[0][0].getType() << std::endl;
    // modifier attribut board
}

std::map<string, vector<int> > GameMap::creationDico(){
    std::map<string, vector<int> > dico;
    dico.insert({"plain", {1,1,1,2,1,0,0,0} });
    dico.insert({"mountain", {2,1,0,0,1,0,0,0}});
    dico.insert({"wood",{1,1,2,3,1,0,0,0}});
    dico.insert({"hpipe", {0,0,0,0,0,0,0,1}});
    dico.insert({"river", {2,1,0,0,1,0,0,0}});
    dico.insert({"greenearthcity", {1,1,1,1,1,0,0,0}});
    dico.insert({"hroad",{1,1,1,1,1,0,0,0}});
    //{"sea";{2,1,0,0,1,0,0,0}
    dico.insert({"reef",{0,0,0,0,1,2,2,0}});
    dico.insert({"greenearthairport",{1,1,1,1,1,0,0,0}});
    dico.insert({"greenearthbase",{1,1,1,1,1,0,0,1}});
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
    std::vector<Cellule> * cells = new vector<Cellule>();

    while(! flux.atEnd())
    {

            flux >> mot;
           // std :: cout << mot.toLatin1()<< endl;
            if (mot == ',')  // en python: chr(mot) != ',' mais en c, char c'est un byte, donc ',' = code unicode (ascii) de ',' = ord(',') = 44
            {

              //  std :: cout << stoi(type) << endl;
                int typeInteger = stoi(type); // traduction en entier ex : stoi("10") = 10
                string stringType = this->intTypeToStringType(typeInteger); // traduction d'un entier à son équivalent type (forêt, montagne, etc)
                std::vector<int> value = dico[stringType]; // liste des difficultés associée au type (stringType)
                Cellule cell( stringType, value ); // construction de la cellule
                //std::cout << stringType <<std::endl;
                cells->push_back(cell); // la cellule est rentrée dans le vecteur
                type = "";
                //std::cout << cell->getType()[0]<< cell->getType()[1]<<"-";



            }
            else if(mot == '\n')
            {
              //  std :: cout << stoi(type) << endl;
                //std::cout << endl;
                int typeInteger = stoi(type);
                string stringType = this->intTypeToStringType(typeInteger);
                std::vector<int> value = dico[stringType];
                Cellule cell( stringType, value );
                //std::cout << stringType <<std::endl;
                cells->push_back(cell);
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
        fichier.close(); //TODO


    }/**
    for (int i = 0; i < this->board->size(); i++) {
        for (int j = 0; j < this->board->at(0).size(); j++) {
            std::cout << (*this->board)[i][j].getType()[0] << (*this->board)[i][j].getType()[1] <<  " ";
        }
        std::cout << std::endl; // nouvelle ligne
    }**/
    std::cout << "board "<< this->board << std::endl;
}





string GameMap::intTypeToStringType(int value)
{
    string type = "";
        switch(value){
            case 101: case 104: case 102: case 106: case 107: case 108: case 109: case 110:
                type = "hpipe";
                    //hpipe Cellule(3,"hpipe.gif")
                break;
            case 2:
                type = "foret";
                break;
            case 4: case 5: case 7: case 8: case 9: case 10:
               type = "river";
               break;
            case 5: case 3:
                type = "wood";
                break;
            case 1: case 24: // TODO: vérifier
                type = "plain";
                break;
            case 34:
                type = "greenearthcity";
                break;
            case 15: case 16: case 18: case 19: case 20: case 21: case 22: case 23: case 24: case 25:
                type = "hroad";
                break;

            case 29: case 30:
                type = "sea";
                break;
            case 33: case 29:
                type = "reef";
                break;
            case 36:
                type = "greenearthairport";
                break;
            case 25: case 92:case 110: //TODO: vérifier
                type = "greenearthbase";
                break;
            case 26:
                type = "hbridge";
                break;
            case 125:
                type = "temple";
            break;
            default:
                type= "hpipe";
        }
        if (type=="") {
            std::cout << "cellule mal définie pour id " << value << std::endl;
        }
    return type;
}






Cellule GameMap::getCell(int x, int y)
{
    std::cout << "GET CELL" << std::endl;
    //std::cout << this->board->at(x).at(y) << std::endl;
    std::cout << "get cell passed" << std::endl;
    std::cout << "board "<< this->board << std::endl;
    std::cout << x << y<< endl;
    return (*this->board)[x][y];
}




std::vector< std :: vector<Cellule>> * GameMap::getBoard()
 {
    return this->board;
 }
/*
void Gamemap :: casesDispo(Unit unit, int mp,int a, int x, int y)
{
  if (mp>0)
  {
    if (this->board[x+1][y].getDisponible() && a =! 3)
    {
        mp = mp - this->board[x+1][y].valueMP(unit);
        a = 4;
        this->board[x+1][y].setDeplacement(true);
        this.casesDispo(unit,mp,a, x+1, y);
    }
    if (this->board[x-1][y].getDisponible() && a =! 4)
    {
        mp = mp - this.getCell(x-1,y).valueMP(unit);
        a=3
      this.getCell(x-1, y).setDeplacement(true);
      this.casesDispo(unit, mp, a, x-1, y);
    }
    if (map.getCell(x, y+1).getDisponible() && a =! 1)
    {
    mp = mp - map.getCell(x, y+1).valueMP(unit);
    a = 2;
    this.getCell(x, y+1).setDeplacement(true);
    this.casesDispo(unit, mp, a, x, y+1);
    }
    if (this.getCell(x, y-1).getDisponible() && a=!2)
    {
    mp = mp - map.getCell(x, y-1).valueMP(unit);
    a = 1;
    this.getCell(x, y-1).setDeplacement(true);
    this.casesDispo(unit, mp,a, x, y-1);
    }
  }
}


 int** a = new int*[rowCount];
     for(int i = 0; i < rowCount; ++i)
         a[i] = new int[colCount]; */


 //vector<vector<int>>
 /*vector<vector<int>> vec; // declare 2D vector

     for (int i=0; i<=17; i++) {
         vector<int> row;  // create a row vector which adds a row to vec
         for (int j=0; j<=21; j++) {
             row.push_back(j); // push elements 0,10,20,30,40 to row
         }
         vec.push_back(row); // add this row to vec
         // Repeat this procedure 4 times to make a 4*5 2D vector
     }

     cout<<"output is "<<vec[2][4]; // output is 40
*/
