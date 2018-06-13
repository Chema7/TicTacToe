#include <iostream>
#include <algorithm>
#include "../headers/funcs.h"

int main()
{
    bool player;
    bool game = true;
    char winner;
    char array0[] = {' ', ' ', ' '};
    char array1[] = {' ', ' ', ' '};
    char array2[] = {' ', ' ', ' '};
    int roundCounts = 0;

    system("cls");
    std::cout << "\n\n\t   ********* Welcome to TicTacToe ************\n";
    std::cout << "To place your X, you need to insert from 0 to 2, from top-left\n";
    std::cout << "Example: If you want to place your X in the first top left corner.\nYou need to enter 0 and 0\n";
    std::cout << "Another: If you want to place your X in the top right,\nit would be 0 and 2. Ez right?\n";
    std::cout << "\nSo let's begin.\nYou decide. Who do you want to start the game, you or AI?\n(Write me for you, anything for AI)\n";
    std::string selection;
    std::cin >> selection;
    std::transform(selection.begin(), selection.end(), selection.begin(), ::tolower);
    if (selection == "me")
    {
        std::cout << "Ok, so you start!\n";
        std::cout << "This is the map you will play in\n";
        player = true;
    }
    else
    {
        std::cout << "The AI won't be easy to beat!\n";
        std::cout << "This is the map you will play in\n";
        player = false;
    }
    while (game)
    {
        printCampoJuego(array0, array1, array2);
        if (!player)
        {
            std::cout << "The AI choses now.\n";
            iaChoses(array0, array1, array2);
            roundCounts++;
            player = true;
        }
        else
        {
            std::cout << "Your turn\n";
            userChoses(array0, array1, array2);
            roundCounts++;
            player = false;
        }
        // Test if anyone won the game
        winner = areThreeTogether(array0, array1, array2);
        if (winner != ' ')
        {
            game = true;
            if (winner == 'X')
            {
                printCampoJuego(array0, array1, array2);
                std::cout << "GAME OVER! WELL PLAYED, YOU WON!\n";
                game = false;
            }
            else
            {
                printCampoJuego(array0, array1, array2);
                std::cout << "GAME OVER! MY SUPER AI WON, YIHAAA!\n";
                game = false;
            }
        }
        // Test if the game is still ON and the map is completed
        if (roundCounts == 9 && game)
        {
            std::cout << "GAME OVER! NO ONE WON!\n"<<std::flush;
            game = false;
        }
    }
    std::system("pause");
}