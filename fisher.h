#ifndef FISHER_H
#define FISHER_H

#include "Character.h"

class Fisher : public Character
{
private:
    int fishing_bonus;

public:
    Fisher();
    Fisher(std::string character_name, int starting_money,
           int starting_reputation, int bonus);

    int getFishingBonus() const;

    void fish();
    void showRole() const override;
};

#endif
