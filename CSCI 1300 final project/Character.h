#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;
// define character that has a name and location
class Character
{
protected:
    string name;
    string location;

public:
    Character();
    Character(string characterName, string characterLocation);

    string getName();
    string getLocation();

    void displayCharacter();
};

#endif
