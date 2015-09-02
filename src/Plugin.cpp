#include "Plugin.h"

Plugin::Plugin()
{}

void Plugin::SetFile(HMODULE lib)
{
	file = lib;
}



char *Plugin::GetName()
{
	typedef char*(*LibName)();
	LibName name;
	name = reinterpret_cast<LibName>(GetProcAddress(file, "GetName"));
	this->name = name();
	return this->name;
}

Factory *Plugin:: GetFactory()
{
	CreateNewfactory factHandle;
	factHandle = reinterpret_cast<CreateNewfactory>(GetProcAddress(file, "CreateNewfactory"));
	mPFact = factHandle();
	return this->mPFact;

}

Plugin *CreatePlugin()
{
	return new Plugin;
}