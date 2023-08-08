/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Lantern Class File
 **************************************************/

#include "Lantern.h"

Lantern::Lantern() : Item() {
	setItemObject(ItemObject::Lantern);
	setItemType(ItemType::Item);
	setItemUses(500);
	setItemName("Lantern");
	setItemDescription("Lights way losing 2-5 points with each move or search action.");
	setIsDroppable(false);
}

Lantern::~Lantern() {}