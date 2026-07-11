#include "Hunter.h"

#include <iostream>

Hunter::Hunter() : Character()
{
    hunting_bonus = 10;
}

Hunter::Hunter(std::string character_name, int starting_money,
               int starting_reputation, int bonus)
    : Character(character_name, starting_money, starting_reputation)
{
    hunting_bonus = bonus;
}

int Hunter::getHuntingBonus() const
{
    return hunting_bonus;
}

void Hunter::hunt()
{
    std::cout << getName() << " goes hunting with a +"
              << hunting_bonus << "% hunting bonus." << std::endl;

    std::cout << "Hunting rewards will be completed later." << std::endl;
}

void Hunter::showRole() const
{
    std::cout << "Role: Hunter" << std::endl;
}
