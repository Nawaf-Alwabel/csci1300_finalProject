#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
private:
    string name;
    string type;
    int value;

public:
    Item();
    Item(string itemName, string itemType, int itemValue);

    string getName();
    string getType();
    int getValue();

    void display();
};

#endif
