#pragma once 

#ifdef FLOWER_EXPORTS
#define FLOWER_API __declspec(dllexport)
#else
#define FLOWER_API __declspec(dllimport)
#endif

#include "Product.h"
#include "AliveInput.h"

class AliveInput;
struct FLOWER_API Alive : Product 
{
	std::string Color;
	double Height;
	std::string Type;
	std::string TypeOfGroud;
	std::string PeriodOfLife;
	friend class AliveInput;
};
//
//std::ostream& operator << (std::ostream &out, const Alive &Data) // used to add Alive to byte stream
//{
//	std::size_t colorSize = Data.Color.size();
//	std::size_t typeSize = Data.Type.size();
//	std::size_t typeOfGroundSize = Data.TypeOfGroud.size();
//	std::size_t PeriodofLifeSize = Data.PeriodOfLife.size();
//	std::size_t nameSize = Data.NAME.size();
//	std::size_t fromSize = Data.FROM.size();
//	std::size_t warehouseSize = Data.ISATWAREHOUSE.size(); 
//	
//	out.write(Data.NAME.c_str(), sizeof(nameSize));
//	out.write(reinterpret_cast<const char*>(&Data.Height), sizeof(Data.Height));
//	out.write(Data.Color.c_str(), sizeof(colorSize));
//	out.write(Data.Type.c_str(), sizeof(typeSize));
//	out.write(Data.TypeOfGroud.c_str(), sizeof(typeOfGroundSize));
//	out.write(Data.PeriodOfLife.c_str(), sizeof(PeriodofLifeSize));
//	out.write(Data.ISATWAREHOUSE.c_str(), sizeof(warehouseSize));
//	out.write(Data.FROM.c_str(), sizeof(fromSize));
//	out.write(reinterpret_cast<const char*>(&Data.ammount), sizeof(Data.ammount));
//	out.write(reinterpret_cast<const char*>(&Data.PRICE), sizeof(Data.PRICE));
//	return out;
//}
//
//
//std::istream& operator >> (std::istream &is, Alive &Data)
//{
//	std::size_t colorSize = Data.Color.size();
//	std::size_t typeSize = Data.Type.size();
//	std::size_t typeOfGroundSize = Data.TypeOfGroud.size();
//	std::size_t PeriodofLifeSize = Data.PeriodOfLife.size();
//	std::size_t nameSize = Data.NAME.size();
//	std::size_t fromSize = Data.FROM.size();
//	std::size_t warehouseSize = Data.ISATWAREHOUSE.size(); 
//	
//	is.read(const_cast<char*>(Data.NAME.c_str()), sizeof(nameSize));
//	is.read(reinterpret_cast<char*>(&Data.Height), sizeof(Data.Height));
//	is.read(const_cast<char*>(Data.Color.c_str()), sizeof(colorSize));
//	is.read(const_cast<char*>(Data.Type.c_str()), sizeof(typeSize));
//	is.read(const_cast<char*>(Data.TypeOfGroud.c_str()), sizeof(typeOfGroundSize));
//	is.read(const_cast<char*>(Data.PeriodOfLife.c_str()), sizeof(PeriodofLifeSize));
//	is.read(const_cast<char*>(Data.ISATWAREHOUSE.c_str()), sizeof(warehouseSize));
//	is.read(const_cast<char*>(Data.FROM.c_str()), sizeof(fromSize));
//	is.read(reinterpret_cast<char*>(&Data.ammount), sizeof(Data.ammount));
//	is.read(reinterpret_cast<char*>(&Data.PRICE), sizeof(Data.PRICE));
//	return is;
//}