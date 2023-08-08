/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Ninja Class File
 **************************************************/
#include "Ninja.h"
#include "../Player.h"

 // Constructor
Ninja::Ninja() : TreasureHunter() {
	setHunterType(TreasureHunterType::Ninja);
	setHunterName("Ninja");
}

// Destructor
Ninja::~Ninja() {}

// Interaction with Ninja
void Ninja::encounter(Player* player) {
	cout << "You encountered a ninja on a new turn!" << endl;
	// Some chance to evade the attack from the ninja, depending on the player's luck stat
	int dodgeChance = 20 + ((int)player->getPlayerLuck() / 5) * 10;
	if (Helper::genValue(1, 100) <= dodgeChance) {
		cout << "The ninja attempts to assassinate you, but you dodged it, how lucky!" << endl;
	}
	else {
		switch (Helper::genValue(1, 3)) {
		case 1: 
		{
			// Decrease player's lantern oil uses
			cout << "Attacking with a kunai, some oil leaked out from your lantern!" << endl;
			int originalOil = player->getItemUses(ItemObject::Lantern);
			player->updateItemUses(ItemObject::Lantern, -Helper::genValue(10, 30));
			cout << "Lantern oil decreased by " << originalOil - player->getItemUses(ItemObject::Lantern) << "!" << endl;
			break;
		}
		case 2:
		{
			// Deal damage to the player
			cout << "The ninja slashed you once with a samurai and then disappeared!" << endl;
			int originalHp = player->getPlayerHp();
			player->updatePlayerHp(-Helper::genValue(5, 10));
			cout << "Health decreased by " << originalHp - player->getPlayerHp() << "!" << endl;
			break;
		}
		case 3:
		{
			// Remove random equipment from the player, if has any
			cout << "The ninja sneaked behind you and stole one of your equipment!" << endl;
			vector<int> indices;
			vector<Item*> inventory = player->getPlayerInventory();
			for (int i = 0; i < inventory.size(); i++) {
				indices.push_back(i);
			}
			random_shuffle(indices.begin(), indices.end());
			bool isStolen = false;
			for (int index : indices) {
				Item* item = inventory[index];
				if (item->getItemType() == ItemType::Weapon || item->getItemType() == ItemType::Armour) {
					cout << "One of your " << item->getItemName() << "was stolen!" << endl;
					player->updateItemUses(item->getItemObject(), -1);
					isStolen = true;
					break;
				}
			}
			if (!isStolen) {
				cout << "Luckily you do not have any equipments on your inventory." << endl;
			}
			break;
		}
		}
	}
}