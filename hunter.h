#ifndef HUNTER_H
#define HUNTER_H

#include "Character.h"

class Hunter : public Character
{
private:
    int hunting_bonus;

public:
    Hunter();
    Hunter(std::string character_name, int starting_money,
           int starting_reputation, int bonus);

    int getHuntingBonus() const;

    void hunt();
    void showRole() const override;
};

#endif
