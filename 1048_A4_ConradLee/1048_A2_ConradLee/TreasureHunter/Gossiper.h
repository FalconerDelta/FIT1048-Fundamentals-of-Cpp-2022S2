/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Gossiper Class HEADER File
 **************************************************/
#ifndef GOSSIPER_H
#define GOSSIPER_H
#include "../TreasureHunter.h"

using namespace std;

class Gossiper : public TreasureHunter {
private:
	vector<string> gossips = {	"Do you know that all of the artefacts are located in the inner ring of the cavern?",
								"When you have collected 1 of 5 artefacts, a hunter will arrive for assistance!", 
								"When you have collected 3 of 5 artefacts, a hunter will arrive to sabotage your plan!"};
	bool moneyGiven = false;

public:
	// constructor
	Gossiper();
	~Gossiper();
	void encounter(Player* player) override;
};

#endif