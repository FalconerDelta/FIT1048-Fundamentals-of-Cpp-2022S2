/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Monster Class File
 **************************************************/
#include "Monster.h"
#include "Dragon.h"

// Constructor
Monster::Monster(MonsterType newMonster) {
	setMonsterName(newMonster);
	setMonsterType(newMonster);
	switch (monsterType) {
	case MonsterType::Goblin:
		setMonsterLevel(1);
		setMonsterMaxHp(monsterLevel * Helper::genValue(2, 3));
		setMonsterHp(getMonsterMaxHp());
		setMonsterAtk(monsterLevel + Helper::genValue(1, 3));
		setMonsterDef(monsterLevel + Helper::genValue(1, 2));
		setMonsterDmg(monsterLevel);
		rollForMonsterItem(40);
		break;
	case MonsterType::Hobgoblin:
		setMonsterLevel(2);
		setMonsterMaxHp(monsterLevel * Helper::genValue(3, 5));
		setMonsterHp(getMonsterMaxHp());
		setMonsterAtk(monsterLevel + Helper::genValue(2, 4));
		setMonsterDef(monsterLevel + Helper::genValue(1, 3));
		setMonsterDmg(monsterLevel + Helper::genValue(1, 2));
		rollForMonsterItem(50);
		break;
	case MonsterType::Ogre:
		setMonsterLevel(3);
		setMonsterMaxHp(monsterLevel * Helper::genValue(4, 6));
		setMonsterHp(getMonsterMaxHp());
		setMonsterAtk(monsterLevel + Helper::genValue(3, 5));
		setMonsterDef(monsterLevel + Helper::genValue(2, 4));
		setMonsterDmg(monsterLevel + Helper::genValue(1, 3));
		break;
	case MonsterType::Troll:
		setMonsterLevel(4);
		setMonsterMaxHp(monsterLevel * Helper::genValue(5, 7));
		setMonsterHp(getMonsterMaxHp());
		setMonsterAtk(monsterLevel + Helper::genValue(4, 7));
		setMonsterDef(monsterLevel + Helper::genValue(2, 5));
		setMonsterDmg(monsterLevel + Helper::genValue(2, 4));
		break;
	case MonsterType::Dragon:
		setMonsterLevel(5);
		setMonsterMaxHp(monsterLevel * Helper::genValue(6, 8));
		setMonsterHp(getMonsterMaxHp());
		setMonsterAtk(monsterLevel + Helper::genValue(6, 10));
		setMonsterDef(monsterLevel + Helper::genValue(6, 12));
		setMonsterDmg(monsterLevel + Helper::genValue(4, 6));
		break;
	}
}

void Monster::rollForMonsterItem(int percentage) {
	int value = Helper::genValue(1, 100);
	if (value <= percentage) {
		setMonsterItem(Item::genRandomItem());
	}
}

// Destructor
Monster::~Monster(){}

// accessor methods
Monster* Monster::initNewMonster(MonsterType monsterType) {
	switch (monsterType) {
	case MonsterType::Dragon:
		return new Dragon();
		break;
	default:
		return new Monster(monsterType);
	}
}

string Monster::getMonsterName() {
	return monsterName;
}

MonsterType Monster::getMonsterType() {
	return monsterType;
}

int Monster::getMonsterLevel() {
	return monsterLevel;
}

int Monster::getMonsterMaxHp() {
	return monsterMaxHp;
}

int Monster::getMonsterHp() {
	return monsterHp;
}

int Monster::getMonsterAtk() {
	return monsterAtk;
}

int Monster::getMonsterDef() {
	return monsterDef;
}

int Monster::getMonsterDmg() {
		return monsterDmg;
}

Item* Monster::getMonsterItem() {
	return holdingItem;
}

bool Monster::isHasItem() {
	return hasItem;
}

string Monster::getDetails() {
	// returns a formatted string
	stringstream monsterDetails;
	monsterDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	monsterDetails << "\n Monster Name       : " << getMonsterName();
	monsterDetails << "\n Monster Level      : " << getMonsterLevel();
	monsterDetails << "\n Monster Health     : " << getMonsterMaxHp();
	monsterDetails << "\n Monster Attack     : " << getMonsterAtk();
	monsterDetails << "\n Monster Defence    : " << getMonsterDef();
	monsterDetails << "\n Monster Damage     : " << getMonsterDmg();
	if (hasItem) {
		monsterDetails << "\n Monster Item       : " << getMonsterItem()->getItemName();
	}
	monsterDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return monsterDetails.str();
}


// mutator methods
void Monster::setMonsterName(MonsterType type) {
	switch (type) {
	case MonsterType::Dragon:
		monsterName = "Dragon";
		break;
	case MonsterType::Goblin:
		monsterName = "Goblin";
		break;
	case MonsterType::Hobgoblin:
		monsterName = "Hobgoblin";
		break;
	case MonsterType::Ogre:
		monsterName = "Ogre";
		break;
	case MonsterType::Troll:
		monsterName = "Troll";
		break;
	}
}

void Monster::setMonsterType(MonsterType type) {
	monsterType = type;
}

void Monster::setMonsterLevel(int level) {
	if (0 < level && level < 6) {
		monsterLevel = level;
	}
}

void Monster::setMonsterMaxHp(int maxHp) {
	if (maxHp > 0) {
		monsterMaxHp = maxHp;
	}
}

void Monster::setMonsterHp(int hp) {
	if (hp > 0) {
		monsterHp = hp;
	}
}

void Monster::setMonsterAtk(int atk) {
	if (atk >= 0) {
		monsterAtk = atk;
	}
}

void Monster::setMonsterDef(int def) {
	if (def >= 0) {
		monsterDef = def;
	}
}

void Monster::setMonsterDmg(int dmg) {
	if (dmg >=0) {
		monsterDmg = dmg;
	}
}

void Monster::setMonsterItem(Item* newItem) {
	holdingItem = newItem;
	hasItem = true;
}


void Monster::updateMonsterHp(int hp) {
	monsterHp = min(monsterHp + hp, monsterMaxHp);
	if (monsterHp < 0) {
		monsterHp = 0;
	}
}
