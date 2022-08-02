#include "Framework.h"

DataManager* DataManager::instance = nullptr;

DataManager::DataManager()
{
	LoadMonsterData();
}

DataManager::~DataManager()
{
}

void DataManager::LoadMonsterData()
{
	ifstream loadFile("TableData/MonsterTable.tsv", ios::in);

	int colNum = 8;
	bool isFirstLine = true;

	int monsterCount = 0;

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
		MonsterData monsterData;
		loadFile >> monsterData.key >> monsterData.name >>
			monsterData.type >> monsterData.hp >> monsterData.attack >>
			monsterData.defence>> monsterData.speed >> monsterData.special;

		monsterDatas[monsterCount++] = monsterData;

		if (loadFile.eof())
			return;
	}
}
