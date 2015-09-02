#include "stdafx.h"
#include "AliveOutput.h"
#include "IO.hpp"

void AliveOutput::ShowList()
{
	if(!Loader.isExist())
	{
		pAl.reset(new AliveInput);
		if(pAl->EnterAllData())
		{
			IO::Print("Data entered, save it? <Type 'Yes' or 'No'>\n");
			IO::Print("> ");
			std::string in = IO::getString();
			if(in == "Yes")
				Loader.Write(std::ofstream("Alive.shp"));
			else
				return;
		}
		
	}
	else
		{
				Loader.Read(std::ifstream("Alive.shp", std::ios_base::binary));
				IO::Print("Loaded: ");
				int size = AliveDataSingleton::getInstance()->getDataSize();
				IO::Print(size);
				/*AlData.resize(size);
				AlData = AliveDataSingleton::getInstance()->getData();
				for(auto it = AlData.begin();it != AlData.end(); it++)
				{
					std::cout << it->NAME <<" | " << it->Type << " | " << it->FROM << " | "
						<< it->Height <<" | " << it->PeriodOfLife << " | " << it->TypeOfGroud << " | "
						<< it->ISATWAREHOUSE <<" | " << it->PRICE << " | " << it->Color << " | " << it->ammount << " | ";
					std::cout << "\n";
				}*/
		}
}