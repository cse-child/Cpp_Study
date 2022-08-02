#include "Framework.h"

Warrior::Warrior()
	:Character("전사", 30, 20)
{
	cout << "Warrior 생성자 호출" << endl;
}

Warrior::Warrior(string name, int attack, int defence)
	:Character(name, attack, defence)
{
	cout << "Warrior 생성자 호출" << endl;
}

Warrior::~Warrior()
{
	cout << "Warrior 소멸자 호출" << endl;
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

	cout << "전사의 보호막!!" << endl;
	cout << maxShield << "만큼 쉴드를 획득했습니다." << endl;
	curShield = maxShield;
}
