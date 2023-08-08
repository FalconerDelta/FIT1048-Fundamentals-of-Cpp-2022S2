/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Lantern Class HEADER File
 **************************************************/
#ifndef LANTERN_H
#define LANTERN_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Lantern : public Item {
public:
	Lantern();
	~Lantern();
};

#endif