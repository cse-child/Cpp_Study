#pragma once

enum Type
{
	SHIELD,		// ����
	KNIFE,		// Į
	ARROW,		// ȭ��
	DAGGER		// �ܰ�
};

struct WeaponInfo
{
	string name;
	int attack;
	int price;
	string wClass; // ���
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