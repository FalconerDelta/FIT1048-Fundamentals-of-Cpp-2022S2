/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Dragon Class HEADER File
 **************************************************/
#ifndef DRAGON_H
#define DRAGON_H
#include "Monster.h"

using namespace std;

class Dragon : public Monster {

private:
	bool specialSkillUsed;

public:
	// Constructors and Destructor
	Dragon();
	~Dragon();

	int getMonsterDmg() override;

};


#endif
