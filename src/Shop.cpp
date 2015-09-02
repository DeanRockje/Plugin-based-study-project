#include "Shop.h"


Shop::Shop()
{
	IO::Print("Shop Constructor", 1);
	wchar_t* str = L"Plugins//";
	PluginManager::getInstance()->SetPath(str);
	createConfigs();
	Category *cat = new Category(PluginManager::getInstance()->getFactory());
	if(cat)
	{
		char* name = PluginManager::getInstance()->getName();
		CatgInfo.emplace(cat, name);
	}
}


void Shop::createConfigs()
{
	std::ofstream toFile;
	std::ifstream out("config.txt");
	if(!out)
	{
		   toFile.open("config.txt", std::ios_base::binary);
			IO::Print("Sum of MONEY in shop cash desk: ");
			double money = IO::getDouble();
			toFile << money;
	}
	else if(out && out.peek() == std::ifstream::traits_type::eof())
		{
			toFile.open("config.txt", std::ios_base::binary);
			IO::Print("Sum of MONEY in shop cash desk: ");
			double money = IO::getDouble();
			toFile << money;
		}
		else
		{
			double money = 0;
			out >> money;
			_Money = money;
		}

}

void Shop::ShowMainMenu()
{
	IO::Print("Shop cash: ");
	IO::Print(_Money);
	int Input;
	IO::Print("\n\n");
	IO::Print("\t---------------------------------------------------", 1);
	IO::Print("\t|1. Show Categories Goods                         |", 1);
	IO::Print("\t|2. Show Categories                               |", 1);
	IO::Print("\t|3. Show Items                                    |", 1);
	IO::Print("\t|4. Quit                                          |", 1);
	IO::Print("\t---------------------------------------------------", 1);
	IO::Print("\t\tEnter Menu Item ----> ");
	Input = IO::getInt();
	checkChoice(Input);
}

void Shop::ShowAvailableCategories()
{
	system("cls");
	IO::Print("Available Categories: ",1);
	std::string RetWord = "Return";
	for(auto it = CatgInfo.begin(); it!=CatgInfo.end(); ++it)
	{
		IO::Print(it->second);
		IO::Print("\n");
	}
	IO::Print("To return to main menu enter [Return]\n");
	IO::Print("---> ");
	std::string in = IO::getString();
	while(!(in == RetWord))
	{
		IO::Print("---> ");
		in = IO::getString();
	}
	ShowMainMenu();
}

void Shop::checkChoice(int Choice)
{
	switch (Choice)
	{
	case 1:
		{
				system("cls");
			    std::string name;
				IO::Print("Enter category name: ");
				name = IO::getString();
				char *cName = new char[name.length()+1];
				std::strcpy(cName,name.c_str());
				ShowItemsByCategoy(cName);
		}
		break;
	case 2:
		ShowAvailableCategories();
		break;
	case 3:
		IO::Print("Category->ShowGoods");
		break;
	case 4:
		return;
		break;
	default:
		IO::Print("Error![1..4] available positions", 1);
	}
}


void Shop::ShowItemsByCategoy(char *categname)
{
	for(auto it = CatgInfo.begin(); it!= CatgInfo.end(); ++it)
	{
		if(strcmp(it->second,categname)==0)
		{
			IO::Print("All items associated with category: ");
			IO::Print(it->second);
			it->first->pOut->ShowList();	
		}
	}
	std::string RetWord = "Return";
	IO::Print("\nTo return to main menu enter [Return]\n");
	IO::Print("---> ");
	std::string in = IO::getString();
	while(!(in == RetWord))
	{
		IO::Print("---> ");
		in = IO::getString();
	}
	ShowMainMenu();
}

Shop::~Shop()
{
	
}