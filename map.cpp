#include <iostream>
#include<fstream>
#include <string>
#include <set>
#include <vector>

#include "map.h"
#include "cellule.h"

using namespace std;
using std::ifstream;

Map::Map()
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
                listeCellule.push_back(Cellule("hpipe"));
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

/* int** a = new int*[rowCount];
     for(int i = 0; i < rowCount; ++i)
         a[i] = new int[colCount]; */
