#ifndef CASEDISPO_H
#define CASEDISPO_H
#include <iostream>
#include <ostream>


class CaseDispo {
    public :
        CaseDispo();
        std::pair<int,int> & getCelluleDispo();
        std::pair<int,int> & getCellulePrecedente();
        int getDistance();
        void setDistance(int distance);
    private :
        std::pair<int,int> celluleDispo;
        std::pair<int,int> cellulePrecedente;
        int distance;
};


#endif // CASEDISPO_H
