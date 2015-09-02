#pragma once 

#ifdef FLOWER_EXPORTS
#define FLOWER_API __declspec(dllexport)
#else
#define FLOWER_API __declspec(dllimport)
#endif

#include "Input.h"
#include <iostream>
#include <vector>
#include "Alive.h"
#include "AliveLoader.h"
#include "AliveDataSingleton.h"

class AliveLoader;
struct Alive; 

class FLOWER_API AliveInput :public Input
{
	int Ammount;
	Alive *Data;
public:
	Product* CreateProduct();
	bool EnterAllData();
	void setAmmout(int Amm);
	int GetProductsAmmount();
};