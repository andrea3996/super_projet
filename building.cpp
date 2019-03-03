#include "building.h"

Building::Building()
{
    this->x = x;
    this->y = y;
}

Player *Building::getOwner() const
{
    return owner;
}

void Building::setOwner(Player *value)
{
    owner = value;
}

std::string Building::getType() const
{
    return type;
}

City::City() : Building()
{
    type = "city";
}

Airport::Airport() : Building()
{
    type = "airport";
}

Base::Base() : Building()
{
    type = "base";
}
