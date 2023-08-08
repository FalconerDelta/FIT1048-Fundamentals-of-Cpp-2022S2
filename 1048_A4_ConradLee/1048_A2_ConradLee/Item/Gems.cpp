/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Gems Class File
 **************************************************/

#include "Gems.h"

Gems::Gems() : Item() {
	setItemObject(ItemObject::Gems);
	setItemType(ItemType::Item);
	setItemUses(Helper::genValue(1, 3));
	setItemName("Gems");
	setItemDescription("1-3 gems when found");
	setIsPotion(false);
	setIsDroppable(true);
}

Gems::~Gems() {}