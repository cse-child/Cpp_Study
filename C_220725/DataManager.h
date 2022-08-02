#pragma once

struct ItemData
{
	string name;
	int price;
	int value;
};

class DataManager
{
private: // 싱글톤
	DataManager();
	~DataManager();

public:
	static DataManager* Get()
	{
		if (instance == nullptr) // 할당이 안되어있을때
			instance = new DataManager(); // 한번만 할당
		
		return instance;
	}

	static void Delete()
	{
		delete instance;
	}
	
	void LoadItemData();	

	ItemData GetItemData(int key) { return itemDatas[key];}

private:
	static DataManager* instance;

	unordered_map<int, ItemData> itemDatas;
};