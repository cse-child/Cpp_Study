#pragma once

enum class Type
{
	FIRE, WATER, GRASS, STONE, POISON, NONE
};

struct Status
{
	int hp;
	int attack;
	int defence;
	int speed;
	int special;

	void SetData(DataManager::MonsterData data)
	{
		hp = data.hp;
		attack = data.attack;
		defence = data.defence;
		speed = data.speed;
		special = data.special;
	}
};

class Monster
{
public:
	Monster(DataManager::MonsterData data);
	~Monster();

	void ShowInfo();
	void SetType(string type);
	Type StringToType(string type);

private:
	string name;
	string typeName;
	Type types[2];
	Status initStatus;
	Status curStatus;
};