#ifndef GAME_H
#define GAME_H

#include "Fisher.h"
#include "Hunter.h"

class Game
{
private:
    bool running;
    int day;

    Fisher fisher;
    Hunter hunter;

    void displayMainMenu() const;
    void displayStatus() const;
    void performDailyAction();
    void advanceDay();

public:
    Game();

    void run();
};

#endif
