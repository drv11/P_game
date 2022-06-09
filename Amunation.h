#pragma once
#include <vector>
#include <string>

class Player;

class Amunation
{
private:
	std::vector<std::string> m_categoria;
	std::vector<std::string> m_model;
	std::vector<int> m_price;
	std::vector<int> m_sizeModel;
	int m_choiceCategoria;
	int m_choiceModel;
	char m_choiceC;

	enum Categories
	{
		EXIT_C, WEAPON, ARMOR , MEDICINE 
	};

	enum Model
	{
		EXIT_M, LITE , MIDLLE, HARD,  TO_RETURN
	};

public:

	Amunation(std::vector<std::string> categoria = { "Выйти из магазина", "Оружие", "Броню","Аптечку" }, 
		std::vector<std::string> model = { "Выйти из магазина", "Легкую", "Среднюю", "Тяжелую", "Вернуться к выбору категории" },
		std::vector<int> price = { 0,10,20,30,0 }, std::vector <int> sizeModel = {0,1,2,3},
		int choiceCategoria = 0, int choiceModel = 0, char choiceC = 0);
	
	void enterShop(Player& player);
	void selectCategory(Player& player);
	void selectModel(Player& player);
	void pay(Player& player,int level, int price);

	bool inShop();
	void printSelectCategories();
	void printSelectModel();
	void printBuy(int price , Categories categories);
};