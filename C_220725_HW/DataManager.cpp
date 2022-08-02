#include "Framework.h"

DataManager* DataManager::instance = nullptr;

DataManager::DataManager()
{
}

DataManager::~DataManager()
{
}

void DataManager::LoadItemData()
{
	FILE* file;
	fopen_s(&file, "ItemTable.csv", "r");

	bool isFirstLine = true;

	while (true)
	{
		char temp[1024];
		fgets(temp, 1024, file);

		if (isFirstLine)
		{
			isFirstLine = false;
			continue;
		}

		string str = temp;

		size_t at = str.find('\n');
		str = str.substr(0, at);

		vector<string> datas;

		// npos = -1
		while (true)
		{
			at = str.find_first_of(',');

			datas.push_back(str.substr(0, at));

			str = str.substr(at + 1);

			if (at == str.npos)
				break;
		}

		ItemData itemData;
		itemData.index = stoi(datas[0]);
		itemData.name = datas[1];
		itemData.price = stoi(datas[2]); // string->int
		itemData.attack = stoi(datas[3]);

		itemDatas[itemData.index] = itemData;

		if (feof(file))
			return;
	}
}

void DataManager::PrintAllData()
{
	cout << endl << "-------------- Item List --------------" << endl;
	cout << "번호\t아이템명\t가격\t공격력" << endl;

	for (int i = 0; i < itemDatas.size(); i++)
	{
		cout << "  " << (i+1) << "\t" << itemDatas[i].name << "\t" << itemDatas[i].price << "\t" << itemDatas[i].attack << endl;
	}

	cout << "--------------------------------------" << endl;
}
