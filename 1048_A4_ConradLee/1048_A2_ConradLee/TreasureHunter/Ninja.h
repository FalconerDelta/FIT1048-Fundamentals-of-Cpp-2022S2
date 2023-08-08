/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Ninja Class HEADER File
 **************************************************/
#ifndef NINJA_H
#define NINJA_H
#include "../TreasureHunter.h"

using namespace std;

class Ninja : public TreasureHunter {
public:
	// constructor
	Ninja();
	~Ninja();
	void encounter(Player* player) override;
};

#endif