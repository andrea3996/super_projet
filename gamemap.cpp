#include <iostream>
#include<fstream>
#include <string>
#include <set>
#include <vector>
#include <sstream>

#include "gamemap.h"
#include "cellule.h"

using namespace std;
using std::ifstream;
using std::string;
using std::stoi;


GameMap::GameMap(int rows,int column){

    this->rows = rows;
    this->column= column;
    this->board = new std::vector< std :: vector<Cellule>>();
    this->creationBoard();

     //modifier attribut board

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

    ifstream fichier("map1.txt");
    // Extraire données du fichier
    if (fichier.is_open())
    {
        int mot = 0;
        string intType="";
        std::stringstream type;
        type<<"";
        std::vector<Cellule> * cells = new vector<Cellule>();
        while(fichier >> mot)
            if (mot == ',')  // en python: chr(mot) != ',' mais en c, char c'est un byte, donc ',' = code unicode (ascii) de ',' = ord(',') = 44
            {
                int typeInteger = stoi(type.str());
                string stringType = this->intTypeToStringType(typeInteger);
                std::vector<int> value = dico[stringType];
                Cellule * cell = new Cellule( stringType, value );
                cells->push_back(*cell);
                type<<"";
            }
            else if(mot == '\n')
            {
                int typeInteger = stoi(type.str());
                string stringType = this->intTypeToStringType(typeInteger);
                std::vector<int> value = dico[stringType];
                Cellule * cell = new Cellule( stringType, value );
                cells->push_back(*cell);
                this->board->push_back(*cells);
                cells = new vector<Cellule>();
                type<<"";

            }
            else
            {
                intType = mot;
                type << intType;
             }
        fichier.close();

    }


}



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

    cout<<"output is "<<vec[2][4]; // output is 40 */


string GameMap::intTypeToStringType(int value)
{
    string type;
        switch(value){
            case 101: case 104: case 102: case 109: case 108:
                type = "hpipe";
                    //hpipe Cellule(3,"hpipe.gif")
                break;
            case 2:
                type = "foret";
                break;
            case 4: case 7: case 9:
               type = "river";
                break;
            case 3:
                type = "wood";
                break;
            case 1:
                type = "plain";
                break;
            case 34:
                type = "greenearthcity";
                break;
            case 15: case 16: case 18: case 19: case 20: case 21: case 23:
                type = "hroad";
                break;
            case 30:
                type = "sea";
                break;
            case 33:
                type = "reef";
                break;
            case 36:
                type = "greenearthairport";
                break;
            case 92:
                type = "greenearthbase";
                break;
            case 26:
                type = "hbridge";
                break;
            case 125:
                type = "temple";
            break;
        }

    return type;
}





/*
  Cellule getCell(int x, int y)
 {

  return this->plateau[x][y];
 }


void Gamemap :: casesDispo(Unit unit, int mp,int a, int x, int y)
{
  if (mp>0)
  {
    if (this.getCell(x+1, y).getDisponible() && a =! 3)
    {
        mp = mp - this.getCell(x+1, y).valueMP(unit);
        a = 4;
        this.getCell(x+1, y).setDeplacement(true);
        this.casesDispo(unit,mp,a, x+1, y);
    }
    if (this.getCell(x-1,y).getDisponible() && a =! 4)
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
*/

/* int** a = new int*[rowCount];
     for(int i = 0; i < rowCount; ++i)
         a[i] = new int[colCount]; */
