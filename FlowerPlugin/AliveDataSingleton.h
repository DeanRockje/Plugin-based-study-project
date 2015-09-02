#ifndef ALIVEDATASINGLETON_H__
#define ALIVEDATASINGLETON_H__

#ifdef FLOWER_EXPORTS
#define FLOWER_API __declspec(dllexport)
#else
#define FLOWER_API __declspec(dllimport)
#endif
#pragma once 

#include <string>
#include <vector>
#include "Alive.h"
#include "stdafx.h" 

struct Alive;
class FLOWER_API AliveDataSingleton
{

	
	std::vector<Alive> _AliveData;
	static AliveDataSingleton *instance;
	AliveDataSingleton();
	AliveDataSingleton(AliveDataSingleton& Right);
	AliveDataSingleton operator = (AliveDataSingleton &);
public:
	static AliveDataSingleton *getInstance();
	void AddToVector(Alive *alInfo);
	int getDataSize()const;
	void clearVector();
	std::vector<Alive>& getData();
	void Remove();
};


#endif 