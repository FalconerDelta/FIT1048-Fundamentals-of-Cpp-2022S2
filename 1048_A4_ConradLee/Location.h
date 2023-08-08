/**************************************************
  Project: The Treasure Caverns of Doom
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
#include "Dragon.h"
#include "Helper.h"
#include "TreasureHunter.h"

using namespace std;

class Location {

private:
	// location variables
	string locationName;
	string locationDescription;
	// exits[0] = North exit, exits[1] = East exit, exits[2] = South exit, exits[3] = West exit
	int exits[4];
	Monster* enemy = NULL;
	Item* loot = NULL;
	TreasureHunter* hunter = NULL;
	bool enemyExists = false;
	bool lootExists = false;
	bool hunterExists = false;

public:
	// constructor
	Location() : Location("") {};
	Location(string name);
	~Location();

	// accessor methods
	string getLocationName();
	string getLocationDescription();
	string displayMonster();
	string displayItem();
	string getDetails();
	bool isEnemyExists();
	bool isLootExists();
	bool isHunterExists();
	int getNorthExit();
	bool hasNorthExit();
	int getEastExit();
	bool hasEastExit();
	int getSouthExit();
	bool hasSouthExit();
	int getWestExit();
	bool hasWestExit();
	Monster* getMonster();
	Item* getItem();
	TreasureHunter* getHunter();

	// mutator methods
	void setLocationName(string newLocation);
	void setLocationDescription(string newInfo);
	void setExit(int index, int exit);
	void setMonster(MonsterType newMonster);
	void setItem(Item* newItem);
	void setHunter(TreasureHunter* hunter);
	void removeHunter();
	void removeMonster();
	void removeItem();
};

#endif