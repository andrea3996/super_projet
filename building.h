#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include "unit.h"

class Building
{
public:

    Building();


    Player* getOwner() const;
    void setOwner(Player *value);

    std::string getType() const;

protected:
    int x, y;
    std::string type;
    //std::vector<Unit> units;
    Player* owner = nullptr;
};



class Base: public Building{
public:
    Base();
};


class Airport: public Building{
public:
    Airport();
};

class City: public Building{
public:
    City();
};
#endif // BUILDING_H



#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include "unit.h"

class Building
{
public:

    Building();


    Player* getOwner() const;
    void setOwner(Player *value);

    std::string getType() const;

protected:
    int x, y;
    std::string type;
    //std::vector<Unit> units;
    Player* owner = nullptr;
};



class Base: public Building{
public:
    Base();
};


class Airport: public Building{
public:
    Airport();
};

class City: public Building{
public:
    City();
};
#endif // BUILDING_H

