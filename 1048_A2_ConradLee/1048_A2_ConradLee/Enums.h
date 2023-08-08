/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Enum HEADER File
 **************************************************/
#ifndef ENUMS_H
#define ENUMS_H

enum class Items {
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
	Tome
};

enum class ItemTypes {
	Item,
	Weapon,
	Armour,
	Potion,
	Artefact
};

enum Monsters {
	Goblin = 1,
	Hobgoblin,
	Ogre,
	Troll,
	Dragon

};

#endif