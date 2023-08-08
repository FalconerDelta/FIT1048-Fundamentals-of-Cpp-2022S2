/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Monster Class HEADER File
 **************************************************/
#ifndef MONSTER_H
#define MONSTER_H
 // includes and name space
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "Enums.h"
#include "Item.h"

using namespace std;

class Monster {

private:
	// item variables
	Monsters monsterName;
	int monsterLevel;
	int monsterHp;
	int monsterAtk;
	int monsterDef;
	int monsterDmg;
	int carryingChance;
	string holdingItem;

	// Helper
	string genItem(int chance, int typeRangeMin, int typeRangeMax);

public:
	// constructor
	Monster();
	Monster(Monsters newMonster);
	~Monster();

	// accessor methods
	string getMonsterName();
	int getMonsterLevel();
	int getMonsterHp();
	int getMonsterAtk();
	int getMonsterDef();
	int getMonsterDmg();
	int getMonsterCarryingChance();
	string getMonsterItem();

	string getDetails();

	// mutator methods
	void setMonsterName(Monsters newName);
	void setMonsterLevel(int level);
	void setMonsterHp(int hp);
	void setMonsterAtk(int atk);
	void setMonsterDef(int def);
	void setMonsterDmg(int dmg);
	void setMonsterCarryingChance(int chance);
	void setMonsterItem(string newItem);

	void updateMonsterHp(int hp);

	// helper
	int genValue(int min, int max);
};

#endif