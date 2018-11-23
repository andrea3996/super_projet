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





Cellule::Cellule(std::string type)
{
    //std::vector<int> v={1,0,2,4,5,6};
    //std::map <string,vector<int>> my_map = {{"grass",v}};
    //this->difficulte=1;

    //this->location="/Resources/hpipe.gif";
    std:: cout << "Hello" << std:: endl;
    //listediff = dico[ "type"]

//cf TP 5
     //get cretionDico (hpipe)


       //for (std::map<string, vector<int>>::iterator it = liste.begin(); it != liste.end(); it++){
         //  std::cout << it ->first << ":"<< std::endl;
       }

       //std:: cout << liste << std:: endl;

       //qDebug()<<liste;




std::map<string, vector<int>> creationDico(){
    std::map<string, vector<int>> dico;
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

std::map<string, vector<int>>






/*Cellule :: Cellule(int x, int y) : x(x), y(y)
 {
 }


 int Cellule :: valueMP(Unit *unit) // s'applique à une cellule. l'unite qui est dessus

fonction casesDispo à traduire en C++ (fonction Javaisée)
 *
 * void casesDispo(Unit unit, int mp,int a)
{
  int x = this->x; int y = this->y;
  if (mp>0)
     Stashed changes
  {
       int a = this->m[this->type][unit->getMoveType()];
       return a;
  }



  void Cellule :: setDeplacement(bool a)
  {
       this->deplacement = a;
  }


  bool Cellule :: getDisponible()
  {
       return this->disponible;
  }



int Cellule::getDifficulte()
{
    return this->difficulte;
}

int Cellule::test()
{
    std::map<string,vector<int>> liste;
    liste.insert({"plain",{1,2,3,4,5}});
    std::cout << it ->first << ":"<< std::endl;
    return 0 ;
}
std::string Cellule::getLocation(){
    return ""; // TODO

}

    // v = ... ls =[] puis ls.append()
    // ls = [], okay mais ici c'est pas "ls", c'est ?vector, nope
    // # donc ta variable ici c'est pas "ls" c'est "v"
    // et le type c'est vector<int>
    //std::vector<int> v;
    //int x = 5;
    //v.push_back(nombre); // push_back: ajouter à la fin ok
    //v.push_back(x); // vaeriable locale
    //v.push_back(9);


    // pour les erreurs en bas, on supprime le dossier "build"

*/
