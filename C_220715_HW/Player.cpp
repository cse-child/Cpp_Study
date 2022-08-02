#include "Framework.h"

Player::Player()
{
	//cout << "Player ������ ȣ��" << endl;
}

Player::Player(string name)
	:name(name), attack(40), defence(30), skill("Ű���� ����ġ��")
{
	cout << name << " �̸����� ������ �����մϴ�." << endl << endl;
	ShowInfo();
}

Player::~Player()
{
}


void Player::ShowInfo()
{
	cout << endl << "---------- "<< name <<" Info ----------" << endl;
	cout << "HP : " << hp << endl;
	cout << "Attack : " << attack << endl;
	cout << "Defence : " << defence << endl;
	cout << "---------------------------------" << endl << endl;
}

void Player::AttackMonster(Monster * target)
{
	cout << name << "�� " << skill << " ���� !" << endl;
	cout << target->GetName() << "�� HP�� " << attack << "��ŭ �پ������ϴ� !" << endl << endl;

	target->SetHP(target, target->GetHP() - attack);
}

void Player::Damaged(Monster * target)
{
	hp = hp - target->GetAttack();
	if (hp < 0)
		hp = 0;
	cout << target->GetName() << "�� " << target->GetSkill() << " ���� !" << endl;
	cout << name << "�� HP�� " << target->GetAttack() << "��ŭ �پ������ϴ� !" << endl << endl;
	cout << name << "'s HP : " << hp << endl;
}

void Player::SelfHeal()
{
	cout << "�ڰ� ġ���� �����մϴ� !" << endl;
	hp = hp + defence;
	if (hp > 100)
		hp = 100;
	cout << name << "'s HP : " << hp << endl;
}


