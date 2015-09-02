#include "stdafx.h"
#include "AliveInput.h"
#include "Alive.h"
#include "IO.hpp"




Product* AliveInput::CreateProduct()
{
	std::cout << "Products Created\n";
	return new Alive;
}


void AliveInput::setAmmout(int Amm)
{
	Ammount = Amm;
}


bool AliveInput::EnterAllData()
{
	bool ret = false;
	int i = 0;
	IO::Print("Ammount of products: ");
	int amm = IO::getInt();
	setAmmout(amm);
	Data = new Alive; 
	while(i < amm)
	{
		IO::Print("FLOWER NAME: ");
		Data->NAME = IO::getString();
		IO::Print("TYPE NAME: ");
		Data->Type = IO::getString();
		IO::Print("County of origin: ");
		Data->FROM = IO::getString();
		IO::Print("Color: ");
		Data->FROM = IO::getString();
		IO::Print("Height: ");
		Data->Height = IO::getDouble();
		IO::Print("Period of life: ");
		Data->PeriodOfLife = IO::getString();
		IO::Print("Type of ground: ");
		Data->TypeOfGroud = IO::getString();
		IO::Print("Price: ");
		Data->PRICE = IO::getDouble();
		IO::Print("is at warehouse: ");
		Data->ISATWAREHOUSE = IO::getString();
		IO::Print("Ammount: ");
		Data->ammount = IO::getInt();
		AliveDataSingleton::getInstance()->AddToVector(Data);
		i++;
		if( i == amm)
			ret = true;
	}
	delete Data;
	return ret;
}

int AliveInput::GetProductsAmmount()
{
	return Ammount;
}
