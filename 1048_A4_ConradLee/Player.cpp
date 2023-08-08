/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Player Class File
 **************************************************/
#include "Player.h"

 // constructor

Player::Player(string newPlayerName) {
	playerName = newPlayerName;
	initPlayer();
}

Player::~Player() {}

void Player::initPlayer() {
	playerMaxHp = Helper::genValue(4, 12) + 12;
	playerHp = playerMaxHp;
	playerAtk = playerMaxHp / 6;
	playerDef = playerAtk / 2;
	playerDmg = playerAtk + 0;
	playerLuck = Helper::genValue(2, 6) + 6;
	inventory.push_back(Item::initNewItem(ItemObject::Map));
	inventory.push_back(Item::initNewItem(ItemObject::Lantern));
	inventory.push_back(Item::initNewItem(ItemObject::Provisions));
	setItemUses(ItemObject::Gold, Helper::genValue(20, 40));
}

// accessor methods
string Player::getPlayerName() {
	return playerName;
}

int Player::getPlayerMaxHp() {
	return playerMaxHp;
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
	vector<Item*>::iterator itr;
	stringstream artefactsAndEquipments;
	stringstream items;
	stringstream importantItems;
	for (itr = inventory.begin(); itr < inventory.end(); itr++) {
		Item* item = *itr;
		if (item->getItemObject() == ItemObject::Map || item->getItemObject() == ItemObject::Lantern) {
			importantItems << "\n           " << item->getItemName();
		}
		else if (item->getItemType() == ItemType::Armour || item->getItemType() == ItemType::Weapon || item->getItemType() == ItemType::Artefact) {
			artefactsAndEquipments << "\n           " << item->getItemName();
		}
		else {
			items << "\n           " << item->getItemName();
		}

	}
	stringstream inventoryDetails;
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << "\n~~~~~~~~~~~~~~~ Inventory ~~~~~~~~~~~~~~";
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << "\n~~~~~~  Artefacts and Equipments   ~~~~~";
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << "\n Capacity : " << getUsedCapacity() << " / " << inventoryCapacity;
	inventoryDetails << artefactsAndEquipments.str();
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << "\n~~~~~~            Items            ~~~~~";
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << items.str();
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << "\n~~~~~~       Important Items       ~~~~~";
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inventoryDetails << importantItems.str();
	inventoryDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return inventoryDetails.str();
}

string Player::getDetails() {
	// returns a formatted string
	stringstream playerDetails;
	playerDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	playerDetails << "\n Player Name       : " << getPlayerName();
	playerDetails << "\n Player Health     : " << getPlayerHp() << " / " << getPlayerMaxHp();
	playerDetails << "\n Player Attack     : " << getPlayerAtk();
	playerDetails << "\n Player Defence    : " << getPlayerDef();
	playerDetails << "\n Player Damage     : " << getPlayerDmg();
	playerDetails << "\n Player Luck       : " << getPlayerLuck();
	playerDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	playerDetails << displayInventory() << endl;
	return playerDetails.str();
}

int Player::findItemIndex(ItemObject itemObject) {
	// Find the inventory for an item and return the index, or return -1 if nothing is found
	for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
		if ((*it)->getItemObject() == itemObject) {
			return (int) distance(inventory.begin(), it);
		}
	}
	return -1;
}

bool Player::isCollectedAllArtefacts() {
	return collectedAllArtefacts;
}

vector<Item*> Player::getPlayerInventory() {
	return inventory;
}

bool Player::canFightDragon() {
	// Check if inventory contains all artefacts required to fight the dragon
	int count = 0;
	for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
		if (find(begin(artefactsRequiredToFightDragon), end(artefactsRequiredToFightDragon), (*it)->getItemObject()) != end(artefactsRequiredToFightDragon)) {
			count++;
		}
	}
	return count == (int) (sizeof(artefactsRequiredToFightDragon) / sizeof(artefactsRequiredToFightDragon[0]));
}

int Player::getItemUses(ItemObject itemObject) {
	for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
		if ((*it)->getItemObject() == itemObject) {
			return (*it)->getItemUses();
		}
	}
	return 0;
}

// mutator methods
void Player::setPlayerName(string name) {
	playerName = name;
}

void Player::setPlayerMaxHp(int maxHp) {
	if (maxHp >= 0) {
		playerMaxHp = maxHp;
		if (playerHp > playerMaxHp) {
			playerHp = playerMaxHp;
		}
	}
}

void Player::setPlayerHp(int hp) {
	if (hp >= 0) {
		playerHp = hp;
	}
}

void Player::setPlayerAtk(int atk) {
	if (atk >= 0) {
		playerAtk = atk;
	}
}

void Player::setPlayerDef(int def) {
	if (def >= 0) {
		playerDef = def;
	}
}

void Player::setPlayerDmg(int dmg) {
	if (dmg >= 0) {
		playerDmg = dmg;
	}
}

void Player::setPlayerLuck(int luck) {
	if (luck >= 0) {
		playerLuck = luck;
	}
}

void Player::setInventoryCapacity(int capacity) {
	inventoryCapacity = capacity;
}

void Player::updatePlayerMaxHp(int maxhp) {
	playerMaxHp += maxhp;
	if (playerMaxHp < 0) {
		playerMaxHp = 0;
	}
	if (playerHp > playerMaxHp) {
		playerHp = playerMaxHp;
	}
}

void Player::updatePlayerHp(int hp) {
	playerHp = min(playerHp + hp, playerMaxHp);
	if (playerHp < 0) {
		playerHp = 0;
	}
}

void Player::updatePlayerAtk(int atk) {
	playerAtk += atk;
	if (playerAtk < 0) {
		playerAtk = 0;
	}
}

void Player::updatePlayerDef(int def) {
	playerDef += def;
	if (playerDef < 0) {
		playerDef = 0;
	}
}

void Player::updatePlayerDmg(int dmg) {
	playerDmg += dmg;
	if (playerDmg < 0) {
		playerDmg = 0;
	}
}

void Player::updatePlayerLuck(int luck) {
	playerLuck += luck;
	if (playerLuck < 0) {
		playerLuck = 0;
	}
}

bool Player::addItemToInventory(Item* item) {
	if (item->getItemType() == ItemType::Armour || item->getItemType() == ItemType::Weapon || item->getItemType() == ItemType::Artefact) {
		// Return false if inventory is full
		if (getUsedCapacity() == inventoryCapacity) {
			return false;
		}
	}
	// Call the onPickup function on the item
	item->onPickup(this);
	int index = findItemIndex(item->getItemObject());
	if (index >= 0) {
		// If inventory already has that item, add to the item uses instead
		inventory[index]->updateItemUses(item->getItemUses());
		delete item;
	}
	else {
		inventory.push_back(item);
		if (item->getItemType() == ItemType::Artefact) {
			// Check if all artefacts are collected
			int count = 0;
			for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
				if ((*it)->getItemType() == ItemType::Artefact) {
					count++;
				}
			}
			if (count == 5) {
				collectedAllArtefacts = true;
				cout << "You have collected all artefacts! Return to the entrance to win the game!" << endl;
			}
		}
	}
	return true;
}

int Player::getUsedCapacity() {
	int usedCapacity = 0;
	for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
		Item* item = *it;
		if (item->getItemType() == ItemType::Armour || item->getItemType() == ItemType::Weapon || item->getItemType() == ItemType::Artefact) {
			usedCapacity += item->getItemUses();
		}
	}
	return usedCapacity;
}

// Delete a specific item from the inventory
void Player::deleteItemFromInventory(Item* item){
	vector<Item*>::iterator it;
	for (it = inventory.begin(); it != inventory.end(); ++it) {
		if ((*it) == item) {
			item->onDrop(this, item->getItemUses());
			inventory.erase(it);
			delete item;
			return;
		}
	}
}

// Find the item and update its uses
void Player::updateItemUses(ItemObject itemObject, int uses) {
	if (uses == 0) {
		return;
	}
	for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
		if ((*it)->getItemObject() == itemObject) {
			(*it)->updateItemUses(uses);
			if ((*it)->getItemUses() == 0) {
				deleteItemFromInventory(*it);
			}
			return;
		}
	}
	if (uses > 0) {
		Item* item = Item::initNewItem(itemObject);
		item->setItemUses(uses);
		addItemToInventory(item);
	}
}

// Find the item add set its uses
void Player::setItemUses(ItemObject itemObject, int uses) {
	for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
		if ((*it)->getItemObject() == itemObject) {
			(*it)->setItemUses(uses);
			if ((*it)->getItemUses() == 0) {
				deleteItemFromInventory(*it);
			}
			return;
		}
	}
	if (uses > 0) {
		Item* item = Item::initNewItem(itemObject);
		item->setItemUses(uses);
		addItemToInventory(item);
	}
}