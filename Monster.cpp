#include "Monster.h"

Monster::Monster(std::string name, int healthPoint, int powerHit, int gold)
{
	this->m_name = name;	
	this->m_healthPoint = healthPoint;
	this->m_powerHit = powerHit;
	this->m_gold = gold;	
}

void Monster::setMonser(std::string name, int healthPoint, int powerHit, int gold)
{
	m_name = name;	
	m_healthPoint = healthPoint;
	m_powerHit = powerHit;
	m_gold = gold;
}

void Monster::RandomMonster()
{
	int i = getRandomNumber(0, 80);

	if (i > 0 && i < 15)
	{
		i = getRandomNumber(10, 20);
		setMonser("Dragon", i, i / 2, i * 3);		
	}
	else if (i >= 15 && i < 35)
	{
		i = getRandomNumber(2, 6);
		setMonser("Orc", i, i / 2, i * 3);	
	}
	else if (i >= 35 && i < 80)
	{
		i = getRandomNumber(1, 2);
		setMonser("Slime",  i, i/2, i * 3);	
	}
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем генерацию значения из диапазона
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

