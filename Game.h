#ifndef GAME_H
#define GAME_H

#include <string>
using std::string;

void printLettersOnRow(char* arr, int length);
void fillArrWithRndChars(char* arr, int length);
bool checkIfWordContainsWrongLetter(char* arr, int length, int letters, string word);
void printOutputFromRound(string word, int& points, int currentRound, int rounds, bool wrongWord);
void game(int rounds, int letters);


#endif