/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Sword Class HEADER File
 **************************************************/
#ifndef SWORD_H
#define SWORD_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Sword : public Item {
public:
	Sword();
	~Sword();
	void onPickup(Player* player) override;
	void onDrop(Player* player, int quantity) override;
};

#endif