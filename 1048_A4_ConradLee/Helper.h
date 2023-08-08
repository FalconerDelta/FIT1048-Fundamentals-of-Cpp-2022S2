/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Helper Class HEADER File
 **************************************************/
#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <vector>
using namespace std;

class Helper {
public:
	static int genValue(int min, int max);
	static char inputLetter(vector<char> acceptedCommands, string text);
	static void clearScreen();
	static void waitForKeyPress();
};

#endif