/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Elixir Class File
 **************************************************/

#include "Elixir.h"
#include "../Player.h"

Elixir::Elixir() : Item() {
	setItemObject(ItemObject::Elixir);
	setItemType(ItemType::Artefact);
	setItemUses(1);
	setItemName("Elixir Maxima");
	setItemDescription("I wonder what will happen if I drink this?");
	setIsPotion(true);
	setIsDroppable(false);
}

Elixir::~Elixir() {}

// RIP player
void Elixir::onUse(Player* player) {
	player->updatePlayerHp(-999999);
	cout << "Unable to endure the power of the elixir, you are dead!" << endl;
}