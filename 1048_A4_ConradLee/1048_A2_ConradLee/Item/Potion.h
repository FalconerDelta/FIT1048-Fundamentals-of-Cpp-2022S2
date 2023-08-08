/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Potion Class HEADER File
 **************************************************/
#ifndef POTION_H
#define POTION_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Potion : public Item {
public:
	Potion();
	~Potion();
	void onUse(Player* player) override;
};

#endif