#pragma once 
#include "Product.h"

class Input
{
public:
	virtual Product* CreateProduct() = 0;
	virtual  void EnterData() = 0;
};