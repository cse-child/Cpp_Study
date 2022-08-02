#pragma once

class Magician : public Character
{
private:
	const int SKILL_MP = 30;

	enum ElementType
	{
		FIRE, ICE, WIND, 
	};
public:
	Magician();
	~Magician();
	
	virtual void ShowInfo() override;

	// Character��(��) ���� ��ӵ�
	virtual void Skill(Character* target) override;
	// Character��(��) ���� ��ӵ�
	virtual void Damage(int damage) override;

private:
	ElementType type;
};