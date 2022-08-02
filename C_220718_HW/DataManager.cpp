#include "Framework.h"

DataManager* DataManager::instance = nullptr;
string DataManager::weaponsName[] = {};

DataManager::DataManager()
{
	LoadWeaponData();
}

DataManager::~DataManager()
{
}

void DataManager::LoadWeaponData()
{
	ifstream loadFile("TableData/WeaponTable.tsv", ios::in);

	int colNum = 6;
	bool isFirstLine = true;

	int weaponCount = 0;

	while (true)
	{
		string temp;

		if (isFirstLine)
		{
			for (int i = 0; i < colNum; i++)
			{
				loadFile >> temp;
			}
			isFirstLine = false;
		}
		WeaponData weaponData;
		loadFile >> weaponData.key >> weaponData.name >> weaponData.type >> 
			weaponData.attack >> weaponData.price >> weaponData.wClass;

		weaponsName[weaponCount] = weaponData.name;
		weaponDatas[weaponCount++] = weaponData;

		if (loadFile.eof())
			return;
	}
}

void DataManager::ShowWeaponsName()
{
	for (int i = 0; i < MAX_WEAPON_NUM; i++)
	{
		cout << (i + 1) << ". " << weaponsName[i] << endl;
	}
}
