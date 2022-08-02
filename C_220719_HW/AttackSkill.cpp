#include "Framework.h"

AttackSkill::AttackSkill(SkillData skillData)
	:Skill(skillData)
{
}

AttackSkill::~AttackSkill()
{
}

void AttackSkill::Attack(Monster* target, Monster::Status attackerStatus)
{
	curUsingCount--;

	cout << name << " ��ų�� ����߽��ϴ� !" << endl;

	int damage = 0;

	if (elementType == Type::NONE)
	{
		damage = power + attackerStatus.attack;
	}
	else
	{
		damage = power + attackerStatus.special;
	}

	target->Damage(elementType, damage);
}
