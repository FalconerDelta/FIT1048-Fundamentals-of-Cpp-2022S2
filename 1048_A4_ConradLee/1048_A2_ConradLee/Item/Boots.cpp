/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Boots Class File
 **************************************************/

#include "Boots.h"
#include "../Player.h"

Boots::Boots() : Item() {
	setItemObject(ItemObject::Boots);
	setItemType(ItemType::Artefact);
	setItemUses(1);
	setItemName("Boots of Speed");
	setItemDescription("+6 attack");
	setIsPotion(false);
	setIsDroppable(false);
}

Boots::~Boots() {}

// Pickup action
void Boots::onPickup(Player* player) {
	player->updatePlayerAtk(6);
	cout << "Your attack is increased by 6!" << endl;
}