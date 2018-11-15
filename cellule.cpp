#include "cellule.h"
#include <map>

#include <vector>
#include <ostream>
#include <iostream>
#include <QDebug>
using std::map;
using std::pair;
using std::string;
using std::vector;


    // quand tu attends que j'arrive regarder ton écran, n'hésite pas à laisser des commentaires
    // comme ça quand j'arrive, hop, je vois "tiens elle galère sur ça" -- ok je cherche
    // ok, en python tu veux faire quoi ? rien je cherche la bonne syntaxe
    // oui mais en PYTHON c'est quoi que tu cherches à faire ? creer une liste // ok ded oncn eon PYTmHbONres // ok donc en python ?
    // v = ... ls =[] puis ls.append()
    // bon...
    // tu installes python 3.7
    // pdt ce temps
    // ls = [], okay mais ici c'est pas "ls", c'est ?vector, nope
    // # donc ta variable ici c'est pas "ls" c'est "v"
    // et le type c'est vector<int>
    //std::vector<int> v;
    //int x = 5;
    //v.push_back(nombre); // push_back: ajouter à la fin ok
    //v.push_back(x); // vaeriable locale
    //v.push_back(9);

    //pq il n'est tjrs pas content la ?
    //je vais bientot aller dormirmmmmm, that's life :shrug
    // ok
    // je fais quoi avec ces 2 erreurs , je recommence un autre projet ?
    // non
    // emrci robert
    //je vais aller dormir

    // pour les erreurs en bas, on supprime le dossier "build"


Cellule::Cellule(std::string type)
{
    std::vector<int> v={1,0,2,4,5,6};
    std::map <string,vector<int>> my_map = {{"grass",v}};
    this->difficulte=1;
    //this->location="/Resources/hpipe.gif";

//cf TP 5
       std::map<string, vector<int>> liste;
       liste.insert({"plain", {1,1,1,2,1,0,0,0} });
       liste.insert({"mountain", {2,1,0,0,1,0,0,0}});
       liste.insert({"wood",{1,1,2,3,1,0,0,0}});
       liste.insert({"hpipe", {0,0,0,0,0,0,0,1}});
       liste.insert({"river", {2,1,0,0,1,0,0,0}});
       liste.insert({"greenearthcity", {1,1,1,1,1,0,0,0}});
       liste.insert({"hroad",{1,1,1,1,1,0,0,0}});
    //{"sea";{2,1,0,0,1,0,0,0}
       liste.insert({"reef",{0,0,0,0,1,2,2,0}});
       liste.insert({"greenearthairport",{1,1,1,1,1,0,0,0}});
       liste.insert({"greenearthbase",{1,1,1,1,1,0,0,1}});
       for (auto p : liste)
           std::cout << p.first << ":"<< std::endl;

       //std:: cout << liste << std:: endl;

       //qDebug()<<liste;


}

/*fonction casesDispo à traduire en C++ (fonction Javaisée)
 *
 * void casesDispo(Unit unit, int mp,int a)
{
  int x = this->x; int y = this->y;
  if (mp>0)
  {
    if (map.getCell(x+1, y).getDisponible() && a =! 3)
    {
        mp = mp - map.getCell(x+1, y).valueMP(unit);
        a = 4;
        map.getCell(x+1, y).setDeplacement(true);
        map.getCell(x+1,y).casesDispo(unit,mp,a);
    }
    if (map.getCell(x-1,y).getDisponible() && a =! 4)
    {
        mp = mp - map.getCell(x-1,y).valueMP(unit);
        a=3
    map.getCell(x-1, y).setDeplacement(true);
    map.getCell(x-1, y).casesDispo(unit, mp, a);
    }
    if (map.getCell(x, y+1).getDisponible() && a =! 1)
    {
    mp = mp - map.getCell(x, y+1).valueMP(unit);
    a = 2;
    map.getCell(x, y+1).setDeplacement(true);
    map.getCell(x, y+1).casesDispo(unit, mp, a);
    }
    if (map.getCell(x, y-1).getDisponible() && a=!2)
    {
    mp = mp - map.getCell(x, y-1).valueMP(unit);
    a = 1;
    map.getCell(x, y-1).setDeplacement(true);
    map.getCell(x, y+1).casesDispo(unit, mp,a);
    }
  }
}
 *
*/

int Cellule::getDifficulte()
{
    return this->difficulte;
}


std::string Cellule::getLocation(){
    return ""; // TODO

    //bis
    //?
    //correcte ?
}



