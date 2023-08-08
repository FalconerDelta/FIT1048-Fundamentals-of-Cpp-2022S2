/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Tome Class File
 **************************************************/

#include "Tome.h"

Tome::Tome() : Item() {
	setItemObject(ItemObject::Tome);
	setItemType(ItemType::Artefact);
	setItemUses(1);
	setItemName("Balthazar¡¦s Spell Tome");
	setItemDescription("Carry it back to the entrance!");
	setIsPotion(false);
	setIsDroppable(false);
}

Tome::~Tome() {}