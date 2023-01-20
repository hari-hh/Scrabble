#ifndef UTILS_H
#define UTILS_H

#include <string>
using std::string;

string toUpper(string word);
void toLower(char& letter);
bool contains(char* arr, int length, char symbol);
void printStartMenu();
void printColorText(string text, int colorCode);
bool checkIfWordIsInDict(string word);
int choiceSelection(int choice, int min, int max);

#endif