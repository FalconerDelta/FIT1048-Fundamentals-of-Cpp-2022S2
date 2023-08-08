/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Helper Class File
 **************************************************/
#include "Helper.h"

// Generate pseudo random number
int Helper::genValue(int min, int max) {
	return (rand() % (max - min + 1) + min);
}

// Get input from a list of accepted characters, with text as the preceding text before the input
char Helper::inputLetter(vector<char> acceptedCommands, string text) {
	char choice;
	do {
		cout << text;
		cin >> choice;
	} while (find(acceptedCommands.begin(), acceptedCommands.end(), choice) == acceptedCommands.end()
		&& find(acceptedCommands.begin(), acceptedCommands.end(), toupper(choice)) == acceptedCommands.end());
	return toupper(choice);
}

// Clear Screen with system()
void Helper::clearScreen() {

	system("CLS");

}

// System Pause
void Helper::waitForKeyPress() {

	system("pause");
	clearScreen();

}