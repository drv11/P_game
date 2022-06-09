#include "Player.h"
#include "Monster.h"

Player::Player(std::string name, int healthPoint, int powerHit, int gold, int defence, int arms, int level)
	:Creature(name, healthPoint, powerHit, gold, defence, arms)
{		
	this->m_level = level;
}
void Player::levelUp()
{
	m_level++;
	m_powerHit++;
}

bool Player::hasWon()
{
	return m_level >= 20;
}

void Player::reduceGold(int gold)
{
	m_gold -= gold;
}

void Player::hitPlayer(Monster& monster)
{
	monster.reduceHealth(m_powerHit + m_weapon);	 
}

