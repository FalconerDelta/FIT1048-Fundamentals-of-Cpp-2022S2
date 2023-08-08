/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Gloves Class File
 **************************************************/

#include "Gloves.h"
#include "../Player.h"

Gloves::Gloves() : Item() {
	setItemObject(ItemObject::Gloves);
	setItemType(ItemType::Armour);
	setItemUses(1);
	setItemName("Leather Gloves");
	setItemDescription("+2 attack");
	setIsPotion(false);
	setIsDroppable(true);
}

Gloves::~Gloves() {}

// Pickup action
void Gloves::onPickup(Player* player) {
	player->updatePlayerAtk(2);
	cout << "Your attack is increased by 2!" << endl;
}

// Drop action
void Gloves::onDrop(Player* player, int quantity) {
	int value = 2 * quantity;
	player->updatePlayerAtk(-value);
	cout << "Your attack is decreased by " << value << "!" << endl;
}