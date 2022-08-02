#pragma once

class Monster
{
public:
	Monster();
	Monster(string name, int attack, int defence, string skill);
	~Monster();
	void ShowInfo();
	string GetName();
	uint GetHP();
	uint GetAttack();
	string GetSkill();
	void SetHP(Monster* target, uint hp);
	void SelfHeal(Monster *monster);
	bool IsDead(Monster* monster);
	void SetRun(Monster* monster);

private:
	uint attack = 0; // °ø°Ý·Â
	string name = "NoName";
	uint defence = 0;
	string skill = "NoSkill";
	int hp = 100;
	bool isDead = false;
};