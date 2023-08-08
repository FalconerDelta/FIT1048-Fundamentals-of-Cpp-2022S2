/**************************************************
  Project: The Treasure Caverns of Doom A2
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

using namespace std;

class Player {

private:
	// player variables
	string playerName;
	int playerHp;
	int playerAtk;
	int playerDef;
	int playerDmg;
	int playerLuck;
	vector<Item> inventory;

	// Helper
	int genValue(int min, int max);

public:
	// constructor
	Player();
	Player(string playerName, Items item);
	~Player();

	// accessor methods
	string getPlayerName();
	int getPlayerHp();
	int getPlayerAtk();
	int getPlayerDef();
	int getPlayerDmg();
	int getPlayerLuck();
	string displayInventory();

	string getDetails();


	// mutator methods
	void setPlayerName(string name);
	void setPlayerHp(int hp);
	void setPlayerAtk(int atk);
	void setPlayerDef(int def);
	void setPlayerDmg(int dmg);
	void setPlayerLuck(int luck);

	void updatePlayerHp(int hp);
	void updatePlayerAtk(int atk);
	void updatePlayerDef(int def);
	void updatePlayerDmg(int dmg);
	void updatePlayerLuck(int luck);
	void addItemToInventory(Items item);
	void deleteItemFromInventory(string newItem, bool removeItem);
};


#endif