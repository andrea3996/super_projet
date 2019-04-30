#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include<iostream>
class Player
{
    public:
        Player(std::string teamColor);

        std::string getTeamColor() const;

        int getMoney() const;
        void setMoney(int value);
        void buy(int price);
        bool hasEnoughMoney(int price);

private:
        std::string teamColor;
        int money;


};

#endif // PLAYER_H
