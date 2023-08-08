/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Map Class HEADER File
 **************************************************/
#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "../Item.h"
using namespace std;

class Map : public Item {
public:
	Map();
	~Map();
};

#endif