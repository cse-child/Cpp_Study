#pragma once

struct ItemData
{
	string name;
	int price;
	int value;
};

class DataManager
{
private: // �̱���
	DataManager();
	~DataManager();

public:
	static DataManager* Get()
	{
		if (instance == nullptr) // �Ҵ��� �ȵǾ�������
			instance = new DataManager(); // �ѹ��� �Ҵ�
		
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