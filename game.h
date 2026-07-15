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

    Character candidate;
    Character alchemist;
    Character gambler;

    Fisher fisher;
    Hunter hunter;

    string dialogue[5];

    bool gameOver;
    bool jailEnding;

public:
    Game();

    void loadDialogue();
    void startGame();

    void displayDashboard();
    void displayMap();
    void displayMenu();

    void processChoice(int choice);
    void movePlayer();
    void locationAction();

    void villageAction();
    void fishingAction();
    void huntingAction();
    void alchemistAction();
    void gamblingAction();

    void endDay();

    bool checkWin();
    bool checkLoss();

    void displayEnding();
};

#endif
