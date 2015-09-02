#pragma once 


class FileManager
{
	virtual void Read(std::ifstream &is) = 0;
	virtual void Write(std::ofstream &os) = 0;
};