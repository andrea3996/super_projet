#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include "unit.h"

class Building
{
public:

    Building(std::string type);


private:
    std::string type;
    std::vector<Unit> units;
};

#endif // BUILDING_H
