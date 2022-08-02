#include "Framework.h"

Skill::Skill(SkillData data)
	:name(data.name), elementType((Type)data.elementType),
	skillType((SkillType)data.skillType)
	,maxUsingCount(data.usingCount), 
	curUsingCount(data.usingCount), power(data.power)
{
}

Skill::~Skill()
{
}

void Skill::ShowInfo()
{
	printf("%s(%d/%d) ", name.c_str(), curUsingCount, maxUsingCount);
}
