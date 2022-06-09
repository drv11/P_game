#include "Console.h"

Console::Console(char choice)
{
	this->m_choice = choice;
	
}

std::string Console::inputNamePlayer()
{		
	std::string yourName; //��� ������
	std::cout << "������� ���� ���: ";
	std::cin >> yourName;	
	return yourName;
}

void Console::printWelcome(std::string name)
{
	std::cout << "����� ���������� " << name << std::endl;	
}

void Console::printInsruction()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ���������� ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "�� ��������� � ��� ��������!\n";
	std::cout << "��� ���� ��� �� ������, ��� ���������� �� �������.\n";
	std::cout << "���� ����� ������ ����� ����������� ������.\n";
	std::cout << "� ������� ������� ������� ��� ����� �������� ������. �� ���������� �������� �� ������ ������ ������ � ��������.\n";
	std::cout << "����� ���������� ���������� ������ ��� ���������� ����� 5 Slime ��� 2 Orc. ���� ���������� ����� ������������ Dragon.\n";
	std::cout << "��� ������ ���������� ���������� 20 ������! ������ �����!\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void Console::printTopGamer()
{
	std::cout << "===================== ������ ������ ===================== \n";
	readRecord();
	std::cout << "========================================================= \n";
}

void Console::printKillM(std::string nameMonster)
{
	std::cout << "�� ����� " << nameMonster << " � ��������� ��� ������" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Console::printLevelUp(int level)
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "��� ������� �������! ��� �������: " << level << std::endl;	
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Console::printWin(int level, int gold, int count)
{
	std::cout << "========================================================================" << std::endl;
	std::cout << "�� ��������! ��� �������: " << level << ". ���� ������: " << gold;
	std::cout << " �� ����� " << count << " ��������." << std::endl;
	std::cout << "========================================================================" << std::endl;
}

void Console::printLose(int level, int gold, int count)
{
	std::cout << "========================================================================" << std::endl;
	std::cout << "�� ���������! �� �������� " << level << " ������. C������ " << gold << " ������";
	std::cout << " � ����� " << count << " ��������." << std::endl;
	std::cout << "========================================================================" << std::endl;
}

void Console::printMeet(std::string name, int healthPoint)
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "�� ��������� " << name << " (" << healthPoint << " HP)" << "\n";
}

void Console::printEsc()
{
	std::cout << "�� ������� �������" << std::endl;	
}

void Console::printNoEsc()
{
	std::cout << "������� �� �������. ";
}

void Console::choice()
{
	std::cout << "����������� �������(R) ��� �������(F): ";
	std::cin >> m_choice;	
	while (m_choice != 'R' && m_choice != 'r' && m_choice != 'F' && m_choice != 'f')
	{
		std::cout << "������ (R) ��� (F): ";
		std::cin >> m_choice;
	}
}

void Console::printIndicators(int gold, int healthPoint, int armor,int powerHit, int weapon)
{
	std::cout <<"���� ������: " <<gold;
	std::cout << ".\n��������: " << healthPoint << " HP. �����: " << armor;
	std::cout << " ���� �����: " <<powerHit << ". ����� � �����: " << weapon << std::endl;
}

void Console::writeRecord(std::string name, int count)
{
	std::ofstream wRecord;
	wRecord.open("Record.txt", std::ios_base::app);
	if (wRecord.is_open())
	{
		wRecord << name << " ���� " << count << "-x  ��������." << std::endl;
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






