#include "Framework.h"

Character::Character()
{
	cout << "Character ������ ȣ��" << endl;
}

Character::Character(string name, int attack, int defence)
	:name(name), attack(attack), defence(defence)
{
	cout << "Character ������ ȣ��" << endl;
}

Character::~Character()
{
	cout << "Character �Ҹ��� ȣ��" << endl;
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
	cout << name << "(��/��) " << target->GetName() << "���� ����" << endl;
	
	target->Damage(attack);
}

void Character::Damage(int damage)
{
	float trueDamage = damage - defence;
	if (trueDamage < 0)
		trueDamage = 0;

	hp -= trueDamage;
	
	cout << trueDamage << "��ŭ ���ظ� �Ծ ���� ü���� " << hp << endl;
}
