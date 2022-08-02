#pragma once

enum Type
{
	SHIELD,		// 방패
	KNIFE,		// 칼
	ARROW,		// 화살
	DAGGER		// 단검
};

struct WeaponInfo
{
	string name;
	int attack;
	int price;
	string wClass; // 등급
	string type;

	void SetData(DataManager::WeaponData data)
	{
		name = data.name;
		attack = data.attack;
		price = data.price;
		wClass = data.wClass;
		type = data.type;
	}
};

class Weapon
{
public:
	Weapon();
	Weapon(DataManager::WeaponData data);
	~Weapon();

	void ShowInfo();
	void SetType(string type);

private:
	//Type type;
	WeaponInfo wInfo;

};