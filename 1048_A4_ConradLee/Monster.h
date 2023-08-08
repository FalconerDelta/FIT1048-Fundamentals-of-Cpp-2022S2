/**************************************************
  Project: The Treasure Caverns of Doom
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
#include "Helper.h"

using namespace std;

class Monster {

private:
	MonsterType monsterType;
	string monsterName;
	int monsterLevel;
	int monsterMaxHp;
	int monsterHp;
	int monsterAtk;
	int monsterDef;
	int monsterDmg;
	Item* holdingItem;
	bool hasItem = false;

	void rollForMonsterItem(int percentage);

public:
	// constructor
	Monster() : Monster(MonsterType::Goblin) {};
	Monster(MonsterType newMonster);
	~Monster();

	// accessor methods
	static Monster* initNewMonster(MonsterType monsterType);
	string getMonsterName();
	MonsterType getMonsterType();
	int getMonsterLevel();
	int getMonsterMaxHp();
	int getMonsterHp();
	int getMonsterAtk();
	int getMonsterDef();
	// Overrided by the dragon class
	virtual int getMonsterDmg();
	Item* getMonsterItem();
	bool isHasItem();
	string getDetails();

	// mutator methods
	void setMonsterName(MonsterType type);
	void setMonsterType(MonsterType type);
	void setMonsterLevel(int level);
	void setMonsterMaxHp(int maxHp);
	void setMonsterHp(int hp);
	void setMonsterAtk(int atk);
	void setMonsterDef(int def);
	void setMonsterDmg(int dmg);
	void setMonsterItem(Item* newItem);

	void updateMonsterHp(int hp);
};

#endif