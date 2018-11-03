#include <iostream>
#include<fstream>
#include <string>
#include <set>
#include <vector>

#include "map.h"
#include "cellule.h"

using namespace std;
using std::ofstream;

Map::Map()
{

}

vector<int> listeNombre(ofstream fichier)
{
    // Extraire données du fichier
    if (fichier.is_open())
    {
        vector<int> liste;
        int mot;
        // Mettre slmt les nombres
        while(fichier >> mot)
            if (mot != ',')
            {
                liste.push_back(mot);
                // insert ne fonctionne pas pour vector, faire pushback !!

            }


        fichier.close();
        //printSet(liste);
        return liste;

    }


}


std::vector<std::vector<int> > v (rows, std::vector <int> (column, 4));


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







vector<Cellule> listeCellule(vector<liste> liste)
{
// renvoit liste de cellules
    for (i
            if ls (i) == '2'
             foret
            insert li un carré bleu

            if ls(i) == '101' or '104' or '102' or '109' or '108'
                hpipe

            if ls(i)== '4' or '7' or '9'
               river
            if ls(i)=='3'
                wood
            if ls(i)== '1'
                plain
            if ls(i)=='34'
                greenearthcity
            if ls(i)== '15' or '16' or '18' or '19' or '20' or '21' or '23'
                hroad
            if ls(i)== '30'
                sea
            if ls(i)== '33'
                reef
            if ls(i)== '36'
                greenearthairport
            if ls(i)== '92'
                greenearthbase
            if ls(i)== '26'
                hbridge
            if ls(i)== '125'
                temple
}

/* int** a = new int*[rowCount];
     for(int i = 0; i < rowCount; ++i)
         a[i] = new int[colCount]; */
