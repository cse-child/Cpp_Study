#include "Framework.h"

DataManager* DataManager::instance = nullptr;

DataManager::DataManager()
{
	LoadMonsterData();
	LoadSkillData();
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

void DataManager::LoadSkillData()
{
	ifstream loadFile("TableData/SkillTable.tsv", ios::in);

	int colNum = 6;
	bool isFirstLine = true;

	int skillCount = 0;

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
		SkillData skillData;
		int key;
		loadFile >> key;

		loadFile >> skillData.name >> skillData.elementType >> skillData.skillType >>
			skillData.usingCount >> skillData.power;

		skillDatas[skillCount++] = skillData;

		if (loadFile.eof())
			return;
	}
}
