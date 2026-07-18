#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    name = "";
    role = "";
    location = "Village Square";

    day = 1;
    energy = 10;
    money = 20;
    influence = 0;

    inventorySize = 0;
}

void Player::setName(string playerName)
{
    name = playerName;
}

void Player::setRole(string playerRole)
{
    role = playerRole;

    if (role == "Gambler")
    {
        money = 50;
    }
    else
    {
        money = 20;
    }
}

string Player::getName()
{
    return name;
}

string Player::getRole()
{
    return role;
}

string Player::getLocation()
{
    return location;
}

int Player::getDay()
{
    return day;
}

int Player::getEnergy()
{
    return energy;
}

int Player::getMoney()
{
    return money;
}

int Player::getInfluence()
{
    return influence;
}

void Player::moveTo(string newLocation)
{
    location = newLocation;
}

void Player::useEnergy(int amount)
{
    energy = energy - amount;

    if (energy < 0)
    {
        energy = 0;
    }
}

void Player::restoreEnergy()
{
    energy = 10;
}

void Player::addMoney(int amount)
{
    money = money + amount;
}

bool Player::spendMoney(int amount)
{
    if (money >= amount)
    {
        money = money - amount;
        return true;
    }

    return false;
}

void Player::addInfluence(int amount)
{
    influence = influence + amount;
}

void Player::nextDay()
{
    day = day + 1;
    energy = 10;
    location = "Village Square";
}

void Player::addItem(Item item)
{
    if (inventorySize < 10)
    {
        inventory[inventorySize] = item;
        inventorySize++;
    }
    else
    {
        cout << "Your inventory is full." << endl;
    }
}

void Player::displayInventory()
{
    cout << endl;
    cout << "Inventory" << endl;
    cout << "---------" << endl;

    if (inventorySize == 0)
    {
        cout << "You do not have any items." << endl;
        return;
    }

    for (int i = 0; i < inventorySize; i++)
    {
        cout << i + 1 << ". ";
        inventory[i].display();
    }
}

void Player::sellInventory()
{
    if (inventorySize == 0)
    {
        cout << "You do not have anything to sell." << endl;
        return;
    }

    int totalMoney = 0;

    for (int i = 0; i < inventorySize; i++)
    {
        totalMoney = totalMoney + inventory[i].getValue();
    }

    money = money + totalMoney;
    inventorySize = 0;

    cout << "You sold your items for " << totalMoney << " gold." << endl;
}
