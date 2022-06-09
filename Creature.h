#pragma once
#include <iostream>
#include <string>

class Creature
{
protected:
	std::string m_name; //���	
	int m_healthPoint; // ��������
	int m_powerHit; //���� �����
	int m_gold; // ������
	int m_armor; // �����
	int m_weapon; // ������

public:
	
	Creature(std::string name = " " , int healthPoint = 0, int powerHit = 0, int gold = 0, int  armor = 0, int weapon = 0);

	std::string getName() const { return m_name; };
	int getHealthPoint() const { return m_healthPoint; }
	int getPowerHit() const { return m_powerHit; }
	int getGold() const { return m_gold; }
	int getArmor() const { return m_armor; }
	int getWeapon() const { return m_weapon; }

	void setName(std::string name) { m_name = name; }
	void setHealthPoint(int health) { m_healthPoint += health; }
	void setPowerHit(int hit) { m_powerHit = hit; }
	void setGold(int gold)  { m_gold = gold; }
	void setArmor(int arm)  {m_armor = arm; }
	void setWeapon(int weap) { m_weapon = weap; }
	
	void reduceHealth(int health);
	void reduceArmor(int ph);
	bool isDead();
	void addGold(int);
	
	void printShot();
	void printHealthPoint();

};



