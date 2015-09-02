#pragma once
#include "Output.h"
#include "AliveLoader.h"
#include <memory>
#ifdef FLOWER_EXPORTS
#define FLOWER_API __declspec(dllexport)
#else
#define FLOWER_API __declspec(dllimport)
#endif
#include "Alive.h"

struct Alive;

class FLOWER_API AliveOutput :public Output
{
	AliveLoader Loader;
	std::shared_ptr<AliveInput>pAl;
	std::vector<Alive> AlData;
	int AliveDataSize;
public:
	void ShowList();
};