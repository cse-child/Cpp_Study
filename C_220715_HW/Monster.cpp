#include "Framework.h"

Monster::Monster()
{
	//cout << "Monster 생성자1 호출" << endl;
}

Monster::Monster(string name, int attack, int defence, string skill)
	:name(name), attack(attack), defence(defence), skill(skill)
{
	//cout << "Monster 생성자2 호출" << endl;
}

Monster::~Monster()
{
}

void Monster::ShowInfo()
{
	cout << endl << "몬스터가 등장했습니다 !!" << endl;
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
	
	cout << monster->name << "(이/가) 스스로 회복하여 HP가 " << monster->hp << "가 되었습니다 !!" << endl;
}

bool Monster::IsDead(Monster* monster)
{
	if (monster->hp == 0)
		monster->isDead = true;
	return monster->isDead;
}

void Monster::SetRun(Monster * monster)
{
	isDead = true; // 도망치면 그냥 죽은걸로 침..
}
