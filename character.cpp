#include "Character.h"

#include <iostream>

Character::Character()
{
    name = "Player";
    money = 0;
    reputation = 0;
}

Character::Character(std::string character_name, int starting_money,
                     int starting_reputation)
{
    name = character_name;
    money = starting_money;
    reputation = starting_reputation;
}

std::string Character::getName() const
{
    return name;
}

int Character::getMoney() const
{
    return money;
}

int Character::getReputation() const
{
    return reputation;
}

void Character::setName(std::string character_name)
{
    name = character_name;
}

void Character::addMoney(int amount)
{
    money += amount;

    if (money < 0)
    {
        money = 0;
    }
}

void Character::addReputation(int amount)
{
    reputation += amount;

    if (reputation < 0)
    {
        reputation = 0;
    }
}

void Character::showRole() const
{
    std::cout << "Role: General character" << std::endl;
}
