#pragma once
#include "FileManager.h"
#include "Alive.h"
#include "Product.h"
#include "AliveInput.h"
#include  <fstream>
#include <iostream>

#ifdef FLOWER_EXPORTS
#define FLOWER_API __declspec(dllexport)
#else
#define FLOWER_API __declspec(dllimport)
#endif


struct Alive;

class FLOWER_API AliveLoader:public FileManager
{
	int dataSize;
	std::vector<Alive>AlDat;
public:
	bool isExist();
	void Read(std::ifstream &is);
	void Write(std::ofstream &os);
};