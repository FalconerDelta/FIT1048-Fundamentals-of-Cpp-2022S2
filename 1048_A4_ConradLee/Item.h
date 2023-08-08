/**************************************************
  Project: The Treasure Caverns of Doom
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
#include "Helper.h"

using namespace std;
class Player;

class Item {

private:
	static constexpr ItemObject generatableItems[6] = {ItemObject::Armour, ItemObject::Provisions, ItemObject::Potion, ItemObject::Sword, ItemObject::Gloves, ItemObject::Necklace};
	// item variables
	ItemObject itemObject;
	ItemType itemType;
	string itemName;
	int itemUses;
	string itemDescription;
	bool potion = false;
	bool droppable = false;

public:
	// constructor
	Item();
	~Item();

	void useItem();

	static Item* initNewItem(ItemObject itemName);
	static Item* genRandomItem();
	static Item* genRandomItemExcludingGemsAndGold();
	static Item* genGemsOrGold();

	// accessor methods
	string getItemName();
	ItemObject getItemObject();
	ItemType getItemType();
	string getItemTypeString();
	int getItemUses();
	string getItemDescription();
	string getDetails();
	bool isPotion();
	bool isDroppable();

	// mutator methods
	void setItemName(string itemName);
	void setItemObject(ItemObject itemObject);
	void setItemType(ItemType itemType);
	void setItemUses(int itemUses);
	void updateItemUses(int uses);
	void dropItemUses(Player* player, int uses);
	void setItemDescription(string itemDescription);
	void setIsPotion(bool isPotion);
	void setIsDroppable(bool isDroppable);

	// Overridable functions for the derived item classes to use
	virtual void onPickup(Player* player) {};
	virtual void onUse(Player* player) {};
	virtual void onDrop(Player* player, int quantity) {};
};

#endif