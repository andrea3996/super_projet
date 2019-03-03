#include "player.h"

Player::Player(std::string teamColor)
{
    this->teamColor = teamColor;
    this-> money = 1000;
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
