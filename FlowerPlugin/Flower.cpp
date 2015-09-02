// Flower.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Flower.h"


// This is an example of an exported variable
FLOWER_API int nFlower=0;

// This is an example of an exported function.
FLOWER_API int fnFlower(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Flower.h for the class definition
CFlower::CFlower()
{
	return;
}


extern "C" __declspec(dllexport)const char *GetName()
{
	return "Flower";
}



extern "C" __declspec(dllexport)Factory* CreateNewfactory()
{
	std::cout << "Factory function started\n";
	return new AliveFactory;
}