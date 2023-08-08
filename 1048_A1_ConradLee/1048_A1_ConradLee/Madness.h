#ifndef MADNESS_H
#define MADNESS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

// necessary global variables
vector<string> madLibs;
vector<string> madBits;
string currentMadLib;

// ease of access if variable need to be changed later
string KEYWORD = "WORD";
string ABOUT = "MadAbout.txt";
string DATA = "MadLibData.txt";
string SAVEDFILE = "savedMadLib.txt";

void runMenu();
void displayTextData(string aboutFile);
void createLists(string myFileName);
void generateMadLib();
void saveData(string myFileName);
void loadData(string myFileName);
string askForString(string question); 
void readFile(string myFileName);
vector<string> prepareMadBits(int index);
vector<string> updateMadBits(vector<string> vec);
void updateMadLibs(vector<string> vec, int index);
void displayMenu();


#endif
