/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Gossiper Class File
 **************************************************/
#include "Gossiper.h"
#include "../Player.h"

// Constructor
Gossiper::Gossiper() : TreasureHunter() {
	setHunterType(TreasureHunterType::Gossiper);
	setHunterName("Gossiper");
	random_shuffle(gossips.begin(), gossips.end());
}

// Destructor
Gossiper::~Gossiper() {}

// Interaction with Gossiper
void Gossiper::encounter(Player* player) {
	cout << "You encountered a gossiper on a new turn!" << endl;
	if (gossips.size() == 0) {
		// If there are no gossips, the gossiper would give money to the player
		if (!moneyGiven) {
			cout << "Gossiper: You again? I have no more secrets to tell you!" << endl;
			cout << "          Thanks for your supports, here are some money for you!" << endl;
			player->updateItemUses(ItemObject::Gold, Helper::genValue(40, 60));
			moneyGiven = true;
		}
		// If money has already been given, the gossiper will ignore the player forever
		else {
			cout << "You saw the gossiper whispering to another hero far away." << endl;
			cout << "You decided not to bother them." << endl;
		}
	}
	else {
		// Allow the player to pay 5 golds to get one gossip
		cout << "Gossiper: I know a lot of secrets about this cavern!" << endl;
		cout << "          Give me 5 golds and I will tell you one of them." << endl;
		if (player->getItemUses(ItemObject::Gold) <= 5) {
			cout << "          But seems like you do not have enough golds. Shame." << endl;
		}
		else {
			cout << "You now have " << player->getItemUses(ItemObject::Gold) << " golds" << endl;
			vector<char> acceptedCommands{ '1', '2' };
			cout << "[1]: Pay 5 golds to learn about a secret" << endl;
			cout << "[2]: Ignore him" << endl;
			switch (Helper::inputLetter(acceptedCommands, "Select your option: ")) {
			case '1':
				player->updateItemUses(ItemObject::Gold, -5);
				cout << gossips[gossips.size() - 1] << endl;
				cout << "Now go away! I have works to do." << endl;
				gossips.pop_back();
				break;
			case '2':
				cout << "Gossiper: Fine, I will tell someone else then." << endl;
				break;
			}
		}
	}
}