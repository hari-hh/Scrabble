#include "Utils.h";
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

string toUpper(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = toupper(word[i]);
    }

    return word;
}

void toLower(char& letter)
{
    if (65 <= letter && letter <= 90)
    {
        letter = letter + 32;
    }
}

void printStartMenu()
{
    cout << "\t\tWelcome to Scrabble!" << endl;
    cout << "Please select the number representing your choice:" << endl;
    cout << "1.Start" << endl;
    cout << "2.Settings" << endl;
    cout << "3.Add a new word" << endl;
    cout << "4.Exit" << endl << endl;
}

bool contains(char* arr, int length, char symbol)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == symbol)
        {
            arr[i] = NULL;
            return true;
        }
    }

    return false;
}


void printColorText(string text, int colorCode)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, colorCode);
    cout << text << endl;
    SetConsoleTextAttribute(h, 7);
}

bool checkIfWordIsInDict(string word)
{
    word = toUpper(word);
    fstream file;

    file.open("scrabble dict.txt");

    if (!file.is_open())
    {
        cout << "Error opening the file" << endl;
    }

    while (!file.eof())
    {
        string currentWord;
        getline(file, currentWord);

        if (word == currentWord)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

int choiceSelection(int choice, int min, int max)
{
    if (choice < min || choice > max)
    {
        cout << "Invalid choice, please try again:" << endl;
        int newChoice = 0;
        cout << "Enter your new choice: ";
        cin >> newChoice;
        choice = choiceSelection(newChoice, min, max);
    }

    return choice;
}
