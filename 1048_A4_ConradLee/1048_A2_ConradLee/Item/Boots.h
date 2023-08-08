/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Boots Class HEADER File
 **************************************************/
#ifndef BOOTS_H
#define BOOTS_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Boots : public Item {
public:
	Boots();
	~Boots();
	void onPickup(Player* player) override;
};

#endif