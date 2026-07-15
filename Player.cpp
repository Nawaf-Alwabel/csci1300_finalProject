#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    name = "";
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

string Player::getName()
{
    return name;
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
        inventorySize = inventorySize + 1;
    }
    else
    {
        cout << "Inventory is full." << endl;
    }
}

void Player::displayInventory()
{
    cout << endl;
    cout << "--- Inventory ---" << endl;

    if (inventorySize == 0)
    {
        cout << "Inventory is empty." << endl;
    }
    else
    {
        for (int i = 0; i < inventorySize; i++)
        {
            cout << i + 1 << ". ";
            inventory[i].display();
        }
    }
}

void Player::sellInventory()
{
    if (inventorySize == 0)
    {
        cout << "You have nothing to sell." << endl;
        return;
    }

    int total = 0;

    for (int i = 0; i < inventorySize; i++)
    {
        total = total + inventory[i].getValue();
    }

    money = money + total;
    inventorySize = 0;

    cout << "You sold everything for " << total << " gold." << endl;
}
