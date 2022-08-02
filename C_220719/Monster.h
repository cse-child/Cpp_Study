#pragma once

class Monster
{
private:
	static const int SKILL_NUM = 4;

public:
	enum StatusType
	{
		HP, ATK, DEF, SPD, SPE
	};

	struct Status
	{
		int hp;
		int attack;
		int defence;
		int speed;
		int special;

		void SetData(MonsterData data)
		{
			hp = data.hp;
			attack = data.attack;
			defence = data.defence;
			speed = data.speed;
			special = data.special;
		}
	};

public:
	Monster(MonsterData data);
	~Monster();

	void Damage(Type type, int damage);
	void Attack(Monster* target);

	void ShowInfo();
	void ShowSkillInfo();
	void SetType(string type);
	Type StringToType(string type);

	void AddSkill(int skillKey);
	void IncreaseStatus(StatusType statusType, int value);

private:
	string name;
	string typeName;
	Type types[2];
	Status initStatus;
	Status curStatus;

	class Skill* skills[SKILL_NUM] = {}; // 전방선언
	int skillCount = 0;
};