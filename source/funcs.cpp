#include <iostream>
#include <time.h>
#include "../headers/funcs.h"


void printCampoJuego(char *array0, char *array1, char *array2)
{
    std::cout << "   0  1  2" << std::endl;
    std::cout << "   _______" << std::endl;
    std::cout << "0  |" << array0[0] << "|" << array0[1] << "|" << array0[2] << "|" << std::endl;
    std::cout << "1  |" << array1[0] << "|" << array1[1] << "|" << array1[2] << "|" << std::endl;
    std::cout << "2  |" << array2[0] << "|" << array2[1] << "|" << array2[2] << "|\n";
    std::cout << "   ¯¯¯¯¯¯¯" << std::endl;
}

bool isValid(char valorArray)
{
    bool valid = true;
    if (valorArray != ' ')
        valid = false;
    return valid;
}

void iaChoses(char array0[], char array1[], char array2[])
{
    bool goodSelection = false;
    int maq1;
    int maq2;
    srand(time(NULL));
    while (!goodSelection)
    {

        maq1 = rand() % 3 + 0;
        maq2 = rand() % 3 + 0;
        if (maq1 == 0)
        {
            if (isValid(array0[maq2]))
            {
                array0[maq2] = 'O';
                goodSelection = true;
            }
        }
        else if (maq1 == 1)
        {
            if (isValid(array1[maq2]))
            {
                array1[maq2] = 'O';
                goodSelection = true;
            }
        }
        else if (maq1 == 2)
        {
            if (isValid(array2[maq2]))
            {
                array2[maq2] = 'O';
                goodSelection = true;
            }
        }
    }
}

void userChoses(char *array0, char *array1, char *array2)
{
    bool goodSelection = false;
    int x;
    int per1;
    int per2;
    std::cout << "REMEMBER: 1st choise = left number, 2nd choice top number\n";
    while (!goodSelection)
    {
        std::cout << "Choose your 1st: ";
        std::cin >> per1;
        std::cout << "Now your 2nd: ";
        std::cin >> per2;

        if (per1 == 0)
        {
            if (isValid(array0[per2]))
            {
                array0[per2] = 'X';
                goodSelection = true;
            }
        }
        else if (per1 == 1)
        {
            if (isValid(array1[per2]))
            {
                array1[per2] = 'X';
                goodSelection = true;
            }
        }
        else if (per1 == 2)
        {
            if (isValid(array2[per2]))
            {
                array2[per2] = 'X';
                goodSelection = true;
            }
        }
    }
}

// Function that returns X or O, depends in who won (if anyone did, since this is verified every turn)
char areThreeTogether(char *array0, char *array1, char *array2)
{
    char winner = ' ';
    if (array0[0] == 'X' && array0[1] == 'X' && array0[2] == 'X' || array0[0] == 'O' && array0[1] == 'O' && array0[2] == 'O')
    {
        // Test if the first line from left to right is the winner
        winner = array0[0];
    }
    else if (array0[0] == 'X' && array1[0] == 'X' && array2[0] == 'X' || array0[0] == 'O' && array1[0] == 'O' && array2[0] == 'O')
    {
        // Test if the first column from top to bottom is the winner
        winner = array0[0];
    }
    else if (array0[0] == 'X' && array1[1] == 'X' && array2[2] == 'X' || array0[0] == 'O' && array1[1] == 'O' && array2[2] == 'O')
    {
        // Test if the first diagonal from top-left to bottom-right is the winner
        winner = array0[0];
    }
    else if (array0[2] == 'X' && array1[1] == 'X' && array2[0] == 'X' || array0[2] == 'O' && array1[1] == 'O' && array2[0] == 'O')
    {
        // Test if the last diagonal from top-right to bottom-left is the winner
        winner = array0[2];
    }
    else if (array0[1] == 'X' && array1[1] == 'X' && array2[1] == 'X' || array0[1] == 'O' && array1[1] == 'O' && array2[1] == 'O')
    {
        // Test if the second column from top to bottom is the winner
        winner = array0[1];
    }
    else if (array0[2] == 'X' && array1[2] == 'X' && array2[2] == 'X' || array0[2] == 'O' && array1[2] == 'O' && array2[2] == 'O')
    {
        // Test if the third column from top to bottom is the winner
        winner = array0[2];
    }
    else if (array1[0] == 'X' && array1[1] == 'X' && array1[2] == 'X' || array1[0] == 'O' && array1[1] == 'O' && array1[2] == 'O')
    {
        // Test if the second line from left to right is the winner
        winner = array1[0];
    }
    else if (array2[0] == 'X' && array2[1] == 'X' && array2[2] == 'X' || array2[0] == 'O' && array2[1] == 'O' && array2[2] == 'O')
    {
        // Test if the third line from left to right is the winner
        winner = array2[0];
    }
    return winner;
}