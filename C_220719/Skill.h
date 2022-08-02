#pragma once

class Skill
{
public:
	enum SkillType
	{
		ATTACK, BUFF, NONE
	};

public:
	Skill(SkillData data);
	~Skill();

	void ShowInfo();

	virtual void Attack(Monster* target, Monster::Status attackerStatus) {}
	virtual void Buff(Monster* monster) {}

	SkillType GetSkillType() { return skillType; }

protected:
	string name;

	Type elementType;
	SkillType skillType;

	int maxUsingCount;
	int curUsingCount;

	int power;
};