#include <iostream>
#include "Utils.h"
#include <string>
#include "Add_Word.h"

using namespace std;

void printLettersOnRow(char* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            cout << arr[i];
            cout << endl;
            break;
        }
        cout << arr[i] << ", ";
    }
}

void fillArrWithRndChars(char* arr, int length)
{
    char c;
    int rnd = 0;

    srand(time(NULL));    // initialize the random number generator
    for (int j = 0; j < length; j++)
    {
        rnd = rand() % 26;
        c = 'a' + rnd;
        arr[j] = c;
    }
}

bool checkIfWordContainsWrongLetter(char* arr, int length, int letters, string word)
{
    for (int j = 0; j < length; j++)
    {
        if (!contains(arr, letters, word[j]))
        {
            return true;
        }
    }
    return false;
}

void printOutputFromRound(string word, int& points, int currentRound, int rounds, bool wrongWord)
{
    string output;
    if (!wrongWord)
    {
        if (checkIfWordIsInDict(word))
        {
            points += word.length();
            output = "Correct word. Your current points are: " + to_string(points);
            printColorText(output, 2); //green
        }
        else
        {
            output = "Your word is not in the dictionary. You are awarded 0 points.";
            printColorText(output, 4); //red
        }
    }
    else
    {
        output = "Your word is incorrect. You are awarded 0 points.";
        printColorText(output, 4); //red
    }

    if (currentRound == rounds)
    {
        output = "Your final score is: " + to_string(points);
        output += ". Thank you for playing!";
        printColorText(output, 11); //bright cyan
    }
}

void game(int rounds, int letters)
{
    cout << "\tGame starting:" << endl;
    int points = 0;

    for (int i = 1; i <= rounds; i++)
    {
        cout << "Round " << i << ":" << endl;

        char* lettersOnRow = new char[letters] {};
        fillArrWithRndChars(lettersOnRow, letters);

        cout << "The letters availiable to use are: ";
        printLettersOnRow(lettersOnRow, letters);

        string word;
        cout << "Enter your word: ";
        cin >> word;
        int wordLength = word.length();

        bool wordContainsWrongLetter = checkIfWordContainsWrongLetter(lettersOnRow, wordLength, letters, word);

        printOutputFromRound(word, points, i, rounds, wordContainsWrongLetter);
    }
}
