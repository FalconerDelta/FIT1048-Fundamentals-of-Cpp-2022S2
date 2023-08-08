/**************************************************
  Project: The Treasure Caverns of Doom A2
   Author: Conrad Lee
  Purpose: Dragon Class HEADER File
 **************************************************/
#ifndef DRAGONS_H
#define DRAGONS_H
#include "Monster.h"

using namespace std;

class Dragons : public Monster
{

private:
	string dragDescription;
	bool specialSkill;

public:
	// Constructors and Destructor
	Dragons();
	Dragons(string info, bool skillToggle);
	~Dragons();

	// Accessor
	string getDragonDescription();
	bool getSpecialSkillToggle();

	string getDetails();


	// Mutator
	void setDragonDescription(string info);
	void setSpecialSkillToggle(bool toggle);
	void updateSpecialSkillToggle(bool toggle);
	void reflectDmg();

};


#endif
