#include "Framework.h"

Monster::Monster()
{
	//cout << "Monster ������1 ȣ��" << endl;
}

Monster::Monster(string name, int attack, int defence, string skill)
	:name(name), attack(attack), defence(defence), skill(skill)
{
	//cout << "Monster ������2 ȣ��" << endl;
}

Monster::~Monster()
{
}

void Monster::ShowInfo()
{
	cout << endl << "���Ͱ� �����߽��ϴ� !!" << endl;
	cout << "------- Monster Info -------" << endl;
	cout << "Name : " << name << endl;
	cout << "HP : " << hp << endl;
	cout << "Attack : " << attack << endl;
	cout << "Defence : " << defence << endl;
	cout << "----------------------------" << endl << endl;
}

string Monster::GetName()
{
	return name;
}

uint Monster::GetHP()
{
	return hp;
}

uint Monster::GetAttack()
{
	return attack;
}

string Monster::GetSkill()
{
	return skill;
}

void Monster::SetHP(Monster* target, uint hp)
{
	target->hp = hp;
	if (target->hp < 0)
		target->hp = 0;
	cout << target->name << "'s HP : " << target->hp << endl;
}

void Monster::SelfHeal(Monster* monster)
{
	monster->hp = monster->hp + monster->defence;
	if (monster->hp > 100)
		monster->hp = 100;
	
	cout << monster->name << "(��/��) ������ ȸ���Ͽ� HP�� " << monster->hp << "�� �Ǿ����ϴ� !!" << endl;
}

bool Monster::IsDead(Monster* monster)
{
	if (monster->hp == 0)
		monster->isDead = true;
	return monster->isDead;
}

void Monster::SetRun(Monster * monster)
{
	isDead = true; // ����ġ�� �׳� �����ɷ� ħ..
}
