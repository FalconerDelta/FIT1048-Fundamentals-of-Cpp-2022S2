/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Tome Class HEADER File
 **************************************************/
#ifndef TOME_H
#define TOME_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Tome : public Item {
public:
	Tome();
	~Tome();
};

#endif