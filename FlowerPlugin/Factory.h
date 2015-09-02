#pragma once 
#include "Input.h"
#include "Output.h"
#include "FileManager.h"
//----------------------------------
class Factory
{
public :
	virtual Input *CreateInput() = 0;
	virtual Output *CreateOutput() = 0;
	virtual FileManager* CreateLoader() = 0;
};