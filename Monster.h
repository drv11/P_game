#pragma once
#include "Creature.h"

class Monster: public Creature
{
public:
	Monster(std::string name = "monster", int healthPoint = 0, int powerHit = 0, int gold = 0);	
	void setMonser(std::string name, int healthPoint, int powerHit, int gold);
	void RandomMonster();
};
int getRandomNumber(int min, int max);
