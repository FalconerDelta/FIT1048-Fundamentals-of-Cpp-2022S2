/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Player Class HEADER File
 **************************************************/
#ifndef PLAYER_H
#define PLAYER_H
 // includes and name space
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Enums.h"
#include "Item.h"
#include "Helper.h"

using namespace std;

class Player {

private:
	static constexpr ItemObject artefactsRequiredToFightDragon[3] = { ItemObject::Axe, ItemObject::Boots, ItemObject::Chainmail };
	string playerName;
	int playerMaxHp;
	int playerHp;
	int playerAtk;
	int playerDef;
	int playerDmg;
	int playerLuck;
	vector<Item*> inventory;
	void initPlayer();
	bool collectedAllArtefacts = false;
	int inventoryCapacity = 12;
	int getUsedCapacity();

public:
	Player(string playerName = "");
	~Player();

	string getPlayerName();
	int getPlayerMaxHp();
	int getPlayerHp();
	int getPlayerAtk();
	int getPlayerDef();
	int getPlayerDmg();
	int getPlayerLuck();
	string displayInventory();
	string getDetails();
	int findItemIndex(ItemObject itemObject);
	bool isCollectedAllArtefacts();
	vector<Item*> getPlayerInventory();
	bool canFightDragon();
	int getItemUses(ItemObject itemObject);


	// mutator methods
	void setPlayerName(string name);
	void setPlayerMaxHp(int maxHp);
	void setPlayerHp(int hp);
	void setPlayerAtk(int atk);
	void setPlayerDef(int def);
	void setPlayerDmg(int dmg);
	void setPlayerLuck(int luck);
	void setInventoryCapacity(int capacity);

	void updatePlayerMaxHp(int maxHp);
	void updatePlayerHp(int hp);
	void updatePlayerAtk(int atk);
	void updatePlayerDef(int def);
	void updatePlayerDmg(int dmg);
	void updatePlayerLuck(int luck);
	bool addItemToInventory(Item* item);
	void deleteItemFromInventory(Item* item);
	void updateItemUses(ItemObject itemObject, int uses);
	void setItemUses(ItemObject itemObject, int uses);
};


#endif