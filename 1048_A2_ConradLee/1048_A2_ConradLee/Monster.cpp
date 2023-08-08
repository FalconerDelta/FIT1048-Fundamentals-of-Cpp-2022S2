/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Monster Class File
 **************************************************/
#include "Monster.h"

//Items are generated randomly based on the drop rate

// Constructor
// number and item generator at the very bottom
Monster::Monster() {
	Monsters monsterName = Monsters::Goblin;
	monsterLevel = static_cast<int>(monsterName);
	monsterHp = monsterLevel * genValue(2,3);
	monsterAtk = monsterLevel + genValue(1,3);
	monsterDef = monsterLevel + genValue(1,2);
	monsterDmg = monsterLevel;
	carryingChance = 40;
	holdingItem = genItem(carryingChance,1,7);
}

// Overloaded constructor
Monster::Monster(Monsters newMonster) {
	setMonsterName(newMonster);
	switch (monsterName) {
	case Monsters::Goblin:
		setMonsterLevel(static_cast<int>(monsterName));
		setMonsterHp(monsterLevel * genValue(2, 3));
		setMonsterAtk(monsterLevel + genValue(1, 3));
		setMonsterDef(monsterLevel + genValue(1, 2));
		setMonsterDmg(monsterLevel);
		setMonsterCarryingChance(40);
		setMonsterItem(genItem(carryingChance, 1, 7));
		break;
	case Monsters::Hobgoblin:
		setMonsterLevel(static_cast<int>(monsterName));
		setMonsterHp(monsterLevel * genValue(3, 5));
		setMonsterAtk(monsterLevel + genValue(2, 4));
		setMonsterDef(monsterLevel + genValue(1, 3));
		setMonsterDmg(monsterLevel + genValue(1, 2));
		setMonsterCarryingChance(50);
		setMonsterItem(genItem(carryingChance, 1, 7));
		break;
	case Monsters::Ogre:
		setMonsterLevel(static_cast<int>(monsterName));
		setMonsterHp(monsterLevel * genValue(4, 6));
		setMonsterAtk(monsterLevel + genValue(3, 5));
		setMonsterDef(monsterLevel + genValue(2, 4));
		setMonsterDmg(monsterLevel + genValue(1, 3));
		setMonsterCarryingChance(60);
		setMonsterItem(genItem(carryingChance, 8, 12));
		break;
	case Monsters::Troll:
		setMonsterLevel(static_cast<int>(monsterName));
		setMonsterHp(monsterLevel * genValue(5, 7));
		setMonsterAtk(monsterLevel + genValue(4, 7));
		setMonsterDef(monsterLevel + genValue(2, 5));
		setMonsterDmg(monsterLevel + genValue(2, 4));
		setMonsterCarryingChance(70);
		setMonsterItem(genItem(carryingChance, 8, 12));
		break;
	case Monsters::Dragon:
		setMonsterLevel(static_cast<int>(monsterName));
		setMonsterHp(monsterLevel * genValue(6, 8));
		setMonsterAtk(monsterLevel + genValue(6, 10));
		setMonsterDef(monsterLevel + genValue(6, 12));
		setMonsterDmg(monsterLevel + genValue(4, 6));
		setMonsterCarryingChance(100);
		setMonsterItem(genItem(carryingChance, 8, 12));
		break;
	}
}

// Destructor
Monster::~Monster(){}

// accessor methods
string Monster::getMonsterName() {
	switch (monsterName) {
	case Monsters::Goblin:
		return "Goblin";
	case Monsters::Hobgoblin:
		return "Hobgoblin";
	case Monsters::Ogre:
		return "Ogre";
	case Monsters::Troll:
		return "Troll";
	case Monsters::Dragon:
		return "Dragon";
	default:
		return "Error in getMonsterName()";
	}
}

int Monster::getMonsterLevel() {
	return static_cast<int>(monsterName);
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

int Monster::getMonsterCarryingChance() {
	return carryingChance;
}

string Monster::getMonsterItem() {
	return holdingItem;
}


string Monster::getDetails() {
	// returns a formatted string
	stringstream monsterDetails;
	monsterDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	monsterDetails << "\n Monster Name       : " << getMonsterName();
	monsterDetails << "\n Monster Level      : " << getMonsterLevel();
	monsterDetails << "\n Monster Health     : " << getMonsterHp();
	monsterDetails << "\n Monster Attack     : " << getMonsterAtk();
	monsterDetails << "\n Monster Defence    : " << getMonsterDef();
	monsterDetails << "\n Monster Damage     : " << getMonsterDmg();
	monsterDetails << "\n Monster Loot Chance: " << getMonsterCarryingChance();
	monsterDetails << "\n Monster Item       : " << getMonsterItem();
	monsterDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return monsterDetails.str();
}


// mutator methods
void Monster::setMonsterName(Monsters newName) {
	if (newName >= Monsters::Goblin && newName <= Monsters::Dragon) {
	monsterName = newName;
	}
}

void Monster::setMonsterLevel(int level) {
	if (0 < level && level < 6) {
		monsterLevel = level;
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

void Monster::setMonsterCarryingChance(int chance) {
	if (chance >=0 && chance <= 100) {
		carryingChance = chance;
	}
}

void Monster::setMonsterItem(string newItem) {
	if (newItem != "") {
		holdingItem = newItem;
	}
}


void Monster::updateMonsterHp(int hp) {
	if (monsterHp + hp >= 0) {
		monsterHp += hp;
	}
	else {
		monsterHp = 0;
	}
}



// Generate number with given range
int Monster::genValue(int min, int max) {
	return (rand() % (max - min + 1) + min);
}

// Generate random item based on drop rate
string Monster::genItem(int chance, int typeRangeMin, int typeRangeMax) {
	int result = rand() % 100;
	if (result < chance) {
		Items temp = static_cast<Items>(genValue(typeRangeMin, typeRangeMax));
		switch (temp) {
		case Items::Map:
			return "Map";
		case Items::Lantern:
			return "Lantern";
		case Items::Provisions:
			return "Provisions";
		case Items::Gems:
			return "Gems";
		case Items::Gold:
			return "Gold";
		case Items::Sword:
			return "Sword";
		case Items::Armour:
			return "Leather Armour";
		case Items::Potion:
			return "Potion Flask";
		case Items::Axe:
			return "Krang's Battle Axe";
		case Items::Chainmail:
			return "Krang's Chainmail";
		case Items::Boots:
			return "Boots of Speed";
		case Items::Elixir:
			return "Elixir Maxima";
		case Items::Tome:
			return "Balthazar's Spell Tome";
		default:
			return "Nothing";
		}
	}
	else {
		return "Nothing";
	}
}
