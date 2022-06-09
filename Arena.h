#pragma once
#include "Player.h"
#include "Monster.h"
#include "Console.h"
#include "Amunation.h"

class Arena
{
private:
	Player m_player;
	Monster m_monster;
	Console m_console;
	Amunation m_amunation;

	int m_countSlime;
	int m_countOrc;
	int m_countDragon;
	int m_countCommon;
	int  m_lucky; // успех побега

public:

	Arena(int  lucky = 0, int countSlime = 0, int countOrc = 0, int countDragon = 0, int count = 0);

	int getCountCommon() { return m_countCommon; }

	void addCountSlime() { m_countSlime++; }
	void addCountOrc() { m_countOrc++; }
	void addCountDragon() { m_countDragon++; }

	void welcomeArena();
	void figth();
	void attackP();
	void attackM();
	void countMonster();
	bool isCount();
};