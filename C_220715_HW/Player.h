#pragma once

class Player
{
public:
	Player();
	Player(string name);
	~Player();
	void ShowInfo();
	void AttackMonster(Monster* target);
	void Damaged(Monster* target);
	void SelfHeal();

private:
	string name = "NoName";
	int hp = 100;
	uint attack = 0;
	uint defence = 0;
	string skill = "NoSkill";
};