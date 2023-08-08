/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Classes testing for A2
 **************************************************/
#include "Main.h"

int main() {
	
	// seed random
	srand(unsigned(time(nullptr)));

	// Item Class section
	cout << "\nVVV Item Class VVV";
	testItem();
	cout << "\n\n\n";
	system("pause");

	// Monster Class section
	cout << "\nVVV Monster Class VVV";
	testMonster();
	cout << "\n\n\n";
	system("pause");

	// Dragon Class section
	cout << "\nVVV Dragon Class VVV";
	testDragon();
	cout << "\n\n\n";
	system("pause");

	// Player Class section
	cout << "\nVVV Player Class VVV";
	testPlayer();
	cout << "\n\n\n";
	system("pause");

	// Location Class section
	cout << "\nVVV Location Class VVV";
	testLocation();
	cout << "\n\n\n";

	// End note
	cout << "End of Testing\n\n";
	// pause
	system("pause");

	//did not use system clear so result will not get cleared
}

void testPlayer() {
	// create new Player
	Player newPlayer01;
	newPlayer01.setPlayerHp(50);
	newPlayer01.setPlayerAtk(newPlayer01.getPlayerHp() / 6);
	newPlayer01.addItemToInventory(Items::Gold);
	cout << newPlayer01.getDetails();

	// test mutator
	newPlayer01.updatePlayerLuck(+3);
	newPlayer01.updatePlayerHp(-5);
	newPlayer01.deleteItemFromInventory("Provisions", true);
	cout << newPlayer01.getDetails();

	// test overload
	Player newPlayer02("Tutor", Items::Tome);
	cout << newPlayer02.getDetails();
}


void testMonster() {
	// create new Monster
	Monster newMonster01;
	newMonster01.setMonsterName(Monsters::Hobgoblin);
	newMonster01.setMonsterHp(5);
	newMonster01.setMonsterAtk(1);
	newMonster01.setMonsterDef(1);
	newMonster01.setMonsterDmg(1);
	newMonster01.setMonsterCarryingChance(1);
	newMonster01.setMonsterItem("Leather Armour");
	cout << newMonster01.getDetails();

	// test mutator
	newMonster01.updateMonsterHp(-2);
	cout << newMonster01.getDetails();

	// test overload
	Monster newMonster02(Monsters::Troll);
	cout << newMonster02.getDetails();

}


void testDragon() {
	// create new Dragon
	Dragons newDragon01;
	newDragon01.setDragonDescription("");
	newDragon01.setSpecialSkillToggle(true);
	cout << newDragon01.getDetails();

	// test mutator
	newDragon01.updateSpecialSkillToggle(false);
	cout << newDragon01.getDetails();

	// test overload
	Dragons newDragon02("random Description", false);
	cout << newDragon02.getDetails();

	
}


void testItem() {
	// create new item
	Item newItem01;
	newItem01.setItemName(Items::Provisions);
	newItem01.setItemType(ItemTypes::Item);
	newItem01.setItemUses(rand() % 3 + 2);
	newItem01.setItemDesciprtion("restores 5-10 hp");
	cout << newItem01.getDetails();

	// test mutator
	newItem01.updateItemUses(-1);
	cout << newItem01.getDetails();

	// test overload
	Item newItem02(Items::Potion);
	cout << newItem02.getDetails();

}


void testLocation() {
	// create new Location
	Location newLocation01;
	newLocation01.setLocationName("No Guardian Here Room");
	newLocation01.setLocationDescription("Def not Danagerous");
	newLocation01.setItem(Items::Gold);
	newLocation01.setMonster(Monsters::Hobgoblin);
	int temp[3] = { 18,11,20 };
	newLocation01.setExits(temp);
	cout << newLocation01.getDetails();

	// test mutator
	newLocation01.updateMonsterStats(Monsters::Ogre);
	newLocation01.updatePlayerExist(true);
	cout << newLocation01.getDetails();

	// test overload
	Location newLocation02("Twin Overwatch");
	cout << newLocation02.getDetails();
}
