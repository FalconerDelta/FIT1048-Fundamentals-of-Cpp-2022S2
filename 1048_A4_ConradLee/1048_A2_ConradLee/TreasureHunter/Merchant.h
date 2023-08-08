/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Merchant Class HEADER File
 **************************************************/
#ifndef MERCHANT_H
#define MERCHANT_H
#include "../TreasureHunter.h"

using namespace std;

class Merchant : public TreasureHunter {
private:
	int armourPrice = 15;
	int swordPrice = 15;
	int glovesPrice = 20;
	int necklacePrice = 10;
	int lanternPrice = 50;
	void increasePrices();
public:
	// constructor
	Merchant();
	~Merchant();
	void encounter(Player* player) override;
};

#endif