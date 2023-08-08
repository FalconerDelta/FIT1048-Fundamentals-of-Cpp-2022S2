/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Merchant Class File
 **************************************************/
#include "Merchant.h"
#include "../Player.h"

 // Constructor
Merchant::Merchant() : TreasureHunter() {
	setHunterType(TreasureHunterType::Merchant);
	setHunterName("Merchant");
}

// Destructor
Merchant::~Merchant() {}

// Interaction with Merchant
void Merchant::encounter(Player* player) {
	bool boughtSomething = false;
	char letter;
	do {
		Helper::clearScreen();
		cout << "You encountered a merchant on a new turn!" << endl;
		cout << "Merchant: I have infinity supplies of gears for you hero to equip." << endl;
		cout << "          However the more you buy, the more the price would go up." << endl;
		cout << "          This is just how the magical world works." << endl;
		cout << "You now have " << player->getItemUses(ItemObject::Gold) << " golds" << endl;
		cout << player->getDetails();
		vector<char> acceptedCommands{'A', 'S', 'G', 'N', 'L', 'X'};
		int gems = player->getItemUses(ItemObject::Gems);
		// Allow player to convert all the gems into golds
		// This is the only way the gems could be used
		if (gems > 0) {
			cout << "[C]: Convert " << gems << " gems into " << gems * 10 << " golds" << endl;
			acceptedCommands.push_back('C');
		}
		cout << "[A]: Pay " << armourPrice << " golds to buy a leather armour" << endl;
		cout << "[S]: Pay " << swordPrice << " golds to buy a sword" << endl;
		cout << "[G]: Pay " << glovesPrice << " golds to buy leather gloves" << endl;
		cout << "[N]: Pay " << necklacePrice << " golds to buy a necklace" << endl;
		cout << "[L]: Pay " << lanternPrice << " golds to buy 50 units of lantern oil" << endl;
		cout << "[X]: Leave" << endl;
		letter = Helper::inputLetter(acceptedCommands, "Select your option: ");
		if (letter == 'X') {
			continue;
		}
		if (letter == 'C') {
			player->updateItemUses(ItemObject::Gems, -gems);
			player->updateItemUses(ItemObject::Gold, gems * 10);
			continue;
		}
		int price;
		ItemObject buyingItem;
		switch (letter) {
			case 'A':
				buyingItem = ItemObject::Armour;
				price = armourPrice;
				break;
			case 'S':
				buyingItem = ItemObject::Sword;
				price = swordPrice;
				break;
			case 'G':
				buyingItem = ItemObject::Gloves;
				price = glovesPrice;
				break;
			case 'N':
				buyingItem = ItemObject::Necklace;
				price = necklacePrice;
				break;
			case 'L':
			default:
				buyingItem = ItemObject::Lantern;
				price = lanternPrice;
				break;
		}
		if (player->getItemUses(ItemObject::Gold) < price) {
			cout << "You do not have enough golds!" << endl;
		}
		else {
			// If is buying lantern, add oil
			if (buyingItem == ItemObject::Lantern) {
				boughtSomething = true;
				player->updateItemUses(ItemObject::Gold, -price);
				player->updateItemUses(ItemObject::Lantern, 50);
				cout << "Lantern oil increased by 50." << endl;
				increasePrices();
			}
			else {
				if (player->addItemToInventory(Item::initNewItem(buyingItem))) {
					boughtSomething = true;
					player->updateItemUses(ItemObject::Gold, -price);
					increasePrices();
				}
				else {
					cout << "But your inventory is full!" << endl;
				}
			}
		}
		Helper::waitForKeyPress();
	} while (letter != 'X' && letter != 'x');
	if (boughtSomething) {
		cout << "Thank you for purchases!" << endl;
	}
	else {
		cout << "You will regret for not buying equipments from me!" << endl;
	}
}

// The increase the prices of all items after each purchase
void Merchant::increasePrices() {
	armourPrice += 5;
	swordPrice += 5;
	glovesPrice += 5;
	necklacePrice += 5;
	lanternPrice += 5;
}