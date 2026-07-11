#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
private:
    std::string name;
    int money;
    int reputation;

public:
    Character();
    Character(std::string character_name, int starting_money,
              int starting_reputation);

    std::string getName() const;
    int getMoney() const;
    int getReputation() const;

    void setName(std::string character_name);
    void addMoney(int amount);
    void addReputation(int amount);

    virtual void showRole() const;
};

#endif
