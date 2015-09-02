#include "stdafx.h"
#include "AliveFactory.h"
#include "AliveInput.h"

Input* AliveFactory::CreateInput()
{
	std::cout << "Input created\n";
	return new AliveInput;
}

Output* AliveFactory::CreateOutput()
{
	std::cout << "Output created\n";
	return new AliveOutput;

}


FileManager* AliveFactory::CreateLoader()
{
	std::cout << "File Manager created\n";
	return new AliveLoader;
}