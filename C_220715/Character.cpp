#include "Framework.h"

Character::Character()
{
	cout << "Character 생성자 호출" << endl;
}

Character::Character(string name, int attack, int defence)
	:name(name), attack(attack), defence(defence)
{
	cout << "Character 생성자 호출" << endl;
}

Character::~Character()
{
	cout << "Character 소멸자 호출" << endl;
}

void Character::ShowInfo()
{
	cout << "----------------------------" << endl;
	cout << "-----INFO-------------------" << endl;
	cout << "Name : " << name << endl;
	cout << "HP : " << hp << endl;
	cout << "MP : " << mp << endl;
	cout << "ATK : " << attack << endl;
	cout << "DEF : " << defence << endl;
}

void Character::Attack(Character* target)
{
	cout << name << "(이/가) " << target->GetName() << "에게 공격" << endl;
	
	target->Damage(attack);
}

void Character::Damage(int damage)
{
	float trueDamage = damage - defence;
	if (trueDamage < 0)
		trueDamage = 0;

	hp -= trueDamage;
	
	cout << trueDamage << "만큼 피해를 입어서 현재 체력은 " << hp << endl;
}
