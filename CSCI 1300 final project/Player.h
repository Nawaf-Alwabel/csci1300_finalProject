#ifndef PLAYER_H
#define PLAYER_H

#include "Item.h"
#include <string>
using namespace std;

class Player
{
private:
    string name;
    string role;
    string location;

    int day;
    int energy;
    int money;
    int influence;

    Item inventory[10];
    int inventorySize;

public:
    Player();

    void setName(string playerName);
    void setRole(string playerRole);

    string getName();
    string getRole();
    string getLocation();

    int getDay();
    int getEnergy();
    int getMoney();
    int getInfluence();

    void moveTo(string newLocation);
    void useEnergy(int amount);
    void restoreEnergy();

    void addMoney(int amount);
    bool spendMoney(int amount);

    void addInfluence(int amount);
    void nextDay();

    void addItem(Item item);
    void displayInventory();
    void sellInventory();
};

#endif
