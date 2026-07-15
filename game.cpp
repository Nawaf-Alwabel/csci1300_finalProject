#include "Game.h"

#include <iostream>
#include <limits>

Game::Game()
    : fisher("Finn", 25, 10, 15),
      hunter("Hunter", 25, 10, 15)
{
    running = true;
    day = 1;
}

void Game::displayMainMenu() const
{
    std::cout << "\n--- Goofy Mayor Campaign ---" << std::endl;
    std::cout << "Day: " << day << std::endl;
    std::cout << "1. View character status" << std::endl;
    std::cout << "2. Perform a daily action" << std::endl;
    std::cout << "3. Advance to the next day" << std::endl;
    std::cout << "4. Exit game" << std::endl;
    std::cout << "Enter choice: ";
}

void Game::loadDialogue()
{
    ifstream inputFile("dialogue.txt");

    if (inputFile.fail())
    {
        cout << "Could not open dialogue.txt" << endl;

        for (int i = 0; i < 5; i++)
        {
            dialogue[i] = "";
        }

        return;
    }

    for (int i = 0; i < 5; i++)
    {
        getline(inputFile, dialogue[i]);
    }

    inputFile.close();
}

void Game::displayStatus() const
{
    std::cout << "\n--- Character Status ---" << std::endl;

    fisher.showRole();
    std::cout << "Name: " << fisher.getName() << std::endl;
    std::cout << "Money: " << fisher.getMoney() << std::endl;
    std::cout << "Reputation: " << fisher.getReputation() << std::endl;

    std::cout << std::endl;

    hunter.showRole();
    std::cout << "Name: " << hunter.getName() << std::endl;
    std::cout << "Money: " << hunter.getMoney() << std::endl;
    std::cout << "Reputation: " << hunter.getReputation() << std::endl;
}

void Game::performDailyAction()
{
    int action_choice = 0;

    std::cout << "\nChoose an action:" << std::endl;
    std::cout << "1. Go fishing" << std::endl;
    std::cout << "2. Go hunting" << std::endl;
    std::cout << "3. Return to main menu" << std::endl;
    std::cout << "Enter choice: ";

    std::cin >> action_choice;

    if (action_choice == 1)
    {
        fisher.fish();
    }
    else if (action_choice == 2)
    {
        hunter.hunt();
    }
    else if (action_choice == 3)
    {
        std::cout << "Returning to the main menu." << std::endl;
    }
    else
    {
        std::cout << "Invalid action choice." << std::endl;
    }
}

void Game::advanceDay()
{
    day++;

    std::cout << "A new campaign day begins." << std::endl;
}

void Game::run()
{
    int choice = 0;

    std::cout << "Your goofy friend wants to become mayor." << std::endl;
    std::cout << "Help build money and reputation before time runs out."
              << std::endl;

    while (running)
    {
        displayMainMenu();

        if (!(std::cin >> choice))
        {
            std::cin.clear();

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter a number from 1 to 4." << std::endl;
            continue;
        }

        if (choice == 1)
        {
            displayStatus();
        }
        else if (choice == 2)
        {
            performDailyAction();
        }
        else if (choice == 3)
        {
            advanceDay();
        }
        else if (choice == 4)
        {
            running = false;

            std::cout << "Exiting game." << std::endl;
        }
        else
        {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}
