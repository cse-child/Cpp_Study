#include "Framework.h"

BuffSkill::BuffSkill(SkillData skillData)
	:Skill(skillData)
{
}

BuffSkill::~BuffSkill()
{
}

void BuffSkill::Buff(Monster* target)
{
	cout << name << "��ų�� ����߽��ϴ�." << endl;

	target->IncreaseStatus((Monster::StatusType)elementType, power);
}
