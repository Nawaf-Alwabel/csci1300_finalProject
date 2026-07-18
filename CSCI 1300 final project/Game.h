#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Character.h"
#include "Fisher.h"
#include "Hunter.h"

#include <string>
using namespace std;

class Game
{
private:
    Player player;

    Character bestFriend;
    Character alchemist;
    Character casinoOwner;

    Fisher fisher;
    Hunter hunter;

    string dialogue[5];

    int casinoInfluence;

    bool gameOver;
    bool jailEnding;
    bool playerQuit;

public:
    Game();

    void loadDialogue();
    void chooseRole();
    void startGame();

    void displayDashboard();
    void displayMap();
    void displayMenu();

    void processChoice(int choice);
    void movePlayer();
    void talkToNPC();
    void useLocation();

    void villageAction();
    void riverAction();
    void forestAction();
    void alchemistAction();
    void casinoAction();

    void endDay();

    bool checkWin();
    bool checkLoss();

    void displayEnding();
};

#endif
