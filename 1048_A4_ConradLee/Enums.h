/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Enum HEADER File
 **************************************************/
#ifndef ENUMS_H
#define ENUMS_H

enum class ItemObject {
	Map,
	Lantern,
	Provisions,
	Gems,
	Gold,
	Sword,
	Armour,
	Potion,
	Axe,
	Chainmail,
	Boots,
	Elixir,
	Tome,
	Gloves,
	Necklace
};

enum class ItemType {
	Item,
	Weapon,
	Armour,
	Potion,
	Artefact
};

enum class MonsterType {
	Goblin,
	Hobgoblin,
	Ogre,
	Troll,
	Dragon

};

enum class TreasureHunterType {
	Gossiper,
	Merchant,
	Ninja
};

enum class SkillLevel {
	Rookie,
	Adventurer,
	MasterAdventurer
};

#endif