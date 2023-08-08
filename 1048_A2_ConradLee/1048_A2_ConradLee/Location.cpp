/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Location Class File
 **************************************************/
#include "Location.h"

 // constructor
Location::Location() {
	locationName = "Origin End Point";
	locationDescription = "Dangerous Place";
	exits[0] = 5;
	exits[1] = 8;
	exits[2] = 2;
	enemy = Monster::Monster(Monsters::Goblin);
	loot = Item::Item(Items::Gems);
	playerExist = false;
}

// overload constructer that only spawn higher rank monster in inner ring of the map
Location::Location(string name) {
	bool outerRing = find(begin(locations), end(locations)-5, name) < end(locations)-5; // check if belongs to outer ring
	bool exists = find(begin(locations), end(locations), name) != end(locations); // check if valid location name
	playerExist = false;
	if (exists) {
		locationName = name;
		locationDescription = "Dangerous Place";
		for (unsigned int i = 0; i < sizeof(exits)/sizeof(exits[0]); i++) {
			exits[i] = exitLookUp(name, i);
		}

		if (outerRing) {
			int random = genValue(0,1);
			switch (random) {
			case 0: 
				enemy = Monster::Monster(Monsters::Goblin);
				break;
			case 1: 
				enemy = Monster::Monster(Monsters::Hobgoblin);
				break;
			default: 
				enemy = Monster::Monster(Monsters::Goblin);
				break;
			}

		}
		else {
			int random = genValue(0, 2);
			switch (random) {
			case 0:
				enemy = Monster::Monster(Monsters::Ogre);
				break;
			case 1:
				enemy = Monster::Monster(Monsters::Troll);
				break;
			default:
				enemy = Dragons::Dragons("Final Boss", true);
				break;
			}
		}
	}
	
	
}

Location::~Location(){}

// accessor methods
string Location::getLocationName() {
	return locationName;
}

string Location::getLocationDescription() {
	return locationDescription;
}

string Location::displayExits() { // translate exit index to location name
	// returns a formatted string
	stringstream exitDetails;
	exitDetails << "\n~~~~~~~~~~~~~~~~~ Exits ~~~~~~~~~~~~~~~~";
	for (unsigned int i = 0; i < sizeof(exits)/sizeof(exits[0]); i++) {
		exitDetails << "\n Exit " << i+1 << " : " << locations[exits[i] - 1];
	}
	exitDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	return exitDetails.str();
}

string Location::displayMonster() {
	return enemy.getMonsterName();
}

string Location::displayItem() {
	return loot.getItemName();
}

string Location::getPlayerExist() {
	switch (playerExist) {
	case true: 
		return "true";
	case false:
		return "false";
	}
}

string Location::getDetails() {
	// returns a formatted string
	stringstream locationDetails;
	locationDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	locationDetails << "\n Location Name: " << getLocationName();
	locationDetails << "\n Location Info: " << getLocationDescription();
	locationDetails << "\n Monster      : " << displayMonster();
	locationDetails << "\n Loot         : " << displayItem();
	locationDetails << "\n Player Exist?: " << getPlayerExist();
	locationDetails << displayExits();
	locationDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return locationDetails.str();
}

// mutator methods


void Location::setLocationName(string newLocation) { // Check if entered name exists
	bool exists = find(begin(locations), end(locations), newLocation) != end(locations);
	if (exists == true) {
		locationName = newLocation;
	}
	else {
		locationName = "Origin End Point";
	}
}

void Location::setLocationDescription(string newInfo) {
	if (newInfo != "") {
		locationDescription = newInfo;
	}
}

void Location::setExits(int newExits[3]) { // Technically just copying array
	if (sizeof(newExits) == 3) {
		for (unsigned int i = 0; i < sizeof(newExits); i++) {
			exits[i] = newExits[i];
		}
	}
}

void Location::setMonster(Monsters newMonster) {
	if (newMonster >= Monsters::Goblin && newMonster <= Monsters::Dragon) {
		enemy = Monster::Monster(newMonster);
	}
}

void Location::setItem(Items newItem) {
	if (newItem >= Items::Map && newItem <= Items::Tome) {
		loot = Item::Item(newItem);
	}
}

void Location::setPlayerExist(bool status) {
	if(status == true || status == false) {
		playerExist = status;
	}
}

void Location::updateMonsterStats(Monsters newMonster) {
	if (newMonster >= Monsters::Goblin && newMonster <= Monsters::Dragon) {
		enemy = Monster::Monster(newMonster);
	}
}

void Location::updateItemStatus(Items newItem) {
	if (newItem >= Items::Map && newItem <= Items::Tome) {
		loot = Item::Item(newItem);
	}
}

void Location::updatePlayerExist(bool status) {
	if (status == true || status == false) {
		playerExist = status;
	}
}

int Location::exitLookUp(string currentLocation, int index) { // Lookup for exit index based on input name
	for (unsigned int i = 0; i < sizeof(locations)/sizeof(locations[0]); i++) {
		if (currentLocation == locations[i]) {
			return exitsTable[i][index];
		}
	}
}

int Location::genValue(int min, int max) {
	return (rand() % (max - min + 1) + min);
}
