/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Provisions Class File
 **************************************************/

#include "Provisions.h"
#include "../Player.h"

Provisions::Provisions() : Item() {
	setItemObject(ItemObject::Provisions);
	setItemType(ItemType::Item);
	setItemUses(Helper::genValue(2, 4));
	setItemName("Provisions");
	setItemDescription("restores 5-10 hp");
	setIsPotion(true);
	setIsDroppable(true);
}

Provisions::~Provisions() {}

// Heal with provisions
void Provisions::onUse(Player* player) {
	int originalHp = player->getPlayerHp();
	int value = Helper::genValue(5, 10);
	player->updatePlayerHp(value);
	cout << "Restored " << player->getPlayerHp() - originalHp << " health." << endl;
}