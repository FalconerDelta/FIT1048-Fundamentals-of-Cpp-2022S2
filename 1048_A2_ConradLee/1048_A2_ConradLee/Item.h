/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Item Class HEADER File
 **************************************************/
#ifndef ITEM_H
#define ITEM_H
 // includes and name space
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "Enums.h"


using namespace std;

class Item {

private:
	// item variables
	Items itemName;
	ItemTypes itemType;
	int itemUses;
	string itemDescription;

	// Helper
	int genValue(int min, int max);

public:
	// constructor
	Item();
	Item(Items itemName);
	~Item();

	// accessor methods
	string getItemName();
	string getItemType();
	int getItemUses();
	string getItemDescription();
	string getDetails();

	// mutator methods
	void setItemName(Items newItemName);
	void setItemType(ItemTypes type);
	void setItemUses(int uses);
	void setItemDesciprtion(string info);
	void updateItemUses(int uses);
};

#endif