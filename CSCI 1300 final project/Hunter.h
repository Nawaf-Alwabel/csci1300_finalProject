#ifndef HUNTER_H
#define HUNTER_H

#include "Character.h"
#include "Item.h"

class Hunter : public Character
{
public:
    Hunter();
    Hunter(string characterName, string characterLocation);

    Item hunt();
};

#endif
