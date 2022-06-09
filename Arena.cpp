#include "Arena.h"

Arena::Arena(int lucky, int countSlime, int countOrc, int countDragon, int count)
{
	Player player;
	Monster monster;
	Console console;
	Amunation amunation;

	this->m_console = console;
	this->m_player = player;
	this->m_monster = monster;
	this->m_amunation = amunation;	
	this->m_lucky = lucky;	
	this->m_countSlime = countSlime;
	this->m_countOrc = countOrc;
	this->m_countDragon = countDragon;
}

void Arena::welcomeArena()
{
	m_console.printInsruction();
	m_console.printTopGamer();
	m_player.setName(m_console.inputNamePlayer());	
	m_console.printWelcome(m_player.getName());
	m_console.printIndicators(m_player.getGold(),m_player.getHealthPoint(),m_player.getArmor(),m_player.getPowerHit(),m_player.getWeapon());

	while (!m_player.isDead() && !m_player.hasWon())
	{		
		m_monster.RandomMonster();
		m_console.printMeet(m_monster.getName(), m_monster.getHealthPoint());
		figth();
	}
}

void Arena::figth()
{
	while (!m_monster.isDead() && !m_player.isDead())
	{
		m_console.choice();
		m_lucky = getRandomNumber(0, 1);

		if ((m_console.getChoice() == 'R' || m_console.getChoice() == 'r') && m_lucky == 1)
		{
			m_console.printEsc();
			break;
		}
		else if (m_console.getChoice() == 'F' || m_console.getChoice() == 'f')
			attackP();
		else
		{
			m_console.printNoEsc();
			attackM();
		}
	}	
}

void Arena::attackP() // атака игроком
{
	m_player.printShot();		
	m_player.hitPlayer(m_monster); //монстр получает урон 	
	m_monster.printHealthPoint();

	if (m_monster.isDead())
	{
		m_console.printKillM(m_monster.getName());
		m_player.addGold(m_monster.getGold());
		countMonster();

		if (isCount())
		{
			m_player.levelUp();
			m_console.printLevelUp(m_player.getLevel());
		}
		m_console.printIndicators(m_player.getGold(), m_player.getHealthPoint(), m_player.getArmor(), m_player.getPowerHit(), m_player.getWeapon());
		m_amunation.enterShop(m_player);
		m_console.printIndicators(m_player.getGold(), m_player.getHealthPoint(), m_player.getArmor(), m_player.getPowerHit(), m_player.getWeapon());		

		if (m_player.hasWon())
		{
			m_console.printWin(m_player.getLevel(),m_player.getGold(), m_countCommon);
			m_console.writeRecord(m_player.getName(), m_countCommon);
		}
	}
	else
		attackM();	
}

void  Arena::attackM() // јтака монстра
{
	m_monster.printShot();

	if (m_player.getArmor() > 0)
	{
		m_player.reduceHealth(m_monster.getPowerHit() - m_player.getArmor());
		m_player.reduceArmor(m_player.getArmor());
	}
	else
		m_player.reduceHealth(m_monster.getPowerHit());	

	m_player.printHealthPoint();

	if (m_player.isDead())	
		m_console.printLose(m_player.getLevel(), m_player.getGold(), m_countCommon);
}

void  Arena::countMonster()
{
	if (m_monster.getName() == "Dragon")
		addCountDragon();
	else if (m_monster.getName() == "Orc")
		addCountOrc();
	else if (m_monster.getName() == "Slime")
		addCountSlime();
}

bool Arena::isCount()
{
	m_countCommon++;
	if (m_countSlime == 5)
	{
		m_countSlime = 0;
		return true;
	}
	else if (m_countOrc == 2)
	{
		m_countOrc = 0;
		return true;
	}
	else if (m_countDragon == 1)
	{
		m_countDragon = 0;
		return true;
	}
	else
		return false;
}