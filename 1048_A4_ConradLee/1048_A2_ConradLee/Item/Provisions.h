/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Provisions Class HEADER File
 **************************************************/
#ifndef PROVISIONS_H
#define PROVISIONS_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Provisions : public Item {
public:
	Provisions();
	~Provisions();
	void onUse(Player* player) override;
};

#endif