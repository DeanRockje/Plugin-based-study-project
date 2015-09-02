#pragma once
#include <string>
#include "PluginManager.h"
#include "Category.h"
#include <memory>
#include <fstream>
#include <algorithm>
//struct Customer
//{
//	int ID;
//	double _AmmountOfMoney;
//};

class Shop
{
	std::map<Category*, char*> CatgInfo; 
	Shop(const Shop &right);
	double _Money;
	Shop operator = (const Shop &right);
	void createConfigs();
public:
	Shop();
	void AddPlugin();
	void ShowMainMenu();
	//void CustomerInfo();
	void checkChoice(int Choice);
	void ShowAvailableCategories();
	void ShowItemsByCategoy(char *categName);
	~Shop();
};

