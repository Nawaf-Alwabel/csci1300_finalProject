#include "Item.h"
#include <iostream>
using namespace std;

Item::Item()
{
    name = "";
    type = "";
    value = 0;
}

Item::Item(string itemName, string itemType, int itemValue)
{
    name = itemName;
    type = itemType;
    value = itemValue;
}

string Item::getName()
{
    return name;
}

string Item::getType()
{
    return type;
}

int Item::getValue()
{
    return value;
}

void Item::display()
{
    cout << name << " - " << type << " - " << value << " gold" << endl;
}
