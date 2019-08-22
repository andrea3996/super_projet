#include "casedispo.h"

CaseDispo::CaseDispo()
{

}

std::pair<int, int> & CaseDispo::getCelluleDispo()
{
    return celluleDispo;
}

std::pair<int, int> & CaseDispo::getCellulePrecedente()
{
    return cellulePrecedente;
}

int CaseDispo::getDistance()
{
    return distance;
}

void CaseDispo::setDistance(int distance)
{
    this->distance = distance;
}
