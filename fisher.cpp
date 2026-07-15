#include "Fisher.h"
#include <cstdlib>

Fisher::Fisher() : Character()
{
}

Fisher::Fisher(string characterName, string characterLocation)
    : Character(characterName, characterLocation)
{
}

Item Fisher::fish()
{
    int chance = rand() % 2;

    if (chance == 0)
    {
        return Item("Small Fish", "Fish", 20);
    }
    else
    {
        return Item("Large Fish", "Fish", 40);
    }
}
