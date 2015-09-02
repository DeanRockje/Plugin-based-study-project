#include <ostream>
#include <istream>
#include <vector>
#pragma once 


class FileManager
{
public:
	virtual void Read(std::ifstream &is) = 0;
	virtual void Write(std::ofstream &os) = 0;
	
};