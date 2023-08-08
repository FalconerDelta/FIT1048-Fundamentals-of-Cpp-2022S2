/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Sword Class File
 **************************************************/

#include "Sword.h"
#include "../Player.h"

Sword::Sword() : Item() {
	setItemObject(ItemObject::Sword);
	setItemType(ItemType::Weapon);
	setItemUses(1);
	setItemName("Sword");
	setItemDescription("+2 damage");
	setIsPotion(false);
	setIsDroppable(true);
}

Sword::~Sword() {}

// Pickup action
void Sword::onPickup(Player* player) {
	player->updatePlayerDmg(2);
	cout << "Your damage is increased by 2!" << endl;
}

// Drop action
void Sword::onDrop(Player* player, int quantity) {
	int value = 2 * quantity;
	player->updatePlayerDmg(-value);
	cout << "Your damage is decreased by " <<  value << "!" << endl;
}