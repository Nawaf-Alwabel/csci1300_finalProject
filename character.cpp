#include "Character.h"
#include <iostream>
using namespace std;

Character::Character()
{
    name = "";
    location = "";
}

Character::Character(string characterName, string characterLocation)
{
    name = characterName;
    location = characterLocation;
}

string Character::getName()
{
    return name;
}

string Character::getLocation()
{
    return location;
}

void Character::talk()
{
    cout << "";
}
