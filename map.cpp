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
                // insert ne fonctionne pas pour vector faire pushback !!

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
            if ls (i) == '102'
             foret
            insert li un carré bleu

            if
}

/* int** a = new int*[rowCount];
     for(int i = 0; i < rowCount; ++i)
         a[i] = new int[colCount]; */
