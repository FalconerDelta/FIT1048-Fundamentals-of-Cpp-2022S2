/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Chainmail Class File
 **************************************************/

#include "Chainmail.h"
#include "../Player.h"

Chainmail::Chainmail() : Item() {
	setItemObject(ItemObject::Chainmail);
	setItemType(ItemType::Artefact);
	setItemUses(1);
	setItemName("Krang¡¦s Chainmail");
	setItemDescription("+12 defence");
	setIsPotion(false);
	setIsDroppable(false);
}

Chainmail::~Chainmail() {}

// Pickup action
void Chainmail::onPickup(Player* player) {
	player->updatePlayerDef(12);
	cout << "Your defence is increased by 12!" << endl;
}