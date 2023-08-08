/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Item Class File
 **************************************************/
#include "Item.h"
#include "Item/Map.h"
#include "Item/Lantern.h"
#include "Item/Provisions.h"
#include "Item/Gems.h"
#include "Item/Gold.h"
#include "Item/Sword.h"
#include "Item/Armour.h"
#include "Item/Potion.h"
#include "Item/Axe.h"
#include "Item/Chainmail.h"
#include "Item/Boots.h"
#include "Item/Elixir.h"
#include "Item/Tome.h"
#include "Item/Gloves.h"
#include "Item/Necklace.h"
#include "Player.h"

// Constructor
Item::Item() {
	setItemObject(ItemObject::Map);
	setItemType(ItemType::Item);
	setItemUses(0);
}

// Destructor
Item::~Item() {}

void Item::useItem() {}

// Call the derived classes according to the ItemObject
Item* Item::initNewItem(ItemObject itemName) {
	switch (itemName) {
	case ItemObject::Map:
	{
		return new Map;
	}
	case ItemObject::Lantern:
	{
		return new Lantern;
	}
	case ItemObject::Provisions:
	{
		return new Provisions;
	}
	case ItemObject::Gems:
	{
		return new Gems;
	}
	case ItemObject::Gold:
	{
		return new Gold;
	}
	case ItemObject::Sword:
	{
		return new Sword;
	}
	case ItemObject::Armour:
	{
		return new Armour;
	}
	case ItemObject::Potion:
	{
		return new Potion;
	}
	case ItemObject::Axe:
	{
		return new Axe;
	}
	case ItemObject::Chainmail:
	{
		return new Chainmail;
	}
	case ItemObject::Boots:
	{
		return new Boots;
	}
	case ItemObject::Elixir:
	{
		return new Elixir;
	}
	case ItemObject::Tome:
	{
		return new Tome;
	}
	case ItemObject::Gloves:
	{
		return new Gloves;
	}
	case ItemObject::Necklace:
	{
		return new Necklace;
	}
	default:
	{
		return new Map;
	}
	}
}

Item* Item::genRandomItem() {
	int size = sizeof(generatableItems) / sizeof(generatableItems[0]);
	int value = Helper::genValue(1, size + 2);
	for (int i = 1; i <= size + 2; i++) {
		if (value == i && value <= size) {
			return initNewItem(generatableItems[i-1]);
		}
		else {
			if (i == size + 1) {
				return initNewItem(ItemObject::Gems);
			}
			else if (i == size + 2) {
				return initNewItem(ItemObject::Gold);
			}
		}
	}
	return initNewItem(ItemObject::Gold);
}

Item* Item::genRandomItemExcludingGemsAndGold() {
	int size = sizeof(generatableItems) / sizeof(generatableItems[0]);
	int value = Helper::genValue(1, size);
	for (int i = 1; i <= size; i++) {
		if (value == i && value <= size) {
			return initNewItem(generatableItems[i-1]);
		}
	}
	return initNewItem(generatableItems[0]);
}

Item* Item::genGemsOrGold() {
	int value = Helper::genValue(1, 2);
	switch (value) {
	case 1:
		return initNewItem(ItemObject::Gems);
	case 2:
		return initNewItem(ItemObject::Gold);
	default:
		return initNewItem(ItemObject::Gold);
	}
}

// Accessors
string Item::getItemName() {
	if (itemUses > 1) {
		return itemName + " (" + to_string(itemUses) + ")";
	}
	return itemName;
}

ItemObject Item::getItemObject() {
	return itemObject;
}

ItemType Item::getItemType() {
	return itemType;
}

string Item::getItemTypeString() {
	switch (itemType) {
	case ItemType::Item:
		return "Item";
		break;
	case ItemType::Weapon:
		return "Weapon";
		break;
	case ItemType::Armour:
		return "Armour";
		break;
	case ItemType::Potion:
		return "Potion";
		break;
	case ItemType::Artefact:
		return "Artefact";
		break;
	}
	return "";
}

int Item::getItemUses() {
	return itemUses;
}

string Item::getItemDescription() {
	return itemDescription;
}

bool Item::isPotion() {
	return potion;
}

bool Item::isDroppable() {
	return droppable;
}

string Item::getDetails() {
	// returns a formatted string
	stringstream itemDetails;
	itemDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	itemDetails << "\n Item Name  : " << getItemName();
	itemDetails << "\n Item Type  : " << getItemTypeString();
	itemDetails << "\n Remain uses: " << getItemUses();
	itemDetails << "\n Description: " << getItemDescription();
	itemDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return itemDetails.str();
}

void Item::setItemName(string itemName) {
	this->itemName = itemName;
}

void Item::setItemObject(ItemObject itemObject) {
	this->itemObject = itemObject;
}

void Item::setItemType(ItemType itemType) {
	this->itemType = itemType;
}

void Item::setItemUses(int itemUses) {
	this->itemUses = itemUses;
}

void Item::updateItemUses(int uses) {
	itemUses += uses;
	if (itemUses < 0) {
		itemUses = 0;
	}
}

void Item::dropItemUses(Player* player, int uses) {
	updateItemUses(uses);
	onDrop(player, uses);
}

void Item::setItemDescription(string itemDescription) {
	this->itemDescription = itemDescription;
}

void Item::setIsPotion(bool isPotion) {
	this->potion = isPotion;
}

void Item::setIsDroppable(bool isDroppable) {
	this->droppable = isDroppable;
}