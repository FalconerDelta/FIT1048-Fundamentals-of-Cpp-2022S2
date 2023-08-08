/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Gold Class HEADER File
 **************************************************/
#ifndef GOLD_H
#define GOLD_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Gold : public Item {
public:
	Gold();
	~Gold();
};

#endif