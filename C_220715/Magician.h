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

	// Character을(를) 통해 상속됨
	virtual void Skill(Character* target) override;
	// Character을(를) 통해 상속됨
	virtual void Damage(int damage) override;

private:
	ElementType type;
};