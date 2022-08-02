#pragma once

struct ItemData
{
	int index;
	string name;
	int price;
	int attack;
};

class DataManager
{
private:
	DataManager();
	~DataManager();

public:
	static DataManager* Get()
	{
		if (instance == nullptr)
			instance = new DataManager();
		return instance;
	}

	 static void Delete()
	{
		 delete instance;
	}

	 void LoadItemData();
	 ItemData GetItemData(int key) { return itemDatas[key]; }
	 void PrintAllData();


public:
	static DataManager* instance;

	unordered_map<int, ItemData> itemDatas;
};