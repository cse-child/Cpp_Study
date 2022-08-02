#include "Framework.h"

// static ������ �� Ŭ���� �ۿ��� �ʱ�ȭ �� ��
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

		/*while ((at = str.find_first_of(',')) != str.npos)
		{
			datas.push_back(str.substr(0, at));
			str = str.substr(at + 1);
		}*/

		ItemData itemData;
		itemData.name = datas[1];
		itemData.price = stoi(datas[2]); // string->int
		itemData.value = stoi(datas[3]);

		int key = stoi(datas[0]);

		itemDatas[key] = itemData;

		if (feof(file))
			return;
	}
}
