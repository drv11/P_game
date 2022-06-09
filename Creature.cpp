#include "Creature.h"

Creature::Creature(std::string name, int healthPoint, int powerHit, int gold, int  armor, int weapon)
{
	this->m_name = name;
	this->m_healthPoint = healthPoint;
	this->m_powerHit = powerHit;
	this->m_gold = gold;
	this->m_armor = armor;
	this->m_weapon = weapon;
}

void Creature::reduceHealth(int health)
{
	m_healthPoint -= health;
}

void Creature::reduceArmor(int ph)
{
	m_armor -= ph;
}

bool Creature::isDead()
{
	return m_healthPoint <=  0;
}

void Creature::addGold(int gold)
{
	m_gold += gold;
}

void Creature::printShot()
{
	std::cout << m_name << " наносит удар! На " << m_powerHit + m_weapon << " HP.";
}
void Creature::printHealthPoint()
{
	std::cout << " У " << m_name << " осталось " << m_healthPoint << " HP." << std::endl;
}