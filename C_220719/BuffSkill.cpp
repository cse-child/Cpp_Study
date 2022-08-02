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
	cout << name << "스킬을 사용했습니다." << endl;

	target->IncreaseStatus((Monster::StatusType)elementType, power);
}
