#ifndef PLUGINMANAGER_H__
#define PLUGINMANAGER_H__
#include <Windows.h>
#include <vector>
#include <map>
#include "IO.hpp"
#include "Category.h"
#include "Plugin.h"
#include <memory>

/*Класс отвечает за загрузку, удаление и работу с плагином*/



class PluginManager
{
	PluginManager(const PluginManager &right); //запрещаем коприрование
	PluginManager operator = (const PluginManager &right); // а так же присваивание.
	HMODULE  m_pLib;
	std::shared_ptr<Plugin>mS_Plug;
	wchar_t *Path;
	std::vector<HMODULE>m_LibVector;
	//------------------------------------
	static PluginManager *mpInst;
	
	bool Load();
	void Unload(HMODULE hmod);
	void clearPluginList();
	PluginManager();
	
public:
	static PluginManager* getInstance();
	void SetPath(const wchar_t *Path);
	wchar_t* getPath();
	void pluginMenu();
	int getNumPlugins();
	void GetPluginList();
	char* getName();
	Factory* getFactory();
	~PluginManager();
protected:
	typedef Factory*(*FactoryFUNC)();

};

#endif