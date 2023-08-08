/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Armour Class HEADER File
 **************************************************/
#ifndef ARMOUR_H
#define ARMOUR_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Armour : public Item {
public:
	Armour();
	~Armour();
	void onPickup(Player* player) override;
	void onDrop(Player* player, int quantity) override;
};

#endif