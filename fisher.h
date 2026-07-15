#ifndef FISHER_H
#define FISHER_H

#include "Character.h"
#include "Item.h"

class Fisher : public Character
{
public:
    Fisher();
    Fisher(string characterName, string characterLocation);

    Item fish();
};

#endif
