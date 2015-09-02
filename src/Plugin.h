#ifndef PLUGIN_H__
#define PLUGIN_H__

#include "Factory.h"
#include <Windows.h>


typedef Factory*(*CreateNewfactory)();
/*описатель каждого подключаемого плагина*/
class Plugin
{
	char *name;
	HMODULE file;
	Factory *mPFact;
	bool Registered;
	bool Activated;
	Plugin(const Plugin &right);
	Plugin operator =(const Plugin &right);
public:
	Plugin();
	void SetFile(HMODULE lib);
	bool getRegisterStatus()const{return Registered;}
	bool getActivationStatus()const{return Activated;}
	char *GetName();
	Factory* GetFactory();
};

Plugin *CreatePlugin();

#endif