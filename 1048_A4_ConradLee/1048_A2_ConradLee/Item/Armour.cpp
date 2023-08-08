/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Armour Class File
 **************************************************/

#include "Armour.h"
#include "../Player.h"

Armour::Armour() : Item() {
	setItemObject(ItemObject::Armour);
	setItemType(ItemType::Armour);
	setItemUses(1);
	setItemName("Leather Armour");
	setItemDescription("+4 defence");
	setIsPotion(false);
	setIsDroppable(true);
}

Armour::~Armour() {}

// Pickup action
void Armour::onPickup(Player* player) {
	player->updatePlayerDef(4);
	cout << "Your defence is increased by 4!" << endl;
}

// Drop action
void Armour::onDrop(Player* player, int quantity) {
	int value = 4 * quantity;
	player->updatePlayerDef(-value);
	cout << "Your defence is decreased by " << value << "!" << endl;
}