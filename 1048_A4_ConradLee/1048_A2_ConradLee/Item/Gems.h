/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Gems Class HEADER File
 **************************************************/
#ifndef GEMS_H
#define GEMS_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Gems : public Item {
public:
	Gems();
	~Gems();
};

#endif