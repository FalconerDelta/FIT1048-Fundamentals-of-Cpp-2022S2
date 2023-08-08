/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Item Class File
 **************************************************/
#include "Item.h"

// Constructor
Item::Item() {
	Items itemName = Items::Map;
	ItemTypes itemType = ItemTypes::Item;
	int ItemUses = 0;
	string itemDescription = "";
}

// overloaded constructor, will set if uses == 666 cannot be reduce in the game loop
// "Item Uses" also used as amount for gems/golds
Item::Item(Items itemName) {
	setItemName(itemName);
	switch (itemName) {
	case Items::Map:
		setItemType(ItemTypes::Item);
		setItemUses(666);
		setItemDesciprtion("This is a map");
		break;
	case Items::Lantern:
		setItemType(ItemTypes::Item);
		setItemUses(100);
		setItemDesciprtion("Lights way losing 2-5 points with each move or search action.");
		break;
	case Items::Provisions:
		setItemType(ItemTypes::Item);
		setItemUses(genValue(2,4));
		setItemDesciprtion("restores 5-10 hp");
		break;
	case Items::Gems:
		setItemType(ItemTypes::Item);
		setItemUses(genValue(1,3));
		setItemDesciprtion("1-3 gems when found");
		break;
	case Items::Gold:
		setItemType(ItemTypes::Item);
		setItemUses(genValue(6,12));
		setItemDesciprtion("6-12 golds when found");
		break;
	case Items::Sword:
		setItemType(ItemTypes::Weapon);
		setItemUses(666);
		setItemDesciprtion("+2 damage");
		break;
	case Items::Armour:
		setItemType(ItemTypes::Armour);
		setItemUses(666);
		setItemDesciprtion("+4 defence");
		break;
	case Items::Potion:
		setItemType(ItemTypes::Potion);
		setItemUses(genValue(1,2));
		setItemDesciprtion("+/- 2-4 to one attribute");
		break;
	case Items::Axe:
		setItemType(ItemTypes::Artefact);
		setItemUses(666);
		setItemDesciprtion("+8 damage");
		break;
	case Items::Chainmail:
		setItemType(ItemTypes::Artefact);
		setItemUses(666);
		setItemDesciprtion("+12 defence");
		break;
	case Items::Boots:
		setItemType(ItemTypes::Artefact);
		setItemUses(666);
		setItemDesciprtion("+6 defence");
		break;
	case Items::Elixir:
		setItemType(ItemTypes::Artefact);
		setItemUses(666);
		setItemDesciprtion("Drink and instant game over");
		break;
	case Items::Tome:
		setItemType(ItemTypes::Artefact);
		setItemUses(666);
		setItemDesciprtion("guarded by the Dragon");
		break;
	default:
		Item(Map);
	}
}

// Destructor
Item::~Item() {}

// Accessors
string Item::getItemName() { // return corresponding strings
	switch (itemName) {
	case Items::Map:
		return "Map";
	case Items::Lantern:
		return "Lantern";
	case Items::Provisions:
		return "Provisions";
	case Items::Gems:
		return "Gems";
	case Items::Gold:
		return "Gold";
	case Items::Sword:
		return "Sword";
	case Items::Armour:
		return "Leather Armour";
	case Items::Potion:
		return "Potion Flask";
	case Items::Axe:
		return "Krang's Battle Axe";
	case Items::Chainmail:
		return "Krang's Chainmail";
	case Items::Boots:
		return "Boots of Speed";
	case Items::Elixir:
		return "Elixir Maxima";
	case Items::Tome:
		return "Balthazar's Spell Tome";
	default:
		return "This slot is empty";
	}
}

string Item::getItemType() { // return corresponding strings
	switch (itemName) {
	case Items::Map:
		return "item";
	case Items::Lantern:
		return "item";
	case Items::Provisions:
		return "item";
	case Items::Gems:
		return "item";
	case Items::Gold:
		return "item";
	case Items::Sword:
		return "weapon";
	case Items::Armour:
		return "armour";
	case Items::Potion:
		return "potion";
	case Items::Axe:
		return "artefact";
	case Items::Chainmail:
		return "artefact";
	case Items::Boots:
		return "artefact";
	case Items::Elixir:
		return "artefact";
	case Items::Tome:
		return "artefact";
	default:
		return "This slot is empty";
	}
}

int Item::getItemUses() {
	return itemUses;
}

string Item::getItemDescription() {
	return itemDescription;
}

string Item::getDetails() {
	// returns a formatted string
	stringstream itemDetails;
	itemDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	itemDetails << "\n Item Name  : " << getItemName();
	itemDetails << "\n Item Type  : " << getItemType();
	itemDetails << "\n Remain uses: " << getItemUses();
	itemDetails << "\n Description: " << getItemDescription();
	itemDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return itemDetails.str();
}

// Mutators

void Item::setItemName(Items newItemName) {
	if (newItemName >= Items::Map && newItemName <= Items::Tome) {
		itemName = newItemName;
	}
	else {
		itemName = Items::Map;
	}
}

void Item::setItemType(ItemTypes newType) {
	if (newType >= ItemTypes::Item && newType <= ItemTypes::Artefact) {
		itemType = newType;
	}
	else {
		itemType = ItemTypes::Item;
	}
}

void Item::setItemUses(int uses) {
	if (uses >= 0) {
		itemUses = uses;
	}
	else {
		itemUses = 0;
	}
}

void Item::setItemDesciprtion(string info) {
	if (info != "") {
		itemDescription = info;
	}
	else {
		itemDescription = "";
	}
}

void Item::updateItemUses(int uses) {
	if (itemUses + uses >= 0){
		itemUses += uses;
	}
	else {
		itemUses = 0;
	}
	
}

// Generate number with given range
int Item::genValue(int min, int max) {
	return (rand() % (max - min + 1) + min);
}
