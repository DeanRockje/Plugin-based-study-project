#include "stdafx.h"
#include "AliveDataSingleton.h"


AliveDataSingleton *AliveDataSingleton::instance = NULL;

AliveDataSingleton *AliveDataSingleton::getInstance()
{
	if(!instance )
		instance = new AliveDataSingleton();
	return instance;
}

AliveDataSingleton::AliveDataSingleton(){}


int AliveDataSingleton::getDataSize()const
{
	return _AliveData.end() - _AliveData.begin();
}

std::vector<Alive>& AliveDataSingleton::getData()
{
	return _AliveData;
}

void AliveDataSingleton::AddToVector(Alive *alInfo)
{
	_AliveData.push_back(*(alInfo));
}

void AliveDataSingleton::clearVector()
{
	if(!_AliveData.empty())
		_AliveData.clear();
}

void AliveDataSingleton::Remove()
{
	_AliveData.pop_back();
}

