#pragma once
#include "Creature.h"

class Monster;

class Player: public Creature
{
private:
	int m_level;

public:
	Player(std::string name = "player", int healthPoint = 10, int powerHit = 1, int gold = 0, int defence = 0,int arms = 0, int level = 1);

	int getLevel() const { return m_level; }

	void levelUp();
	bool hasWon();	
	void reduceGold(int gold);
	void hitPlayer(Monster &monster);
};

