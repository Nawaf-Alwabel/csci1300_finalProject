#include "Fisher.h"
#include <cstdlib>

Fisher::Fisher()
{
    name = "";
    location = "";
}

Fisher::Fisher(string characterName, string characterLocation)
{
    name = characterName;
    location = characterLocation;
}

Item Fisher::fish()
{
    int randomNumber = rand() % 2;

    if (randomNumber == 0)
    {
        Item fishItem("Small Fish", "Fish", 20);
        return fishItem;
    }

    Item fishItem("Large Fish", "Fish", 40);
    return fishItem;
}
