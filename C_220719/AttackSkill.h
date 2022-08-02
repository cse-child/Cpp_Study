#pragma once

class AttackSkill : public Skill
{
public:
	AttackSkill(SkillData skillData);
	~AttackSkill();

	void Attack(Monster* target, Monster::Status attackerStatus) override;
};