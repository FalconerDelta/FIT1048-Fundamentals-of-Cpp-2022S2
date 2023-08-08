/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Potion Class File
 **************************************************/

#include "Potion.h"
#include "../Player.h"

Potion::Potion() : Item() {
	setItemObject(ItemObject::Potion);
	setItemType(ItemType::Potion);
	setItemUses(Helper::genValue(1, 2));
	setItemName("Potion Flask");
	setItemDescription("+/- 2-4 to one attribute, with chances depending on your luck");
	setIsPotion(true);
	setIsDroppable(true);
}

Potion::~Potion() {}

// Update player status when used
void Potion::onUse(Player* player) {
	int attribute = Helper::genValue(1, 5);
	int value = Helper::genValue(2, 4);
	string sign = "increased";
	// The chance of decreasing stats is depending on the player's luck stat
	int decreaseChance = 60 - ((int)player->getPlayerLuck() / 5) * 10;
	if (Helper::genValue(1, 100) <= decreaseChance) {
		value = -value;
		sign = "decreased";
	}
	switch (attribute) {
	case 1:
		player->updatePlayerMaxHp(value);
		cout << "Your max health is " << sign << " by " << value << "!" <<endl;
		break;
	case 2:
		player->updatePlayerAtk(value);
		cout << "Your attack is " << sign << " by " << value << "!" << endl;
		break;
	case 3:
		player->updatePlayerDef(value);
		cout << "Your defence is " << sign << " by " << value << "!" << endl;
		break;
	case 4:
		player->updatePlayerDmg(value);
		cout << "Your damage is " << sign << " by " << value << "!" << endl;
		break;
	case 5:
		player->updatePlayerLuck(value);
		cout << "Your luck is " << sign << " by " << value << "!" << endl;
		break;
	}
}