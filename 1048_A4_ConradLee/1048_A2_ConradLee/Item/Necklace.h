/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Necklace Class HEADER File
 **************************************************/
#ifndef NECKLACE_H
#define NECKLACE_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Necklace : public Item {
public:
	Necklace();
	~Necklace();
	void onPickup(Player* player) override;
	void onDrop(Player* player, int quantity) override;
};

#endif