/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Chainmail Class HEADER File
 **************************************************/
#ifndef CHAINMAIL_H
#define CHAINMAIL_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Chainmail : public Item {
public:
	Chainmail();
	~Chainmail();
	void onPickup(Player* player) override;
};

#endif