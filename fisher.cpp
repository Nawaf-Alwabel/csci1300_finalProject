#include "Fisher.h"

#include <iostream>

Fisher::Fisher() : Character()
{
    fishing_bonus = 10;
}

Fisher::Fisher(std::string character_name, int starting_money,
               int starting_reputation, int bonus)
    : Character(character_name, starting_money, starting_reputation)
{
    fishing_bonus = bonus;
}

int Fisher::getFishingBonus() const
{
    return fishing_bonus;
}

void Fisher::fish()
{
    std::cout << getName() << " goes fishing with a +"
              << fishing_bonus << "% fishing bonus." << std::endl;

    std::cout << "Fishing rewards will be completed later." << std::endl;
}

void Fisher::showRole() const
{
    std::cout << "Role: Fisher" << std::endl;
}
