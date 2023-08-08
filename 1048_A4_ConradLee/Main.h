/**************************************************
  Project: The Treasure Caverns of Doom
   Author: Conrad Lee
  Purpose: Main HEADER File
 **************************************************/
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <map>
#include <windows.h>
#include "Dragon.h"
#include "Enums.h"
#include "Item.h"
#include "Location.h"
#include "Monster.h"
#include "Player.h"
#include "TreasureHunter/Gossiper.h"
#include "TreasureHunter/Merchant.h"
#include "TreasureHunter/Ninja.h"


using namespace std;

const int ENTRANCE_INDEX = 0;
const int INNER_RING_BEGIN_INDEX = 15;
const long SLEEP_DURATION = 500;
const int TREASURE_HUNTER_ROAM_PER = 3;

// Difficulty settings
const int ROOKIE_LANTERN_OIL = 600;
const int ADVENTURER_LANTERN_OIL = 500;
const int MASTER_LANTERN_OIL = 400;

const int ROOKIE_INVENTORY_CAPACITY = 14;
const int ADVENTURER_INVENTORY_CAPACITY = 12;
const int MASTER_INVENTORY_CAPACITY = 10;

const int ROOKIE_VICTORY_SCORE = 500;
const int ADVENTURER_VICTORY_SCORE = 1000;
const int MASTER_VICTORY_SCORE = 1500;

// Score settings
const int INITIAL_SCORE = 1000;
const int SCORE_DECAY_PER_TURN = 10;
const int DEFEAT_MONSTER_SCORE_BY_LEVEL[5] = { 10, 50, 100, 200, 500 };

// The monsters that are spawning in the inner ring
MonsterType innerRingMonsters[5] = { MonsterType::Ogre, MonsterType::Ogre, MonsterType::Troll, MonsterType::Troll, MonsterType::Dragon };
// The items that the monsters from the inner ring would carry, excluding the dragon which always carry the tome
ItemObject innerRingNonDragonItems[4] = { ItemObject::Axe, ItemObject::Chainmail, ItemObject::Boots, ItemObject::Elixir };
Location* currentLocation;
Player player;
Location locations[20];
vector<TreasureHunter*> hunters;
bool isGameEnd = false;
int turn = 1;
int killedEpicMonsters = 0;
SkillLevel skillLevel = SkillLevel::Adventurer;
int turnScore = INITIAL_SCORE;
int monsterScore = 0;
int victoryScore = 0;

void displayHowToPlay();
void displayMap();
void selectSkillLevel();
void inputPlayerName();
void initLocations();
void buyItems();
void mainSequence();
void handleMoving();
void combatSequence();
void handleFleeing();
void gameoverByLantern();
void gameoverByMonster(string monsterName);
void examine();
void reduceOil();
void takeItem();
void dropItem();
void drinkPotion();
void advanceTurn();
void handleHuntersMove();
void spawnHunter(TreasureHunter* hunter);
void displayHunterInfo();

#endif