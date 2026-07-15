#include "Hunter.h"
#include <cstdlib>

Hunter::Hunter() : Character()
{
}

Hunter::Hunter(string characterName, string characterLocation)
    : Character(characterName, characterLocation)
{
}

Item Hunter::hunt()
{
    int chance = rand() % 2;

    if (chance == 0)
    {
        return Item("Rabbit Hide", "Hunting", 25);
    }
    else
    {
        return Item("Deer Hide", "Hunting", 50);
    }
}
