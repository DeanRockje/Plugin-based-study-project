#include "stdafx.h"
#include "AliveLoader.h"
#include <fstream>
#include "IO.hpp"




bool AliveLoader::isExist()
{
	if(std::ifstream("Alive.shp"))
		return true;
	return false;
}

void AliveLoader::Write(std::ofstream &os)
{
	
	for(auto it:AliveDataSingleton::getInstance()->getData())
		os << it.ammount << it.Color.c_str() << it.FROM.c_str() << it.Height << it.ISATWAREHOUSE.c_str() << it.NAME.c_str() 
		<< it.PeriodOfLife.c_str() << it.PRICE << it.Type.c_str() << it.TypeOfGroud.c_str();
}


void AliveLoader::Read(std::ifstream &is)
{
	while(is >> AlDat.data()->NAME >> AlDat.data()->Type >> AlDat.data()->Height
		>> AlDat.data()->TypeOfGroud >> AlDat.data()->PeriodOfLife 
		>> AlDat.data()->Color >> AlDat.data()->FROM >> AlDat.data()->ISATWAREHOUSE 
		>> AlDat.data()->ammount )
	{
		AliveDataSingleton::getInstance()->clearVector();
		AliveDataSingleton::getInstance()->AddToVector(AlDat.data());
	}
}