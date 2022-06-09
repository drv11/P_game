#include "Arena.h"
#include <cstdlib>
#include <ctime> 


int main()
{
	setlocale(LC_ALL, "Ru");
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат	

	Arena arena;
	arena.welcomeArena();
}