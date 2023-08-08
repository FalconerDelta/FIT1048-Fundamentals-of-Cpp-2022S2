/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Necklace Class File
 **************************************************/

#include "Necklace.h"
#include "../Player.h"

Necklace::Necklace() : Item() {
	setItemObject(ItemObject::Necklace);
	setItemType(ItemType::Armour);
	setItemUses(1);
	setItemName("Necklace");
	setItemDescription("+2 luck");
	setIsPotion(false);
	setIsDroppable(true);
}

Necklace::~Necklace() {}

// Pickup action
void Necklace::onPickup(Player* player) {
	player->updatePlayerLuck(2);
	cout << "Your luck is increased by 2!" << endl;
}

// Drop Action
void Necklace::onDrop(Player* player, int quantity) {
	int value = 2 * quantity;
	player->updatePlayerLuck(-value);
	cout << "Your luck is decreased by " << value << "!" << endl;
}