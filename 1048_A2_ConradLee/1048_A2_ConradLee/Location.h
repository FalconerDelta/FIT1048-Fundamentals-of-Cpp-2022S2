/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Location Class HEADER File
 **************************************************/
#ifndef LOCATION_H
#define LOCATION_H

 // includes and name space
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include "Enums.h"
#include "Monster.h"
#include "Item.h"
#include "Dragons.h"

using namespace std;

class Location {

private:
	// location variables
	string locationName;
	string locationDescription;
	int exits[3];
	Monster enemy;
	Item loot;
	bool playerExist;


	// Load from file is in Assignment 4's brief
	// Hardcoding as temp solution for Assignment 2
	string locations[20]{
	"Origin End Point",
	"Twin Overwatch",
	"The Rat Tree",
	"Formally Suited Trolls Cave",
	"Fairy Valkyrie Cave",
	"Sensitive bee wax Cave",
	"Small Eve Night Room",
	"The Eighth Tomb Stone",
	"Nine tails ruins",
	"Tented Bee Hive",
	"Elephant War Wreckage",
	"Tweety's cage",
	"Thirsty Lion Den",
	"Fountain Of The Undead",
	"Five Fire Flies Cave",
	"Sentinel Exodus",
	"Sick Evening Illusion Pond",
	"Never Ending Dream Room",
	"No Guardian Here Room",
	"Twin Swen Statue Hall"
	};

	int exitsTable[20][3]{
		{5,8,2},
		{1,10,3},
		{2,12,4},
		{3,14,5},
		{4,6,1},
		{7,5,15},
		{6,17,8},
		{7,1,9},
		{8,18,10},
		{9,2,11},
		{10,19,12},
		{11,3,13},
		{12,20,14},
		{13,4,15},
		{14,16,6},
		{17,15,20},
		{16,7,18},
		{17,9,19},
		{18,11,20},
		{19,13,16}
	};

	// helper
	int exitLookUp(string currentLocation, int index);
	int genValue(int min, int max);

public:
	// constructor
	Location();
	Location(string name);
	~Location();

	// accessor methods
	string getLocationName();
	string getLocationDescription();
	string displayExits();
	string displayMonster();
	string displayItem();
	string getPlayerExist();

	string getDetails();

	// mutator methods
	void setLocationName(string newLocation);
	void setLocationDescription(string newInfo);
	void setExits(int newExits[3]);
	void setMonster(Monsters newMonster);
	void setItem(Items newItem);
	void setPlayerExist(bool status);

	void updateMonsterStats(Monsters newMonster);
	void updateItemStatus(Items newItem);
	void updatePlayerExist(bool status);
};

#endif