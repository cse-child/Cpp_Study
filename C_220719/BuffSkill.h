#pragma once

class BuffSkill : public Skill
{
public:
	BuffSkill(SkillData skillData);
	~BuffSkill();

	void Buff(Monster* target) override;
};
