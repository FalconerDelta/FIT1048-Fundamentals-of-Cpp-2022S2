/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Gloves Class HEADER File
 **************************************************/
#ifndef GLOVES_H
#define GLOVES_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Gloves : public Item {
public:
	Gloves();
	~Gloves();
	void onPickup(Player* player) override;
	void onDrop(Player* player, int quantity) override;
};

#endif