#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Utils.h"
#include "Setting.h"
#include "Add_Word.h"
#include "Game.h"

using namespace std;

const int MAX_ROUNDS = 100;
const int MIN_ROUNDS = 1;
const int MAX_LETTERS = 100;
const int MIN_LETTERS = 1;

int main()
{
    int choice = 0;
    int minChoice = 1;
    int maxChoice = 4;
    int rounds = 10;
    int numberOfLetters = 10;

    while (true)
    {
        printStartMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        choice = choiceSelection(choice, minChoice, maxChoice);

        switch (choice)
        {
        case 1:
            game(rounds, numberOfLetters);
            break;
        case 2:
            changingSettings(rounds, numberOfLetters, MAX_ROUNDS, MIN_ROUNDS, MAX_LETTERS, MIN_LETTERS);
            break;
        case 3:
            addWord();
            break;
        case 4:
            string exitText = "Thank you for playing Scrabble!";
            printColorText(exitText, 13);
            return 0;
        }

        cout << endl;
        cout << endl;
    }
}