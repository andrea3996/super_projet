#ifndef MAP_H
#define MAP_H
#include <vector>
#include <fstream>

class Map
{
public:
    Map();
private:
    std::vector<int> listeMap(std::ifstream & fichier);  // attention, fichier n'est pas copiable
    int rows;
    int column;
    std::vector<std::vector<int>> v;

};

#endif // MAP_H



