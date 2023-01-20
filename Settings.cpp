#include "Utils.h"
#include "Setting.h"
#include <iostream>

using namespace std;

void printPossibleSettings(int rounds, int letters)
{
    cout << "\tSetting options:" << endl;
    cout << "1.Change the number of letters per round(current number is " << letters << ")" << endl;
    cout << "2.Change the number of round(current number is " << rounds << ")" << endl;
    cout << "3.Back" << endl;
}


void changingSettings(int& rounds, int& letters, int maxRounds, int minRounds, int maxLetters, int minLetters)
{
    printPossibleSettings(rounds, letters);

    int minSettingNum = 1;
    int maxSettingNum = 3;

    int settingChoice = 0;

    cout << "Enter your choice: ";
    cin >> settingChoice;
    settingChoice = choiceSelection(settingChoice, minSettingNum, maxSettingNum);

    if (settingChoice == 2)
    {
        int newRounds = 0;
        cin >> newRounds;

        rounds = choiceSelection(newRounds, minRounds, maxRounds);
    }
    else if (settingChoice == 1)
    {
        int newLetters = 0;
        cin >> newLetters;

        letters = choiceSelection(newLetters, minLetters, maxLetters);
    }
}
