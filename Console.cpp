#include "Console.h"

Console::Console(char choice)
{
	this->m_choice = choice;
	
}

std::string Console::inputNamePlayer()
{		
	std::string yourName; //имя игрока
	std::cout << "Введите ваше имя: ";
	std::cin >> yourName;	
	return yourName;
}

void Console::printWelcome(std::string name)
{
	std::cout << "Добро пожаловать " << name << std::endl;	
}

void Console::printInsruction()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ИНСТРУКЦИЯ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Вы попадаете в мир монстров!\n";
	std::cout << "Для того что бы выжить, Вам необходимо их убивать.\n";
	std::cout << "Сила удара игрока равна полученному уровню.\n";
	std::cout << "С каждого убитого монстра Вам будет выпадать золото. На полученные средства Вы можите купить товары у торговца.\n";
	std::cout << "Чтобы достигнуть следующего уровня Вам необходимо убить 5 Slime или 2 Orc. Либо попробуйте убить легендарного Dragon.\n";
	std::cout << "Для победы необходимо достигнуть 20 уровня! Хахаха Удачи!\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void Console::printTopGamer()
{
	std::cout << "===================== Лучшие игроки ===================== \n";
	readRecord();
	std::cout << "========================================================= \n";
}

void Console::printKillM(std::string nameMonster)
{
	std::cout << "Вы убили " << nameMonster << " и забираете его золото" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Console::printLevelUp(int level)
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Ваш уровень повышен! Ваш уровень: " << level << std::endl;	
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Console::printWin(int level, int gold, int count)
{
	std::cout << "========================================================================" << std::endl;
	std::cout << "Вы выиграли! Ваш уровень: " << level << ". Ваше золото: " << gold;
	std::cout << " Вы убили " << count << " монстров." << std::endl;
	std::cout << "========================================================================" << std::endl;
}

void Console::printLose(int level, int gold, int count)
{
	std::cout << "========================================================================" << std::endl;
	std::cout << "Вы проиграли! Вы достигли " << level << " уровня. Cобрали " << gold << " золота";
	std::cout << " и убили " << count << " монстров." << std::endl;
	std::cout << "========================================================================" << std::endl;
}

void Console::printMeet(std::string name, int healthPoint)
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Вы встретили " << name << " (" << healthPoint << " HP)" << "\n";
}

void Console::printEsc()
{
	std::cout << "Вы успешно сбежали" << std::endl;	
}

void Console::printNoEsc()
{
	std::cout << "Сбежать не удалось. ";
}

void Console::choice()
{
	std::cout << "Попробовать сбежать(R) или ударить(F): ";
	std::cin >> m_choice;	
	while (m_choice != 'R' && m_choice != 'r' && m_choice != 'F' && m_choice != 'f')
	{
		std::cout << "Ведите (R) или (F): ";
		std::cin >> m_choice;
	}
}

void Console::printIndicators(int gold, int healthPoint, int armor,int powerHit, int weapon)
{
	std::cout <<"Ваше золото: " <<gold;
	std::cout << ".\nЗдоровье: " << healthPoint << " HP. Броня: " << armor;
	std::cout << " Сила удара: " <<powerHit << ". Бонус к удару: " << weapon << std::endl;
}

void Console::writeRecord(std::string name, int count)
{
	std::ofstream wRecord;
	wRecord.open("Record.txt", std::ios_base::app);
	if (wRecord.is_open())
	{
		wRecord << name << " убил " << count << "-x  монстров." << std::endl;
		wRecord.close();
	}
}

void Console::readRecord()
{
	std::ifstream rRecord;
	rRecord.open("Record.txt", std::ios_base::in);
	if (rRecord.is_open())
	{
		std::string str;
		while (rRecord.good())
		{
			std::getline(rRecord, str);
			std::cout << str << std::endl;
		}
		rRecord.close();
	}
}






