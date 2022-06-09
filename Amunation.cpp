#include "Amunation.h"
#include "Player.h"

Amunation::Amunation(std::vector<std::string> categoria, std::vector<std::string> model,	std::vector<int> price, 
	std::vector <int> sizeModel , int choiceCategoria, int choiceModel, char choiceC)
{	
	this->m_categoria = categoria;
	this->m_model = model;
	this->m_price = price;
	this->m_sizeModel = sizeModel;
	this->m_choiceCategoria = choiceCategoria;
	this->m_choiceModel = choiceModel;
	this->m_choiceC = choiceC;
}

void Amunation::enterShop(Player& player)
{
	while(inShop())
	{
		selectCategory(player);
	}
}

void Amunation::selectCategory(Player& player)
{
	printSelectCategories();

	switch (static_cast<Categories>(m_choiceCategoria))
	{
	case Amunation::EXIT_C:
		break;
	case Amunation::WEAPON:
		selectModel(player);
		break;
	case Amunation::ARMOR:
		selectModel(player);
		break;
	case Amunation::MEDICINE:
		selectModel(player);
		break;
	default:
		break;
	}	
}

void Amunation::selectModel(Player& player)
{
	printSelectModel();

	switch (static_cast<Model>(m_choiceModel))
	{
	case Amunation::EXIT_M:
		break;
	case Amunation::LITE:
		pay(player, m_sizeModel[LITE], m_price[LITE]);
		break;
	case Amunation::MIDLLE:
		pay(player, m_sizeModel[MIDLLE], m_price[MIDLLE]);
		break;
	case Amunation::HARD:
		pay(player, m_sizeModel[HARD], m_price[HARD]);
		break;
	case Amunation::TO_RETURN:
		selectCategory(player);
		break;
	default:
		break;
	}
}

void Amunation::pay(Player& player, int model, int price)
{
	if (player.getGold() >= price)
	{
		if (m_choiceCategoria == Categories::WEAPON)
		{
			player.setWeapon(model);
			player.reduceGold(price);
			printBuy(price, WEAPON);
		}
		else if (m_choiceCategoria == Categories::ARMOR)
		{
			player.setArmor(model);
			player.reduceGold(price);
			printBuy(price, ARMOR);
		}
		else if (m_choiceCategoria == Categories::MEDICINE)
		{
			player.setHealthPoint(model);
			player.reduceGold(price);
			printBuy(price, MEDICINE);
		}
	}	
	else	
		std::cout << "Недостаточно золота \n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;	
}

bool Amunation::inShop()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Хотите посетить торговца?\n" << "Да(Y) Нет(N): ";
	std::cin >> m_choiceC;

	while (m_choiceC != 'y' && m_choiceC != 'Y' && m_choiceC != 'n' && m_choiceC != 'N')
	{
		std::cout << "Ведите (Y) или (N): ";
		std::cin >> m_choiceC;
	}

	if (m_choiceC == 'Y' || m_choiceC == 'y')
		return true;
	else
	{
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		return false;
	}	
}

void Amunation::printSelectCategories()
{
	std::cout << "\nЧто хотите купить?\n";
	for (int i = 0; i < m_categoria.size(); ++i)
	{
		std::cout << i << ". " << m_categoria[i] << std::endl;
	}
	std::cout << "Ответ: ";
	std::cin >> m_choiceCategoria;

	while (m_choiceCategoria > 0 && m_choiceCategoria > 4)
	{
		std::cout << "Выберите категорию: ";
		std::cin >> m_choiceCategoria;
	}
}

void Amunation::printSelectModel()
{
	std::cout << "\nКакую модель хотите купить? \n";

	for (int i = 0; i < m_model.size(); ++i)
	{
		std::cout << i << ". " << m_model[i];

		if (i > 0 && i < 4)		
			std::cout << " (" << m_price[i] << " Золотых) " << " (+" << m_sizeModel[i] << " к показателям)" << std::endl;
		else
			std::cout << std::endl;		
	}

	std::cout << "Ответ: ";
	std::cin >> m_choiceModel;

	while (m_choiceModel > 0 && m_choiceModel > 4 )
	{
		std::cout << "Выберите модель: ";
		std::cin >> m_choiceModel;
	}
}

void Amunation::printBuy(int price, Categories categories)
{
	std::cout << "Вы купили " << m_categoria[categories] << " за " << price << " золотых." << "\n";	
}