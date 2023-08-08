/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Axe Class File
 **************************************************/

#include "Axe.h"
#include "../Player.h"

Axe::Axe() : Item() {
	setItemObject(ItemObject::Axe);
	setItemType(ItemType::Artefact);
	setItemUses(1);
	setItemName("Krang¡¦s Battle Axe");
	setItemDescription("+8 damage");
	setIsPotion(false);
	setIsDroppable(false);
}

Axe::~Axe() {}

// Pickup action
void Axe::onPickup(Player* player) {
	player->updatePlayerDmg(8);
	cout << "Your damage is increased by 8!" << endl;
}