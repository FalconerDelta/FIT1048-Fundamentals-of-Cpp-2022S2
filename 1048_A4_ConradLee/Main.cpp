/**************************************************
  Project: The Treasure Caverns of Doom Main Application
   Author: Conrad Lee
  Purpose: The Treasure Caverns of Doom

  Note: For extra functionality, the first two and the last three were implemented.
 **************************************************/
#include "Main.h"

int main() {
	
	// seed random
	srand(unsigned(time(nullptr)));

	displayHowToPlay();
	Helper::waitForKeyPress();
	selectSkillLevel();
	inputPlayerName();
	initLocations();
	buyItems();
	while (!isGameEnd) {
		mainSequence();
	}
	cout << "Your final score: " << turnScore + monsterScore + victoryScore << endl;
	system("pause");
	return 0;

}

// Display how to play loading from the HowToPlay.txt
// This is called when the game starts and when [H] is input by the user
void displayHowToPlay() {

	Helper::clearScreen();
	ifstream howToPlay("HowToPlay.txt");
	string text;
	while (getline(howToPlay, text)) {
		cout << text << endl;
	}

}

// Display map
// This is called when [M] is input by the user
void displayMap() {

	Helper::clearScreen();
	ifstream showMap("Map.txt");
	string text;
	while (getline(showMap, text)) {
		cout << text << endl;
	}

}

// Select difficulty (Difficulty affects lantern oil uses and inventory capactiy, but increases score when victory)
// This is called as part of the game start sequence
void selectSkillLevel() {
	Helper::clearScreen();
	cout << "Choose your skill level:" << endl;
	vector<char> acceptedCommands{ 'R', 'A', 'M' };
	cout << "[R]: Rookie - Large units of lantern oil, huge inventory capacity" << endl;
	cout << "[A]: Adventurer - Normal units of lantern oil, standard inventory capacity" << endl;
	cout << "[M]: Master Adventurer - Few units of lantern oil, small inventory capacity" << endl;
	switch (Helper::inputLetter(acceptedCommands, "Select your option: ")) {
	case 'R':
		skillLevel = SkillLevel::Rookie;
		player.setItemUses(ItemObject::Lantern, ROOKIE_LANTERN_OIL);
		player.setInventoryCapacity(ROOKIE_INVENTORY_CAPACITY);
		break;
	case 'A':
		skillLevel = SkillLevel::Adventurer;
		player.setItemUses(ItemObject::Lantern, ADVENTURER_LANTERN_OIL);
		player.setInventoryCapacity(ADVENTURER_INVENTORY_CAPACITY);
		break;
	case 'M':
		skillLevel = SkillLevel::MasterAdventurer;
		player.setItemUses(ItemObject::Lantern, MASTER_LANTERN_OIL);
		player.setInventoryCapacity(MASTER_INVENTORY_CAPACITY);
		break;
	}
}

// Input Player name
// This is called as part of the game start sequence
void inputPlayerName() {

	Helper::clearScreen();
	cout << "Type your player name: ";
	string name;
	cin >> name;
	player.setPlayerName(name);

}

// Setup locations
// This is called as part of the game start sequence
void initLocations() {

	ifstream locationNames("LocationNames.txt");
	ifstream locationExits("LocationExits.txt");
	ifstream locationDescriptions("LocationDescriptions.txt");
	string str;
	int index = 0;
	int itemIndex = 0;
	int monsterIndex = 0;
	// Shuffle the array of inner ring monsters and their items
	random_shuffle(begin(innerRingMonsters), end(innerRingMonsters));
	random_shuffle(begin(innerRingNonDragonItems), end(innerRingNonDragonItems));
	// Get location names line by line and assign the exits and descriptions from the other text files to it
	// This is assuming each line of the three text files are corresponding to the same location
	while (getline(locationNames, str)) {
		Location location = Location::Location();
		location.setLocationName(str);
		getline(locationDescriptions, str);
		location.setLocationDescription(str);
		getline(locationExits, str);
		stringstream ss(str);
		for (int i = 0; i < 4; i++) {
			string exitStr;
			ss >> exitStr;
			location.setExit(i, stoi(exitStr));
		}
		// If the location is the entrance do not spawn a monster
		// Else spawn random weak monster if it is not in inner ring
		// Else pick the next monster from the inner ring monster arry
		// And assign next item from the inner ring monster item array if it is not a dragon
		if (index != ENTRANCE_INDEX) {
			if (index >= INNER_RING_BEGIN_INDEX) {
				location.setMonster(innerRingMonsters[monsterIndex++]);
				if (location.getMonster()->getMonsterType() != MonsterType::Dragon) {
					ItemObject artefact = innerRingNonDragonItems[itemIndex++];
					location.getMonster()->setMonsterItem(Item::initNewItem(artefact));
				}
			}
			else {
				int random = Helper::genValue(0, 2);
				switch (random) {
				case 0:
					location.setMonster(MonsterType::Goblin);
					break;
				case 1:
					location.setMonster(MonsterType::Hobgoblin);
					break;
				}
			}
		}
		locations[index] = location;
		index++;
	}
	currentLocation = &locations[ENTRANCE_INDEX];
	// The first treasure hunter, Gossiper, is spawned at the start of the game
	TreasureHunter* hunter = new Gossiper();
	spawnHunter(hunter);
	hunters.push_back(hunter);

}

// Game start Buy Item screen
// This is called as part of the game start sequence
void buyItems() {

	bool isQuit = false;
	// List of items to buy, removing once it is bought
	vector<ItemObject> remainingItems{ ItemObject::Armour, ItemObject::Sword, ItemObject::Gloves, ItemObject::Necklace, ItemObject::Lantern };
	do {
		Helper::clearScreen();
		vector<char> acceptedCommands{ 'Q' };
		cout << "Buy some items before the game start!" << endl;
		for (vector<ItemObject>::iterator it = remainingItems.begin(); it != remainingItems.end(); ++it) {
			switch (*it) {
			case ItemObject::Armour:
				cout << "[A]: Pay 15 golds to buy a leather armour" << endl;
				acceptedCommands.push_back('A');
				break;
			case ItemObject::Sword:
				cout << "[S]: Pay 15 golds to buy a sword" << endl;
				acceptedCommands.push_back('S');
				break;
			case ItemObject::Gloves:
				cout << "[G]: Pay 20 golds to buy leather gloves" << endl;
				acceptedCommands.push_back('G');
				break;
			case ItemObject::Necklace:
				cout << "[N]: Pay 10 golds to buy a necklace" << endl;
				acceptedCommands.push_back('N');
				break;
			case ItemObject::Lantern:
				cout << "[L]: Pay 20 golds to buy 50 units of lantern oil" << endl;
				acceptedCommands.push_back('L');
				break;
			}
		}
		cout << "[Q]: Leave the shop" << endl;
		cout << player.getDetails();
		ItemObject buyingItem = ItemObject::Lantern;
		int price = 0;
		switch (Helper::inputLetter(acceptedCommands, "Select your option: ")) {
		case 'A':
			buyingItem = ItemObject::Armour;
			price = 15;
			break;
		case 'S':
			buyingItem = ItemObject::Sword;
			price = 15;
			break;
		case 'G':
			buyingItem = ItemObject::Gloves;
			price = 20;
			break;
		case 'N':
			buyingItem = ItemObject::Necklace;
			price = 10;
			break;
		case 'L':
			buyingItem = ItemObject::Lantern;
			price = 20;
			break;
		case 'Q':
			isQuit = true;
			break;
		}
		if (!isQuit) {
			// Check if gold is enough
			if (player.getItemUses(ItemObject::Gold) < price) {
				cout << "You do not have enough golds!" << endl;
			}
			else {
				// Remove the item from the shop
				// If lantern, add oil
				// Else add the item to the inventory
				remainingItems.erase(find(remainingItems.begin(), remainingItems.end(), buyingItem));
				if (buyingItem == ItemObject::Lantern) {
					player.updateItemUses(ItemObject::Gold, -price);
					player.updateItemUses(ItemObject::Lantern, 50);
					cout << "Lantern oil increased by 50." << endl;
				}
				else {
					if (player.addItemToInventory(Item::initNewItem(buyingItem))) {
						player.updateItemUses(ItemObject::Gold, -price);
					}
					else {
						cout << "But your inventory is full!" << endl;
					}
				}
			}
			Helper::waitForKeyPress();
		}
	} while (!isQuit);

}

// Main game loop
void mainSequence() {
	Helper::clearScreen();
	// Print all the details
	cout << currentLocation->getDetails();
	if (currentLocation->isEnemyExists()) {
		cout << currentLocation->getMonster()->getDetails();
	}
	displayHunterInfo();
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n Turn: " << turn;
	cout << "\n Score: " << turnScore + monsterScore;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << player.getDetails();
	// P, D, M, H, Q is always acceptable as a command
	vector<char> acceptedCommands{ 'P', 'D', 'M', 'H', 'Q' };
	cout << "Available Actions:" << endl;
	if (currentLocation->isEnemyExists()) {
		// If the location has enemy, allow player to attack or flee
		// Player cannot fight dragon until canFightDragon is true (player collected all artefact gears)
		if (currentLocation->getMonster()->getMonsterType() == MonsterType::Dragon && !player.canFightDragon()) {
			cout << "You cannot fight with the dragon until the artefacts set is collected!" << endl;

		}
		else {
			acceptedCommands.push_back('A');
			cout << "[A]: Combat with the " << currentLocation->displayMonster() << "!" << endl;
		}
		acceptedCommands.push_back('F');
		cout << "[F]: Flee to another location but take damage!" << endl;
	}
	else {
		// If the location has no enemies, allow player to examine for items
		acceptedCommands.push_back('X');
		cout << "[X]: Examine for treasure, but consume oil." << endl;
		// If loot exists, allow player to take the item
		if (currentLocation->isLootExists()) {
			acceptedCommands.push_back('T');
			cout << "[T]: Take the " << currentLocation->displayItem() << " at the location." << endl;
		}
		// Add N/E/S/W if an exit exists at that direction
		if (currentLocation->hasNorthExit()) {
			acceptedCommands.push_back('N');
			cout << "[N]: Go North to " << locations[currentLocation->getNorthExit()].getLocationName() << "." << endl;
		}
		if (currentLocation->hasEastExit()) {
			acceptedCommands.push_back('E');
			cout << "[E]: Go East to " << locations[currentLocation->getEastExit()].getLocationName() << "." << endl;
		}
		if (currentLocation->hasSouthExit()) {
			acceptedCommands.push_back('S');
			cout << "[S]: Go South to " << locations[currentLocation->getSouthExit()].getLocationName() << "." << endl;
		}
		if (currentLocation->hasWestExit()) {
			acceptedCommands.push_back('W');
			cout << "[W]: Go West to " << locations[currentLocation->getWestExit()].getLocationName() << "." << endl;
		}
	}
	cout << "[P]: Eat provisions and potions." << endl;
	cout << "[D]: Drop items in your inventory." << endl;
	cout << "[M]: Open the map." << endl;
	cout << "[H]: Show instructions of the game." << endl;
	cout << "[Q]: Exit the game." << endl;

	switch (Helper::inputLetter(acceptedCommands, "Select your action: ")) {
	case 'A':
		combatSequence();
		break;
	case 'F':
		handleFleeing();
		break;
	case 'X':
		examine();
		break;
	case 'T':
		takeItem();
		break;
	case 'N':
		currentLocation = &locations[currentLocation->getNorthExit()];
		handleMoving();
		break;
	case 'E':
		currentLocation = &locations[currentLocation->getEastExit()];
		handleMoving();
		break;
	case 'S':
		currentLocation = &locations[currentLocation->getSouthExit()];
		handleMoving();
		break;
	case 'W':
		currentLocation = &locations[currentLocation->getWestExit()];
		handleMoving();
		break;
	case 'P':
		drinkPotion();
		break;
	case 'D':
		dropItem();
		break;
	case 'M':
		displayMap();
		break;
	case 'H':
		displayHowToPlay();
		break;
	case 'Q':
		cout << "Goodbye!" << endl;
		turnScore = 0;
		isGameEnd = true;
		break;
	}
	Helper::waitForKeyPress();
}

// Handles moving of the character
void handleMoving() {
	cout << "You travelled to " << currentLocation->getLocationName() << endl;
	// Check victory condition
	if (currentLocation == &locations[ENTRANCE_INDEX] && player.isCollectedAllArtefacts()) {
		cout << "You have returned to the entrance with all artefacts!" << endl;
		cout << "You win!" << endl;
		switch (skillLevel) {
		case SkillLevel::Rookie:
			victoryScore = ROOKIE_VICTORY_SCORE;
			break;
		case SkillLevel::Adventurer:
			victoryScore = ADVENTURER_VICTORY_SCORE;
			break;
		case SkillLevel::MasterAdventurer:
			victoryScore = MASTER_VICTORY_SCORE;
			break;
		}
		isGameEnd = true;
	}
	else {
		reduceOil();
		advanceTurn();
	}
}

// Combat sequence
void combatSequence() {
	Helper::clearScreen();
	Monster* enemy = currentLocation->getMonster();
	int turn = 1;
	// Combat loop - until one of them has 0 hp
	while (enemy->getMonsterHp() > 0 && player.getPlayerHp() > 0) {
		cout << "==========" << "Turn " << turn << "==========" << endl;
		Sleep(SLEEP_DURATION);
		int playerAttack = player.getPlayerAtk() + Helper::genValue(2, 10);
		int enemyAttack = enemy->getMonsterAtk() + Helper::genValue(2, 10);
		cout << player.getPlayerName() << " rolled an attack of " << playerAttack << ", " << enemy->getMonsterName() << " rolled an attack of " << enemyAttack << "." << endl;
		Sleep(SLEEP_DURATION);
		// Minimum damage 1 to avoid stalemale loop
		if (playerAttack > enemyAttack) {
			// Deal damage to enemy
			int damage = max(1, player.getPlayerDmg() - enemy->getMonsterDef());
			enemy->updateMonsterHp(-damage);
			cout << player.getPlayerName() << " dealt " << damage << " damage to " << enemy->getMonsterName() << "!" << endl;
		}
		else if (playerAttack < enemyAttack) {
			// Ennemy deals damage to player
			int damage = max(1, enemy->getMonsterDmg() - player.getPlayerDef());
			player.updatePlayerHp(-damage);
			cout << enemy->getMonsterName() << " dealt " << damage << " damage to " << player.getPlayerName() << "!" << endl;
		}
		else {
			// If same attack value, stalemate this turn
			cout << "This round results in a stalemate!" << endl;
		}
		cout << player.getPlayerName() << "'s remaining health: " << player.getPlayerHp() << ", " << enemy->getMonsterName() << "'s remaining health: " << enemy->getMonsterHp() << endl;
		turn++;
	}
	// Check game over by running out of health
	if (player.getPlayerHp() == 0) {
		gameoverByMonster(enemy->getMonsterName());
	}
	else {
		cout << enemy->getMonsterName() << " has been slain!" << endl;
		// Add score according to the monster level
		monsterScore += DEFEAT_MONSTER_SCORE_BY_LEVEL[enemy->getMonsterLevel()];
		if (enemy->isHasItem()) {
			// Drop the item carried by the monster
			currentLocation->setItem(enemy->getMonsterItem());
			cout << enemy->getMonsterName() << " dropped off " << currentLocation->displayItem() << "!" << endl;
		}
		if (enemy->getMonsterType() == MonsterType::Ogre || enemy->getMonsterType() == MonsterType::Troll || enemy->getMonsterType() == MonsterType::Dragon) {
			if (++killedEpicMonsters == 1) {
				// If 1 of 5 epic monsters are killed, merchant is spawned
				TreasureHunter* hunter = new Merchant();
				spawnHunter(hunter);
				hunters.push_back(hunter);
			}
			else if (killedEpicMonsters == 3) {
				// If 3 of 5 epic monsters are killed, ninja is spawned
				TreasureHunter* hunter = new Ninja();
				spawnHunter(hunter);
				hunters.push_back(hunter);
			}
		}
		currentLocation->removeMonster();
		advanceTurn();
	}
}

// Handls fleeing 
void handleFleeing() {
	Monster& enemy = *currentLocation->getMonster();
	int damage = max(1, enemy.getMonsterDmg() - player.getPlayerDef());
	player.updatePlayerHp(-damage);
	cout << enemy.getMonsterName() << " dealt " << damage << " damage to " << player.getPlayerName() << "!" << endl;
	cout << player.getPlayerName() << "'s remaining health: " << player.getPlayerHp() << endl;
	// Check game over by running out of health
	if (player.getPlayerHp() == 0) {
		gameoverByMonster(enemy.getMonsterName());
	}
	else {
		// Get player input of which exit to go
		vector<char> acceptedCommands;
		cout << "Available Locations:" << endl;
		if (currentLocation->hasNorthExit()) {
			acceptedCommands.push_back('N');
			cout << "[N]: Flee North to " << locations[currentLocation->getNorthExit()].getLocationName() << "." << endl;
		}
		if (currentLocation->hasEastExit()) {
			acceptedCommands.push_back('E');
			cout << "[E]: Flee East to " << locations[currentLocation->getEastExit()].getLocationName() << "." << endl;
		}
		if (currentLocation->hasSouthExit()) {
			acceptedCommands.push_back('S');
			cout << "[S]: Flee South to " << locations[currentLocation->getSouthExit()].getLocationName() << "." << endl;
		}
		if (currentLocation->hasWestExit()) {
			acceptedCommands.push_back('W');
			cout << "[W]: Flee West to " << locations[currentLocation->getWestExit()].getLocationName() << "." << endl;
		}
		switch (Helper::inputLetter(acceptedCommands, "Select your destination: ")) {
		case 'N':
			currentLocation = &locations[currentLocation->getNorthExit()];
			handleMoving();
			break;
		case 'E':
			currentLocation = &locations[currentLocation->getEastExit()];
			handleMoving();
			break;
		case 'S':
			currentLocation = &locations[currentLocation->getSouthExit()];
			handleMoving();
			break;
		case 'W':
			currentLocation = &locations[currentLocation->getWestExit()];
			handleMoving();
			break;
		}
	}
}

// Gameover trigger - Out of oil
void gameoverByLantern() {
	cout << "You have run out of lantern oil!" << endl;
	cout << "Game Over!" << endl;
	turnScore = 0;
	isGameEnd = true;
}

// Gameover trigger - player's death
void gameoverByMonster(string monsterName) {
	cout << player.getPlayerName() << " is slain by " << monsterName << "!" << endl;
	cout << "Game Over!" << endl;
	turnScore = 0;
	isGameEnd = true;
}

// Examine location for items
void examine() {
	cout << "Searching for treasure";
	for (int i = 0; i < 3; i++) {
		Sleep(SLEEP_DURATION);
		cout << ".";
	}
	cout << endl;
	int random = Helper::genValue(1, 100);
	Item* newItem = NULL;
	bool foundItem = false;
	if (random <= 30) {
		foundItem = true;
		newItem = Item::genGemsOrGold();
	}
	else if (random <= 50) {
		foundItem = true;
		newItem = Item::genRandomItemExcludingGemsAndGold();
	}
	else {
		cout << "You found nothing." << endl;
	}
	if (foundItem) {
		cout << "You found " << newItem->getItemName() << "!" << endl;
		if (!player.addItemToInventory(newItem)) {
			// If inventory is full, the examined item is wasted
			cout << "However your inventory is full." << endl;
		}
	}
	reduceOil();
	advanceTurn();
}

// Reduce oil
// This is called after moving and after examining for items
void reduceOil() {
	int oldUses = player.getItemUses(ItemObject::Lantern);
	player.updateItemUses(ItemObject::Lantern, -Helper::genValue(2, 5));
	cout << "Lantern oil reduced from " << oldUses << " to " << player.getItemUses(ItemObject::Lantern) << endl;
	// Check game over by running out of lantern oil
	if (player.getItemUses(ItemObject::Lantern) == 0) {
		gameoverByLantern();
	}
}

// Take Item
void takeItem() {
	cout << "You took the " << currentLocation->displayItem() << " from the ground." << endl;
	if (player.addItemToInventory(currentLocation->getItem())) {
		currentLocation->removeItem();
	}
	else {
		cout << "However your inventory is full!" << endl;
	}
}

// Drop Item
void dropItem() {
	cout << "List of items:" << endl;
	vector<Item*> inventory = player.getPlayerInventory();
	int currentMenuIndex = 1;
	map<int, Item*> menuToItemMap;
	vector<char> acceptedCommands;
	// Check for each item if it is droppable and add the index to the accepted command
	for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
		if ((*it)->isDroppable()) {
			int index = (int) distance(inventory.begin(), it);
			cout << "[" << currentMenuIndex << "]: " << (*it)->getItemName() << " - " << (*it)->getItemDescription() << endl;
			menuToItemMap.insert(pair<int, Item*> (currentMenuIndex, *it));
			acceptedCommands.push_back(currentMenuIndex + '0');
			currentMenuIndex++;
		}
	}
	cout << "[0] - Back to menu" << endl;
	acceptedCommands.push_back('0');
	int input = Helper::inputLetter(acceptedCommands, "Select an item to drop: ") - '0';
	if (input == 0) {
		return;
	}
	Item* item = menuToItemMap[input];
	if (item->getItemUses() > 1) {
		// If item has multiple uses, ask for the desired quantity to drop
		bool finished = false;
		do {
			string quantityString;
			cout << "Input a quantity to drop (1-" << item->getItemUses() << "): ";
			cin >> quantityString;
			try {
				int quantity = stoi(quantityString);
				if (quantity < 0 || quantity > item->getItemUses()) {
					continue;
				}
				if (quantity == item->getItemUses()) {
					player.deleteItemFromInventory(item);
					finished = true;
				}
				else {
					item->dropItemUses(&player, -quantity);
					finished = true;
				}
			}
			catch (...) {
			}
		} while (!finished);
	}
	else {
		// If only one use, delete the item from the inventory directly
		player.deleteItemFromInventory(item);
	}
}

// Drink potion
void drinkPotion() {
	cout << "List of potions:" << endl;
	vector<Item*> inventory = player.getPlayerInventory();
	int currentMenuIndex = 1;
	map<int, Item*> menuToItemMap;
	vector<char> acceptedCommands;
	// Check for each item if it is a potion and add the index to the accepted command
	for (vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
		if ((*it)->isPotion()) {
			int index = (int)distance(inventory.begin(), it);
			cout << "[" << currentMenuIndex << "]: " << (*it)->getItemName() << " - " << (*it)->getItemDescription() << endl;
			menuToItemMap.insert(pair<int, Item*>(currentMenuIndex, *it));
			acceptedCommands.push_back(currentMenuIndex + '0');
			currentMenuIndex++;
		}
	}
	cout << "[0] - Back to menu" << endl;
	acceptedCommands.push_back('0');
	int input = Helper::inputLetter(acceptedCommands, "Select a potion to drink: ") - '0';
	if (input == 0) {
		return;
	}
	Item* item = menuToItemMap[input];
	// Use the potion, calling its onUse function
	item->onUse(&player);
	string itemName = item->getItemName();
	if (item->getItemUses() > 1) {
		item->updateItemUses(-1);
	}
	else {
		player.deleteItemFromInventory(item);
	}
	// Check game over by drinking the elixir
	if (player.getPlayerHp() == 0) {
		gameoverByMonster(itemName);
	}
}

// Advance Turn
// Turn is advanced only after the player has examined, attacked, fleed or moved
void advanceTurn() {
	turn++;
	// Turn score decreases each turn
	turnScore -= SCORE_DECAY_PER_TURN;
	// The treasure hunters move after a fixed amount of turns has passed
	if (turn % TREASURE_HUNTER_ROAM_PER == 0) {
		handleHuntersMove();
	}
	// After the moving, check for hunter encounter
	// A player can only encounter that hunter again after the hunter moved in next iteration
	if (currentLocation->isHunterExists() && !currentLocation->getHunter()->isEncountered()) {
		currentLocation->getHunter()->encounter(&player);
		currentLocation->getHunter()->setIsEncountered(true);
		if (player.getPlayerHp() == 0) {
			gameoverByMonster(currentLocation->getHunter()->getHunterName());
		}
		else if (player.getItemUses(ItemObject::Lantern) == 0) {
			gameoverByLantern();
		}
	}
}

// Move the hunter
void handleHuntersMove() {
	for (vector<TreasureHunter*>::iterator it = begin(hunters); it != end(hunters); ++it) {
		(*it)->setIsEncountered(false);
		// 0 = North, 1 = East, 2 = South, 3 = West
		int directions[4] = { 0, 1, 2, 3 };
		random_shuffle(begin(directions), end(directions));
		bool isMoved = false;
		// Check each direction if exit exists there and there are no hunters at that location
		// And move to there if conditions are fulfilled
		for (int i = 0; i < 4; i++) {
			int direction = directions[i];
			switch (direction) {
			case 0:
				if (!(*it)->getLocation()->hasNorthExit()) {
					continue;
				}
				if (locations[(*it)->getLocation()->getNorthExit()].isHunterExists()) {
					continue;
				}
				isMoved = true;
				(*it)->getLocation()->removeHunter();
				(*it)->setLocation(&locations[(*it)->getLocation()->getNorthExit()]);
				(*it)->getLocation()->setHunter(hunters[distance(hunters.begin(), it)]);
				cout << (*it)->getHunterName() << " moved to " << (*it)->getLocation()->getLocationName() << endl;
				break;
			case 1:
				if (!(*it)->getLocation()->hasEastExit()) {
					continue;
				}
				if (locations[(*it)->getLocation()->getEastExit()].isHunterExists()) {
					continue;
				}
				isMoved = true;
				(*it)->getLocation()->removeHunter();
				(*it)->setLocation(&locations[(*it)->getLocation()->getEastExit()]);
				(*it)->getLocation()->setHunter(hunters[distance(hunters.begin(), it)]);
				cout << (*it)->getHunterName() << " moved to " << (*it)->getLocation()->getLocationName() << endl;
				break;
			case 2:
				if (!(*it)->getLocation()->hasSouthExit()) {
					continue;
				}
				if (locations[(*it)->getLocation()->getSouthExit()].isHunterExists()) {
					continue;
				}
				isMoved = true;
				(*it)->getLocation()->removeHunter();
				(*it)->setLocation(&locations[(*it)->getLocation()->getSouthExit()]);
				(*it)->getLocation()->setHunter(hunters[distance(hunters.begin(), it)]);
				cout << (*it)->getHunterName() << " moved to " << (*it)->getLocation()->getLocationName() << endl;
				break;
			case 3:
				if (!(*it)->getLocation()->hasWestExit()) {
					continue;
				}
				if (locations[(*it)->getLocation()->getWestExit()].isHunterExists()) {
					continue;
				}
				isMoved = true;
				(*it)->getLocation()->removeHunter();
				(*it)->setLocation(&locations[(*it)->getLocation()->getWestExit()]);
				(*it)->getLocation()->setHunter(hunters[distance(hunters.begin(), it)]);
				cout << (*it)->getHunterName() << " moved to " << (*it)->getLocation()->getLocationName() << endl;
				break;
			}
			if (isMoved) {
				break;
			}
		}
		// If no exits are available, the hunter stays
		if (!isMoved) {
			cout << (*it)->getHunterName() << " stayed at " << (*it)->getLocation()->getLocationName() << endl;
		}
	}
}

// Spawn Hunter at a random location without hunter and where the player does not exist there
void spawnHunter(TreasureHunter* hunter) {
	int index;
	do {
		index = Helper::genValue(0, 19);
	} while (&locations[index] == currentLocation || locations[index].isHunterExists());
	locations[index].setHunter(hunter);
	hunter->setLocation(&locations[index]);
}

// Display Hunter Information
void displayHunterInfo() {
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	for (TreasureHunter* hunter : hunters) {
		cout << "\n " << hunter->getHunterName() << " is at " << hunter->getLocation()->getLocationName();
	}
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}