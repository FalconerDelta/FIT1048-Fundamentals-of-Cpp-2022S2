/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: TreasureHunter Class File
 **************************************************/
#include "TreasureHunter.h"
#include "Location.h"

// Constructor
TreasureHunter::TreasureHunter() {
	hunterType = TreasureHunterType::Gossiper;
	hunterName = "Gossiper";
}

// Destructor
TreasureHunter::~TreasureHunter() {}

// getters
Location* TreasureHunter::getLocation() {
	return location;
}

string TreasureHunter::getHunterName() {
	return hunterName;
}

bool TreasureHunter::isEncountered() {
	return encountered;
}

// setters
void TreasureHunter::setHunterType(TreasureHunterType type) {
	hunterType = type;
}

void TreasureHunter::setHunterName(string name) {
	hunterName = name;
}

void TreasureHunter::setLocation(Location* location) {
	this->location = location;
}

void TreasureHunter::setIsEncountered(bool encountered) {
	this->encountered = encountered;
}