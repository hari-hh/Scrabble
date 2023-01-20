#include <iostream>
#include "Add_Word.h"
#include <string>
#include <fstream>
#include "Utils.h"

using namespace std;

void addWord()
{
    string word;
    string output;
    cin >> word;

    fstream file;

    file.open("scrabble dict.txt", ios::app);

    if (file.fail())
    {
        cout << "Error opening the file.";
        return;
    }

    if (checkIfWordIsInDict(word))
    {
        output = word + " is already in the dictionary.";
        printColorText(output, 12);
        return;
    }

    file << "\n" + toUpper(word);
    output = word + " was successfully added to the dictionary.";
    printColorText(output, 14);

    file.close();
}
