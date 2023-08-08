/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Location Class File
 **************************************************/
#include "Location.h"

 // constructor
Location::Location(string name) {

	locationName = name;

}

Location::~Location(){}

// accessor methods
string Location::getLocationName() {
	return locationName;
}

string Location::getLocationDescription() {
	return locationDescription;
}

string Location::displayMonster() {
	return enemy->getMonsterName();
}

string Location::displayItem() {
	return loot->getItemName();
}

string Location::getDetails() {
	// returns a formatted string
	stringstream locationDetails;
	locationDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	locationDetails << "\n Location Name: " << getLocationName();
	locationDetails << "\n Location Info: " << getLocationDescription();
	if (enemyExists) {
		locationDetails << "\n Monster      : " << displayMonster();
	}
	if (lootExists) {
		locationDetails << "\n Loot         : " << displayItem();
	}
	locationDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return locationDetails.str();
}

bool Location::isEnemyExists() {
	return enemyExists;
}

bool Location::isLootExists() {
	return lootExists;
}

bool Location::isHunterExists() {
	return hunterExists;
}

int Location::getNorthExit() {
	return exits[0];
}

bool Location::hasNorthExit() {
	return exits[0] != -1;
}

int Location::getEastExit() {
	return exits[1];
}

bool Location::hasEastExit() {
	return exits[1] != -1;
}

int Location::getSouthExit() {
	return exits[2];
}

bool Location::hasSouthExit() {
	return exits[2] != -1;
}

int Location::getWestExit() {
	return exits[3];
}

bool Location::hasWestExit() {
	return exits[3] != -1;
}

Monster* Location::getMonster() {
	return enemy;
}

Item* Location::getItem() {
	return loot;
}

TreasureHunter* Location::getHunter() {
	return hunter;
}

// mutator methods


void Location::setLocationName(string newLocation) {
	locationName = newLocation;
}

void Location::setLocationDescription(string newInfo) {
	if (newInfo != "") {
		locationDescription = newInfo;
	}
}

void Location::setExit(int index, int exit) {
	exits[index] = exit;
}

void Location::setMonster(MonsterType newMonster) {
	enemy = Monster::initNewMonster(newMonster);
	enemyExists = true;
}

void Location::setItem(Item* newItem) {
	loot = newItem;
	lootExists = true;
}

void Location::setHunter(TreasureHunter* hunter) {
	this->hunter = hunter;
	hunterExists = true;
}

void Location::removeHunter() {
	if (hunterExists) {
		hunter = NULL;
		hunterExists = false;
	}
}

void Location::removeMonster() {
	if (enemyExists) {
		// The enemy would never move, so delete the enemy here
		// To release memory
		delete enemy;
		enemyExists = false;
	}
}

void Location::removeItem() {
	if (lootExists) {
		loot = NULL;
		lootExists = false;
	}
}
