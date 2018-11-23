#include <iostream>
#include<fstream>
#include <string>
#include <set>
#include <vector>

#include "gamemap.h"
#include "cellule.h"

using namespace std;
using std::ifstream;

GameMap::GameMap()
{

}

vector<int> listeNombre(ifstream& fichier)
//envoit ref de l'objet donc utilise comme un objet
{
    // Extraire données du fichier
    if (fichier.is_open())
    {
        vector<int> liste;
        int mot;
        // Mettre slmt les nombres
        while(fichier >> mot)
            if (mot != ',')  // en python: chr(mot) != ',' mais en c, char c'est un byte, donc ',' = code unicode (ascii) de ',' = ord(',') = 44
            {
                liste.push_back(mot);
                // insert ne fonctionne pas pour vector, faire pushback !!

            }


        fichier.close();
        //printSet(liste);
        return liste;

    }


}


void test() {
    int rows = 5;
    int column = 3;
    std::vector<std::vector<int> > v (rows, std::vector <int> (column, 4));
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


vector<Cellule> creerListeCellule(vector<int> listeATraduire)
{
// renvoit liste de cellules
    vector<Cellule> listeCellule;
    for (int i=0;i<listeATraduire.size();i++){
        switch(listeATraduire.at(i)){
            case 101: case 104: case 102: case 109: case 108:
                listeCellule.push_back(Cellule("hpipe", dico));
                    //hpipe Cellule(3,"hpipe.gif")
                break;
            case 2:
                    //foret
                break;
            case 4: case 7: case 9:
               //river
                break;
            case 3:
                //wood
                break;
            case 1:
                //plain
                break;
            case 34:
                //greenearthcity
                break;
            case 15: case 16: case 18: case 19: case 20: case 21: case 23:
                //hroad
                break;
            case 30:
                //sea
                break;
            case 33:
                //reef
                break;
            case 36:
                //greenearthairport
                break;
            case 92:
                //greenearthbase
                break;
            case 26:
                //hbridge
                break;
            case 125:
                //temple
                break;

            default:
                cout<<"error with number"<< i<< endl;
            }
        }
}


/*

  GameMap :: GameMap(int ligne, int colonne)
  {
   std :: vector<std :: vector<Cellule>> grille;
   for (int i = 0; i< ligne; i++)
    {
        for (int j = 0; j< colonne; j++)
        {
            grille[i][j] = new Cellule(i, j);
        }
    }
    plateau = grille;

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
