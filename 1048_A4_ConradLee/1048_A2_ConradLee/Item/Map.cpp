/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Map Class File
 **************************************************/

#include "Map.h"

Map::Map(): Item() {
	setItemObject(ItemObject::Map);
	setItemType(ItemType::Item);
	setItemUses(1);
	setItemName("Map");
	setItemDescription("This is a map");
	setIsDroppable(false);
}

Map::~Map() {}