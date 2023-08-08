/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: TreasureHunter Class HEADER File
 **************************************************/
#ifndef TREASUREHUNTER_H
#define TREASUREHUNTER_H
#include "Enums.h"
#include "Helper.h"

using namespace std;
class Location;
class Player;

class TreasureHunter {
private:
	TreasureHunterType hunterType;
	string hunterName;
	Location* location;
	bool encountered = false;

public:
	// constructor
	TreasureHunter();
	~TreasureHunter();
	virtual void encounter(Player* player) {};
	Location* getLocation();
	string getHunterName();
	bool isEncountered();

	void setHunterType(TreasureHunterType type);
	void setHunterName(string name);
	void setLocation(Location* location);
	void setIsEncountered(bool encountered);
};

#endif