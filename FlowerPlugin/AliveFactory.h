#pragma once 
#include "Factory.h"
#include "AliveInput.h"
#include "AliveOutput.h"
#include "AliveLoader.h"

#ifdef FLOWER_EXPORTS
#define FLOWER_API __declspec(dllexport)
#else
#define FLOWER_API __declspec(dllimport)
#endif

class FLOWER_API AliveFactory: public Factory
{
public:
	Input * CreateInput();
	Output* CreateOutput();
	FileManager * CreateLoader();
};