#include "PluginManager.h"

PluginManager *PluginManager::mpInst = 0;

PluginManager *PluginManager::getInstance()
{
	if (!mpInst)
	{
		mpInst = new PluginManager();
	}
	return mpInst;
}

PluginManager::PluginManager() : m_pLib(NULL)
{
	std::shared_ptr<Plugin>temp(CreatePlugin());
	mS_Plug = temp;
	clearPluginList();
	IO::Print("PLUGIN MANAGER CONSTRUCTOR", 1);
}

void PluginManager::SetPath(const wchar_t *rPath)
{
	Path = new wchar_t[MAX_PATH];
	wcscpy(Path, rPath);
	Load();
}

wchar_t *PluginManager::getPath()
{
	return Path;
}

char *PluginManager::getName()
{
	return mS_Plug->GetName();
}

PluginManager::~PluginManager()
{
	if (!m_LibVector.empty())
	{
		std::vector<HMODULE>::iterator it;
		for (it = m_LibVector.begin(); it != m_LibVector.end(); ++it)
		{
			Unload(*it);
		}
	}
	delete [] Path;
	\
}


int PluginManager::getNumPlugins()
{
	return m_LibVector.size();
}

void PluginManager::clearPluginList()
{
	for (unsigned i = 0; i < m_LibVector.size(); ++i)
	{
		delete m_LibVector.at(i);
	}
	m_LibVector.clear();
}



bool PluginManager::Load()
{
	wchar_t fName[MAX_PATH];
	wcscpy(fName, Path);
	size_t len = wcslen(fName);
	if (fName[len - 1] == '/' || fName[len - 1] == '\\')
		wcscat(fName, L"*.dll");
	else
		wcscat(fName, L"\\*.dll");
	WIN32_FIND_DATA fd;
	HANDLE hFind = FindFirstFile(fName, &fd);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		IO::Print("Can't load plugin", 1);
		FindClose(hFind);
		return false;
	}
	do
	{
		try
		{
				m_pLib = LoadLibrary(fd.cFileName);
				if (m_pLib != NULL)
				{
					FactoryFUNC fHandle;
					fHandle = reinterpret_cast<FactoryFUNC>(GetProcAddress(m_pLib, "CreateNewfactory"));
					if (fHandle != NULL)
					{
						m_LibVector.push_back(m_pLib);
						mS_Plug->SetFile(m_pLib);
						//mPlugMap.emplace(CreatePlugin(),m_pLib);
						 
					}
						
				}
		}
		catch (...)
		{
			if (m_pLib != NULL)
				FreeLibrary(m_pLib);
		}

	} while (FindNextFile(hFind, &fd)!=0); 
	return true;
}

Factory* PluginManager::getFactory()
{
	return mS_Plug->GetFactory();
}

void PluginManager::GetPluginList()
{
	wchar_t fName[MAX_PATH];
	wcscpy(fName, Path);
	size_t len = wcslen(fName);
	if (fName[len - 1] == '/' || fName[len - 1] == '\\')
		wcscat(fName, L"*.dll");
	else
		wcscat(fName, L"\\*.dll");
	WIN32_FIND_DATA fd;
	HANDLE hFind = FindFirstFile(fName, &fd);
	do
	{
		IO::WPrint(fd.cFileName);
	} while (FindNextFile(hFind, &fd) != 0);
}

void PluginManager::Unload(HMODULE hmod)
{

#ifdef  WIN32
	FreeLibrary(hmod); // if windows 
#endif

}


