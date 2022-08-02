#include "Framework.h"

Warrior::Warrior()
	:Character("����", 30, 20)
{
	cout << "Warrior ������ ȣ��" << endl;
}

Warrior::Warrior(string name, int attack, int defence)
	:Character(name, attack, defence)
{
	cout << "Warrior ������ ȣ��" << endl;
}

Warrior::~Warrior()
{
	cout << "Warrior �Ҹ��� ȣ��" << endl;
}

void Warrior::ShowInfo()
{
	Character::ShowInfo();
	cout << "MAX_SHIELD : " << maxShield << endl;
	cout << "CUR_SHIELD : " << curShield << endl;
}

void Warrior::Damage(int damage)
{
	curShield -= damage;

	if (curShield < 0)
		Character::Damage(curShield * 1);
}

void Warrior::Skill(Character* target)
{
	if (mp < maxShield)
		Attack(target);

	mp -= maxShield;

	cout << "������ ��ȣ��!!" << endl;
	cout << maxShield << "��ŭ ���带 ȹ���߽��ϴ�." << endl;
	curShield = maxShield;
}
