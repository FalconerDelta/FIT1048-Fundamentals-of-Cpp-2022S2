/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Dragon Class File
 **************************************************/
#include "Dragon.h"

// Constructor
Dragon::Dragon(): Monster(MonsterType::Dragon) {
	setMonsterItem(Item::initNewItem(ItemObject::Tome));
	specialSkillUsed = false;
}

// Destructor
Dragon::~Dragon() {}

int Dragon::getMonsterDmg() {
	// Once the dragon has only half of the hp left, use the one time skill
	if (getMonsterMaxHp() / 2 > getMonsterHp() && !specialSkillUsed) {
		cout << "Being severely injured, the dragon unleased a powerful fire attack!" << endl;
		specialSkillUsed = true;
		return getMonsterLevel() * Helper::genValue(2, 3);
	}
	else return Monster::getMonsterDmg();
}