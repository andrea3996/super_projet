#include "player.h"

Player::Player(std::string teamColor)
{
    this->teamColor = teamColor;
    this-> money = 1000000;
}

std::string Player::getTeamColor() const
{
    return teamColor;
}

int Player::getMoney() const
{
    return money;
}

void Player::setMoney(int value)
{
    money = value;
}

bool Player::hasEnoughMoney(int price){
    return money >= price;
}

void Player::buy(int price){
    money = money - price;
    if(money < 0){
        exit(10); // TODO: !!!!! it should never happen
    }
}

