#include "Framework.h"

Magician::Magician()
	:Character("������", 40, 10), type(FIRE)
{
	cout << "������ ������ ȣ��" << endl;
}

Magician::~Magician()
{
	cout << "������ �Ҹ��� ȣ��" << endl;
}

void Magician::ShowInfo()
{
	Character::ShowInfo();

	switch (type)
	{
	case Magician::FIRE:
		cout << "TYPE : FIRE" << endl;
		break;
	case Magician::ICE:
		cout << "TYPE : ICE" << endl;
		break;
	case Magician::WIND:
		cout << "TYPE : WIND" << endl;
		break;
	default:
		cout << "TYPE : NORMAL" << endl;
		break;
	}
}

void Magician::Skill(Character* target)
{
	if (mp < SKILL_MP)
		Attack(target);

	mp -= SKILL_MP;

	cout << "FireBall!" << endl;

	target->Damage(attack * 2.0f);

}

void Magician::Damage(int damage)
{
}
