#pragma once
#include "Player.h"
#include "Monster.h"
#include <fstream>

class Console
{
private:		
	char m_choice; // выбор действия		
public:

	Console(char choice = 0);

	char getChoice() const { return m_choice; }	

	std::string inputNamePlayer();
	void printWelcome(std::string name);
	void printInsruction();
	void printTopGamer();
	void printKillM(std::string nameMonster);
	void printLevelUp(int level);
	void printWin(int level, int gold, int count);
	void printLose(int level, int gold, int count);
	void printMeet(std::string name, int healthPoint);
	void printEsc();
	void printNoEsc();
	void choice();
	void writeRecord(std::string name, int count);
	void printIndicators(int gold, int healthPoint, int armor, int powerHit, int weapon);
	void readRecord();

};

