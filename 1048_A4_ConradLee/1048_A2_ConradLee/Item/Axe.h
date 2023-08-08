/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Axe Class HEADER File
 **************************************************/
#ifndef AXE_H
#define AXE_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Axe : public Item {
public:
	Axe();
	~Axe();
	void onPickup(Player* player) override;
};

#endif