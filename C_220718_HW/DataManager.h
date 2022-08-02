#pragma once

class DataManager
{
private:
	static const int MAX_WEAPON_NUM = 5;

public:
	struct WeaponData
	{
		int key;
		string name;
		string type;
		int attack;
		int price;
		string wClass; // µî±Þ
	};

private:
	DataManager();
	~DataManager();

public:
	static DataManager* GetInstance()
	{
		if (instance == nullptr)
			instance = new DataManager();
		return instance;
	}

	static void Delete()
	{
		delete instance;
	}

	WeaponData GetWeaponData(int key)
	{
		return weaponDatas[key - 1];
	}

	static void ShowWeaponsName();

private:
	void LoadWeaponData();

private:
	static DataManager* instance;
	WeaponData weaponDatas[MAX_WEAPON_NUM];
	static string weaponsName[MAX_WEAPON_NUM];
};