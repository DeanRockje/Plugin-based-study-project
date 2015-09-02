#pragma once
#include <iostream>
#include <conio.h>
#include <sstream>
#define MAX_AVAILABLE_SYMBOLS 5 // 5 символов - максимальное значение числа, больше не имеет смысл

class IO
{
public:
	template<typename C>
	static void Print(C c)
	{
		std::cout << c;
	}
	template<typename C>
	static void Print(C c, bool CarriageReturn)
	{
			std::cout << c;
		if (CarriageReturn)
			std::cout << std::endl;
	}
	template<typename Y>
	static void WPrint(Y y)
	{
		std::wcout << y << std::endl;
	}
	static std::string getString()
	{
		std::string temp;
		std::getline(std::cin, temp);
		return temp;
	}
	static int getInt()
	{
		std::string s;
		int number = 0;
		std::stringstream ss;
		std::getline(std::cin, s);
		if (s.empty())
			return 0;
		else
			ss << s;
		int factor = 1;
		for (int i = s.length(); i >= 0; --i)
		{
			if ((int)s[i]<'0' || (int)s[i] > '9')
				continue;
			number += ((int)s[i] - (int)'0')*factor;
			factor *= 10;
		}
		return number;
	}
	static double getDouble()
	{
		std::string s;
		double num = 0;
		std::getline(std::cin, s);
		if(!s.empty())
		{
			std::stringstream ss;
			ss << s;
			ss >> num;
		}
		return num;
	}

};