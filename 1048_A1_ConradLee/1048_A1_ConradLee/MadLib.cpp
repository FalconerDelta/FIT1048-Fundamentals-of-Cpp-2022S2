/**************************************************
  Project: The Amazing Mad Lib Story Generator.
   Author: Conrad Lee
  Purpose: Application File
  “Mad Libs is a phrasal template word game where 
  one player prompts others for a list of words to
  substitute for blanks in a story” Wikipedia
 **************************************************/
#include "Madness.h"

int main() {
	// seed random
	srand(unsigned(time(nullptr)));
	
	// display menu
	runMenu();

	// exit message
	cout << " Thank you for testing this application.\n\n";
	
	// wait and exit
	system("pause");
	return 0;
}

void runMenu() {

	int exitFlag = 0;

	// display the menu
	// make decision based on user's input
	do {
		displayMenu();
		string userSelection = askForString("Which option would you like (0-5): ");
		userSelection = userSelection.at(0);
		cout << endl;

		if (userSelection == "0" || userSelection == "E") {
			//end the do...while loop
			exitFlag = 1;
		}
		else if (userSelection == "1" || userSelection == "I") {
			system("CLS");
			displayTextData(ABOUT);
			system("pause");
		}
		else if (userSelection == "2" || userSelection == "R") {
			createLists(DATA);
			system("pause");
		}
		else if (userSelection == "3" || userSelection == "G") {
			if (madLibs.empty() || madBits.empty()) {
				cout << "Data is not loaded, please select Option 2 to read data, or try other options." << endl << endl;
			}
			else {
				generateMadLib();
			}
			system("pause");
		}
		else if (userSelection == "4" || userSelection == "S") {
			if (currentMadLib == "") {
				cout << "Mad Lib is not generated, please select Option 3 to create one, or try other options." << endl << endl;
			}
			else {
				saveData(SAVEDFILE);
			}
			system("pause");
		}
		else if (userSelection == "5" || userSelection == "L") {
			loadData(SAVEDFILE);
			system("pause");
		}
		else {
			cout << " Please Enter 0-5 or corresponding shortcut character.\n\n";
			system("pause");
		}

	} while (exitFlag == 0);

}

void displayTextData(string aboutFile) {
	//read the file that contains the about information
	readFile(aboutFile);
	cout << endl;
}

void createLists(string myFileName) {
	// make sure vectors are empty
	madLibs.clear();
	madBits.clear();

	// convert MadLibData.txt to vector
	// split and put strings into the vector with ; as the delimiter
	// and split it into two variables with the \n
	ifstream fileToRead(myFileName);
	if (fileToRead.is_open()) {
		string temp = "";
		string line = "";
		int flag = 0;
		while (!fileToRead.eof()) {
			getline(fileToRead, line, ';');
			if (flag == 0) {
				if (line.find('\n') == line.npos) {
					madLibs.push_back(line);
				}
				else {
					temp = line.substr(0, line.find('\n'));
					madLibs.push_back(temp);
					flag = 1;
					temp = line.substr(line.find('\n') + 1);
					madBits.push_back(temp);
				}
			}
			else {
				madBits.push_back(line);
			}
		}
	}
	else {
		cout << "\n " << myFileName << " not found!\n";
	}

	cout << "   Data Loaded from " << myFileName << "\n\n";
	fileToRead.close();
}

void generateMadLib() {
	//declare local variables
	vector<string> madBits1;
	vector<string> madBits2;
	vector<string> madBits3;

	// clear existing variable
	currentMadLib = "";

	// get random numbers to select elements from madLibs/madBits and make sure indices not duplicate 
	int randIndex [3] = {0, 0, 0};
	while (randIndex[0] == randIndex[1]) {
		randIndex[0] = rand() % madLibs.size();
		randIndex[1] = rand() % madLibs.size();
	}

	do {
		randIndex[2] = rand() % madLibs.size();
	} while (randIndex[1] == randIndex[2] || randIndex[2] == randIndex[0]);
	
	// splitting words into elements of a vector
	madBits1 = prepareMadBits(randIndex[0]);
	madBits2 = prepareMadBits(randIndex[1]);
	madBits3 = prepareMadBits(randIndex[2]);
	
	// ask user to enter mad bits
	madBits1 = updateMadBits(madBits1);
	madBits2 = updateMadBits(madBits2);
	madBits3 = updateMadBits(madBits3);

	// replace "WORD" in madLibs with saved user input in madBits1/2/3 
	updateMadLibs(madBits1, randIndex[0]);
	updateMadLibs(madBits2, randIndex[1]);
	updateMadLibs(madBits3, randIndex[2]);

	// format and display Mad Lib
	for (int i = 0; i < 3; i++) {
		currentMadLib += madLibs[randIndex[i]] + "\n";
	}
	cout << currentMadLib << endl;

	// clean up variables and reset to default list
	madBits1.clear();
	madBits2.clear();
	madBits3.clear();
	cout.setstate(std::ios_base::failbit); // silently discard output
	createLists(DATA);
	cout.clear(); // clear the failbit
}

void saveData(string myFileName) {
	// thought about to only save user defined mad bits, 
	// but it would be hard for users to export the madlib and share it with others
	// 
	// ask for user input and make decision using switch
	int ans = 0;
	int exitFlag = 0;
	do {
		displayMenu();
		cout << " Which option would you like (0-5): 4\n\n";
		cout << currentMadLib << endl;
		string answer = askForString("Do you want to save this Mad Lib ? (y/n) ");
		answer = answer.at(0);

		if (answer == "Y" || answer == "y") {
			ans = 1;
			exitFlag = 1;
		}
		else if (answer == "N" || answer == "n") {
			ans = 2;
			exitFlag = 1;
		}
		else {
			cout << " Invalid input. Please try again." << endl << endl;
			system("pause");
		}
	} while (exitFlag == 0);

	ofstream fileHandler(myFileName, ios::app);

	switch (ans) {
	case 1:
		if (fileHandler.is_open()) {
			fileHandler << currentMadLib << endl;
			fileHandler.close();
			cout << " This Mad Lib is now saved." << endl << endl;
		}
		else {
			cout << " Cannot write data or file not there." << endl << endl;
		}
		break;
	case 2:
			cout << " Mad Lib is not saved. Now return to menu." << endl << endl;
			return;
		
	}
}

void loadData(string myFileName) {
	// read the file that saves the past Mad Libs
	readFile(myFileName);
}

string askForString(string question) {
	// takes question(string) as variable
	// format the question and ask until a non-empty answer entered by the user
	string answer = "";
	while (answer == "") {
		cout << " " + question;
		getline(cin, answer);
	}
	return answer;
}

void readFile(string myFileName) {
	// read given file
	ifstream fileToRead(myFileName);
	// Open the file and check if there is any error present.
	if (fileToRead.is_open()) {
		string myData;
		while (!fileToRead.eof()) {
			getline(fileToRead, myData);
			cout << "" << myData << "\n";
		}
		fileToRead.close();
	}
	else {
		cout << " " << myFileName << " not found." << endl << endl;
	}

}

vector<string> prepareMadBits(int index) {
	// using stringstream to extract substr from the selected madBits
	vector<string> temp;

	stringstream ss(madBits[index]);
	while (ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		temp.push_back(substr);
	}

	return temp;
}

vector<string> updateMadBits(vector<string> vec) {
	// ask for user input, check whether input is empty
	// and replace the questions inside the vector with answers
	for (size_t i = 0; i != vec.size(); ++i) {
		string question = "Enter " + vec[i] + ": ";
		int exitFlag = 0;
		string answer = "";

		do { 
			answer = askForString(question);
			if (answer != "") {
				exitFlag = 1;
			}
		} while (exitFlag == 0);
		vec[i] = answer;
	}
	cout << endl;

	return vec;
}

void updateMadLibs(vector<string> vec, int index) {
	// replace keyword to saved madbits
	for (int i = 0; i != vec.size(); i++) {
		madLibs[index] = madLibs[index].replace(madLibs[index].find(KEYWORD), KEYWORD.size(), vec[i]);
	}
}

void displayMenu() {
	// display the texts of the menu
	system("CLS");
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "    The Amazing Mad Lib Story Generator    " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " [0] [E]nd Testing the Program" << endl;
	cout << " [1] Display \"About\" [I]nformation" << endl;
	cout << " [2] [R]ead and store data from files" << endl;
	cout << " [3] [G]enerate a random Mad Lib" << endl;
	cout << " [4] [S]ave a Mad Lib to file" << endl;
	cout << " [5] [L]oad saved Mad Lib from file" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}