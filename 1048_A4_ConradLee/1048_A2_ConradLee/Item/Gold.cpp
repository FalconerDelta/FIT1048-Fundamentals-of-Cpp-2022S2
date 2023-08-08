/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Gold Class File
 **************************************************/

#include "Gold.h"

Gold::Gold() : Item() {
	setItemObject(ItemObject::Gold);
	setItemType(ItemType::Item);
	setItemUses(Helper::genValue(6, 12));
	setItemName("Gold");
	setItemDescription("6-12 golds when found");
	setIsPotion(false);
	setIsDroppable(true);
}

Gold::~Gold() {}