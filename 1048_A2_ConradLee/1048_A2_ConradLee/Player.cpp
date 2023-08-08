/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Player Class File
 **************************************************/
#include "Player.h"

 // constructor
 // see genValue() at the very bottom for generate random number within given range
Player::Player(){
	playerName = "The Tarnished"; //Just because Elden Ring is popular recently
	playerHp = genValue(4, 12) + 12;
	playerAtk = playerHp/6;
	playerDef = playerAtk/2;
	playerDmg = playerAtk + 0;
	playerLuck = genValue(2, 6) +6;
	inventory.push_back(Item::Item(Items::Map));
	inventory.push_back(Item::Item(Items::Lantern));
	inventory.push_back(Item::Item(Items::Provisions));
}

Player::Player(string newPlayerName, Items item) {
	playerName = newPlayerName;
	playerHp = genValue(4, 12) + 12;
	playerAtk = playerHp / 6;
	playerDef = playerAtk / 2;
	playerDmg = playerAtk + 0;
	playerLuck = genValue(2, 6) + 6;
	inventory.push_back(Item::Item(Items::Map));
	inventory.push_back(Item::Item(Items::Lantern));
	inventory.push_back(Item::Item(Items::Provisions));
	inventory.push_back(Item::Item(item));
}

Player::~Player() {}

// accessor methods
string Player::getPlayerName() {
	return playerName;
}

int Player::getPlayerHp() {
	return playerHp;
}

int Player::getPlayerAtk() {
	return playerAtk;
}

int Player::getPlayerDef() {
	return playerDef;
}

int Player::getPlayerDmg() {
	return playerDmg;
}

int Player::getPlayerLuck() {
	return playerLuck;
}

string Player::displayInventory() {
	// returns a formatted string
	vector<Item>::iterator itr;
	stringstream inventoryDetails;
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << "\n~~~~~~~~~~~~~~~ Inventory ~~~~~~~~~~~~~~";
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	for (itr = inventory.begin(); itr < inventory.end(); itr++) {
		Item& item = *itr;
		if (itr == inventory.begin()) { // if clause just for formatting purpose
			inventoryDetails << "\n Content : " << item.getItemName();
		}
		else {
			inventoryDetails << "\n         : " << item.getItemName();
		}
		
	}
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << "\n~~~~~~~~~~ Bottom of Inventory ~~~~~~~~~";
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return inventoryDetails.str();
}

string Player::getDetails() {
	// returns a formatted string
	stringstream playerDetails;
	playerDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	playerDetails << "\n Player Name       : " << getPlayerName();
	playerDetails << "\n Player Health     : " << getPlayerHp();
	playerDetails << "\n Player Attack     : " << getPlayerAtk();
	playerDetails << "\n Player Defence    : " << getPlayerDef();
	playerDetails << "\n Player Damage     : " << getPlayerDmg();
	playerDetails << "\n Player Luck       : " << getPlayerLuck();
	playerDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	playerDetails << displayInventory() << endl;
	return playerDetails.str();
}


// mutator methods
void Player::setPlayerName(string name) {
	if (name != "") {
		playerName = name;
	}
	else {
		playerName = "The Tarnished";
	}
}

void Player::setPlayerHp(int hp) {
	if (hp > 0) {
		playerHp = hp;
	}
}

void Player::setPlayerAtk(int atk) {
	if (atk > 0) {
		playerAtk = atk;
	}
}

void Player::setPlayerDef(int def) {
	if (def > 0) {
		playerDef = def;
	}
}

void Player::setPlayerDmg(int dmg) {
	if (dmg > 0) {
		playerDmg = dmg;
	}
}

void Player::setPlayerLuck(int luck) {
	if (luck > 0) {
		playerLuck = luck;
	}
}

void Player::updatePlayerHp(int hp) {
	if (playerHp + hp >= 0) {
		playerHp += hp;
	}
	else {
		playerHp = 0;
	}
}

void Player::updatePlayerAtk(int atk) {
	if (playerAtk + atk >= 0) {
		playerAtk += atk;
	}
	else {
		playerAtk = 0;
	}
}

void Player::updatePlayerDef(int def) {
	if (playerDef + def >= 0) {
		playerDef += def;
	}
	else {
		playerDef = 0;
	}
}

void Player::updatePlayerDmg(int dmg) {
	if (playerDmg + dmg >= 0) {
		playerDmg += dmg;
	}
	else {
		playerDmg = 0;
	}
}

void Player::updatePlayerLuck(int luck) {
	if (playerLuck + luck >= 0) {
		playerLuck += luck;
	}
	else {
		playerLuck = 0;
	}
}

void Player::addItemToInventory(Items item) {
	inventory.push_back(Item::Item(item));
}

void Player::deleteItemFromInventory(string newItem, bool removeItem){ // find matching item and stop once successful remove
	vector<Item>::iterator itr;
	if (removeItem == true) {
		for (itr = inventory.begin(); itr != inventory.end(); ++itr) {
			Item& item = *itr;
			if (item.getItemName() == newItem) {
				inventory.erase(itr);
				break;
			}
		}
	}
}

// Generate number with given range
int Player::genValue(int min, int max) {
	return (rand() % (max - min + 1) + min);
}