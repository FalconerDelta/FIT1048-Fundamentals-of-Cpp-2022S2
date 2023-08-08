/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Dragon Class File
 **************************************************/
#include "Dragons.h"

// Constructor
Dragons::Dragons(): Monster(Monsters::Dragon) {
	dragDescription = "This is the final boss. Beware of its special skills.";
	specialSkill = false;
}

// Overload
Dragons::Dragons(string info, bool skillToggle): Monster(Monsters::Dragon) {
	setDragonDescription(info);
	setSpecialSkillToggle(skillToggle);
}


// Destructor
Dragons::~Dragons() {}

// Accessor
string Dragons::getDragonDescription() {
	return dragDescription;
}

bool Dragons::getSpecialSkillToggle() {
	return specialSkill;
}

string Dragons::getDetails() {
	// returns a formatted string
	stringstream dragonDetails;
	dragonDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	dragonDetails << "\n Boss Name       : " << getMonsterName();
	dragonDetails << "\n Boss Level      : " << getMonsterLevel();
	dragonDetails << "\n Boss Health     : " << getMonsterHp();
	dragonDetails << "\n Boss Attack     : " << getMonsterAtk();
	dragonDetails << "\n Boss Defence    : " << getMonsterDef();
	dragonDetails << "\n Boss Damage     : " << getMonsterDmg();
	dragonDetails << "\n Boss Loot Chance: " << getMonsterCarryingChance();
	dragonDetails << "\n Boss Item       : " << getMonsterItem();
	dragonDetails << "\n Boss Description: " << getDragonDescription();
	dragonDetails << "\n Skill Toggle    : " << getSpecialSkillToggle();
	dragonDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return dragonDetails.str();
}

// Mutator
void Dragons::setDragonDescription(string info) {
	if (info != "") {
		dragDescription = info;
	}
	else {
		dragDescription = "This is the final boss. Beware of its special skills.";
	}
}

void Dragons::setSpecialSkillToggle(bool toggle) {
	if (toggle == true || toggle == false) {
		specialSkill = toggle;
	}
	else {
		specialSkill = false;
	}
	reflectDmg();
}

void Dragons::updateSpecialSkillToggle(bool toggle) {
	if (toggle == true || toggle == false) {
		specialSkill = toggle;
	}
	else {
		specialSkill = false;
	}
	reflectDmg();
}

void Dragons::reflectDmg() { // update Monster Damage based on toggle
	if (getSpecialSkillToggle() == true) {
		setMonsterDmg(getMonsterLevel() * genValue(2, 3));
	}
	else {
		setMonsterDmg(getMonsterLevel() + genValue(4, 6));
	}
}