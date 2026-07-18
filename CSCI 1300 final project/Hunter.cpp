#include "Hunter.h"
#include <cstdlib>

Hunter::Hunter()
{
    name = "";
    location = "";
}

Hunter::Hunter(string characterName, string characterLocation)
{
    name = characterName;
    location = characterLocation;
}

Item Hunter::hunt()
{
    int randomNumber = rand() % 2;

    if (randomNumber == 0)
    {
        Item huntingItem("Rabbit Hide", "Hunting", 25);
        return huntingItem;
    }

    Item huntingItem("Deer Hide", "Hunting", 50);
    return huntingItem;
}
