// READ! to save you a bunch of time, all my notes are marked by A1-A14.
// if you want to quickly check it, just use ctrl F or command F
// not alot of notes in different files since they are short and should be
// read very easily





#include "Game.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game()
{
    bestFriend = Character("Best Friend", "Village Square");
    alchemist = Character("Alchemist", "Alchemist Hut");
    casinoOwner = Character("Casino Owner", "Casino");

    fisher = Fisher("Fisher", "River");
    hunter = Hunter("Hunter", "Forest");

    casinoInfluence = 0;

    gameOver = false;
    jailEnding = false;
    playerQuit = false;
}
// A1 note; will load the txt file for the dialogue, the file must be in the folder
// IMPORTANT, if you add a dialouge line in txt, you MUST adjust the array here:

void Game::loadDialogue()
{
    ifstream dialogueFile("dialogue.txt");

    if (dialogueFile.fail())
    {
        cout << "The dialogue file could not be opened." << endl;

        for (int i = 0; i < 5; i++) //<-- adjust incase of new dialuoge 
        {
            dialogue[i] = "";
        }

        return;
    }

    for (int i = 0; i < 5; i++)
    {
        getline(dialogueFile, dialogue[i]);
    }

    dialogueFile.close();
}
//A2 note. picking a class, picking any number other than 1, 2 or 3 will result on a default class of fisher
void Game::chooseRole()
{
    cout << endl;
    cout << "Choose a role:" << endl;
    cout << "1. Fisher" << endl;
    cout << "2. Hunter" << endl;
    cout << "3. Gambler" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        player.setRole("Fisher");
    }
    else if (choice == 2)
    {
        player.setRole("Hunter");
    }
    else if (choice == 3)
    {
        player.setRole("Gambler");
    }
    else
    {
        cout << "That was not a valid choice, so Fisher was selected." << endl;
        player.setRole("Fisher");
    }
}
//A3 note obv starts the game, while(!gameover) keep the game in loop
void Game::startGame()
{
    srand(time(0));
    loadDialogue();

    string playerName;

    cout << "Enter your name: ";
    getline(cin, playerName);

    player.setName(playerName);
    chooseRole();

    cout << endl;
    cout << "[intro: (did not actually write any : D, just imagine a crazy cool introduction)]" << endl;

    while (!gameOver)
    {
        displayDashboard();
        displayMenu();

        int choice;
        cin >> choice;

        processChoice(choice);

        if (checkWin() || checkLoss())
        {
            gameOver = true;
        }
    }

    displayEnding();
}

void Game::displayDashboard()
{
    cout << endl;
    cout << "==================================" << endl;
    cout << "       A cool town    " << endl;
    cout << "==================================" << endl;
    cout << "Name: " << player.getName() << endl;
    cout << "Role: " << player.getRole() << endl;
    cout << "Day: " << player.getDay() << " / 3" << endl;
    cout << "Energy: " << player.getEnergy() << " / 10" << endl;
    cout << "Money: " << player.getMoney() << " / 200" << endl;
    cout << "Influence: " << player.getInfluence() << " / 50" << endl;
    cout << "Casino Influence: " << casinoInfluence << endl;
    cout << "Location: " << player.getLocation() << endl;

    displayMap();
}
//A4 note this is a dialouge based on location, it pulls an array from the txt file (that's why it's important : D)
void Game::talkToNPC()
{
    if (player.getLocation() == "Village Square")
    {
        bestFriend.displayCharacter();
        cout << dialogue[0] << endl;
    }
    else if (player.getLocation() == "River")
    {
        fisher.displayCharacter();
        cout << dialogue[1] << endl;
    }
    else if (player.getLocation() == "Forest")
    {
        hunter.displayCharacter();
        cout << dialogue[2] << endl;
    }
    else if (player.getLocation() == "Alchemist Hut")
    {
        alchemist.displayCharacter();
        cout << dialogue[3] << endl;
    }
    else if (player.getLocation() == "Casino")
    {
        casinoOwner.displayCharacter();
        cout << dialogue[4] << endl;
    }
}
//A5 note a little way to make it easier for the player to know where they are, it gets the location and puts a * next to it if you're in the location
void Game::displayMap()
{
    cout << endl;
    cout << "Village Map" << endl;
    cout << "-----------" << endl;

    if (player.getLocation() == "Village Square")
    {
        cout << "1. Village Square *" << endl;
    }
    else
    {
        cout << "1. Village Square" << endl;
    }

    if (player.getLocation() == "River")
    {
        cout << "2. River *" << endl;
    }
    else
    {
        cout << "2. River" << endl;
    }

    if (player.getLocation() == "Forest")
    {
        cout << "3. Forest *" << endl;
    }
    else
    {
        cout << "3. Forest" << endl;
    }

    if (player.getLocation() == "Alchemist Hut")
    {
        cout << "4. Alchemist Hut *" << endl;
    }
    else
    {
        cout << "4. Alchemist Hut" << endl;
    }

    if (player.getLocation() == "Casino")
    {
        cout << "5. Casino *" << endl;
    }
    else
    {
        cout << "5. Casino" << endl;
    }

    cout << "* means you are here" << endl;
}
//A6 note menu
void Game::displayMenu()
{
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Move somewhere" << endl;
    cout << "2. Do the location action" << endl;
    cout << "3. Talk to NPC" << endl;
    cout << "4. View inventory" << endl;
    cout << "5. Sell inventory" << endl;
    cout << "6. End the day" << endl;
    cout << "7. Quit" << endl;
    cout << "Choice: ";
}
//A7 note to pick your choice, if the number is not listed it will loop back to the menu
void Game::processChoice(int choice)
{
    if (choice == 1)
    {
        movePlayer();
    }
    else if (choice == 2)
    {
        useLocation();
    }
    else if (choice == 3)
    {
        talkToNPC();
    }
    else if (choice == 4)
    {
        player.displayInventory();
    }
    else if (choice == 5)
    {
        player.sellInventory();
    }
    else if (choice == 6)
    {
        endDay();
    }
    else if (choice == 7)
    {
        playerQuit = true;
        gameOver = true;
    }
    else
    {
        cout << "That is not a valid option." << endl;
    }
}

void Game::movePlayer()
{
    cout << endl;
    cout << "Where do you want to go?" << endl;
    cout << "1. Village Square" << endl;
    cout << "2. River" << endl;
    cout << "3. Forest" << endl;
    cout << "4. Alchemist Hut" << endl;
    cout << "5. Casino" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        player.moveTo("Village Square");
    }
    else if (choice == 2)
    {
        player.moveTo("River");
    }
    else if (choice == 3)
    {
        player.moveTo("Forest");
    }
    else if (choice == 4)
    {
        player.moveTo("Alchemist Hut");
    }
    else if (choice == 5)
    {
        player.moveTo("Casino");
    }
    else
    {
        cout << "That is not a valid location." << endl;
    }
}
//A8 note the function to set up your action in that specific location.
// check the code below to see the fucntion for each action
// important! a note was added incase you wanted the classes to have special benifit that gives them a bonus based on their class and action
// ie, fisher gets more money when fishing
void Game::useLocation()
{
    if (player.getLocation() == "Village Square")
    {
        villageAction();
    }
    else if (player.getLocation() == "River")
    {
        riverAction();
    }
    else if (player.getLocation() == "Forest")
    {
        forestAction();
    }
    else if (player.getLocation() == "Alchemist Hut")
    {
        alchemistAction();
    }
    else if (player.getLocation() == "Casino")
    {
        casinoAction();
    }
}

void Game::villageAction()
{
    if (player.getEnergy() < 2)
    {
        cout << "You do not have enough energy." << endl;
        return;
    }

    bestFriend.displayCharacter();
    cout << dialogue[0] << endl;

    player.useEnergy(2);
    player.addInfluence(10);

    cout << "You gained 10 influence." << endl;
}

void Game::riverAction()
{
    if (player.getEnergy() < 2)
    {
        cout << "You do not have enough energy." << endl;
        return;
    }

    fisher.displayCharacter();
    cout << dialogue[1] << endl;

    Item caughtFish = fisher.fish();

    // A9 note (for later : D) if (player.getRole() == fisher){
    // cout << "you're a finsher, you gain 10 extra gold" << endl;
    // player.addMoney(10);
    // }

    // applied for the hunter too, just change "fisher" to "hunter" and add it to the forest action


    player.addItem(caughtFish);
    player.useEnergy(2);

    cout << "You caught ";
    caughtFish.display();
}

void Game::forestAction()
{
    if (player.getEnergy() < 3)
    {
        cout << "You do not have enough energy." << endl;
        return;
    }

    hunter.displayCharacter();
    cout << dialogue[2] << endl;

    Item foundItem = hunter.hunt();

    player.addItem(foundItem);
    player.useEnergy(3);

    cout << "You found ";
    foundItem.display();
}
//A10 note energy potion, not HP. (infinite money glitch, this is a logical flaw i did)
void Game::alchemistAction()
{
    alchemist.displayCharacter();
    cout << dialogue[3] << endl;

    cout << "1. Buy a potion for 20 gold" << endl;
    cout << "2. Leave" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        if (player.spendMoney(20))
        {
            player.restoreEnergy();
            cout << "Your energy was restored." << endl;
        }
        else
        {
            cout << "You do not have enough money." << endl;
        }
    }
}

void Game::casinoAction()
{
    int moneyNeeded = 50;

    if (player.getMoney() < moneyNeeded)
    {
        cout << "You need at least 50 gold to enter the casino." << endl;
        return;
    }

    casinoOwner.displayCharacter();
    cout << dialogue[4] << endl;

    cout << "1. Bet 50 gold" << endl;
    cout << "2. Leave" << endl;
    cout << "Choice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        if (!player.spendMoney(50))
        {
            cout << "You do not have enough money." << endl;
            return;
        }

        casinoInfluence++;

        int result = rand() % 4;

        if (result == 0)
        {
            player.addMoney(100);
            cout << "You won 100 gold." << endl;
        }
        else
        {
            cout << "You lost the bet." << endl;

            if (player.getMoney() == 0)
            {
                jailEnding = true;
                gameOver = true;
            }
        }
    }
}

void Game::endDay()
{
    player.nextDay();
    cout << "The day is over." << endl;
}
// A12 where the program checks the conditions for winning/losing
bool Game::checkWin()
{
    if (player.getInfluence() >= 50)
    {
        return true;
    }

    if (player.getMoney() >= 200)
    {
        return true;
    }

    return false;
}

bool Game::checkLoss()
{
    if (jailEnding)
    {
        return true;
    }

    if (player.getDay() > 3)
    {
        return true;
    }

    return false;
}
// A13 note all endnings with added conditions for the "secret ending"
void Game::displayEnding()
{
    cout << endl;
    cout << "==================================" << endl;

    if (jailEnding)
    {
        cout << "[jail time! (ending A)]" << endl;
    }
    else if (player.getMoney() >= 200 && casinoInfluence >= 3)
    {
        cout << "[Too good for the casino, you win! (ending B)]" << endl;
    }
    else if (player.getInfluence() >= 50)
    {
        cout << "[no more aura to be collected, people will listen to you to matter what (ending C)]" << endl;
    }
    else if (player.getMoney() >= 200)
    {
        cout << "[you bought all the votes, your friend is the mayor now! (ending D)]" << endl;
    }
    else if (playerQuit)
    {
        cout << "[-9999 aura (ending E)]" << endl;
    }
    else
    {
        cout << "[you lost, try again in 4 years (ending F)]" << endl;
    }
    //A14 note so the program won't close before the ending (you won't see the ending msg lmao)
    cout << endl;
      cout << "Press Enter to close the game.";
       cin.ignore();
        cin.get();

    cout << "Game Over" << endl;
}
