/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Elixir Class HEADER File
 **************************************************/
#ifndef ELIXIR_H
#define ELIXIR_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Elixir : public Item {
public:
	Elixir();
	~Elixir();
	void onUse(Player* player) override;
};

#endif