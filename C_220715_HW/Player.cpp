#include "Framework.h"

Player::Player()
{
	//cout << "Player 생성자 호출" << endl;
}

Player::Player(string name)
	:name(name), attack(40), defence(30), skill("키보드 내려치기")
{
	cout << name << " 이름으로 게임을 시작합니다." << endl << endl;
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
	cout << name << "의 " << skill << " 공격 !" << endl;
	cout << target->GetName() << "의 HP가 " << attack << "만큼 줄어들었습니다 !" << endl << endl;

	target->SetHP(target, target->GetHP() - attack);
}

void Player::Damaged(Monster * target)
{
	hp = hp - target->GetAttack();
	if (hp < 0)
		hp = 0;
	cout << target->GetName() << "의 " << target->GetSkill() << " 공격 !" << endl;
	cout << name << "의 HP가 " << target->GetAttack() << "만큼 줄어들었습니다 !" << endl << endl;
	cout << name << "'s HP : " << hp << endl;
}

void Player::SelfHeal()
{
	cout << "자가 치유를 시작합니다 !" << endl;
	hp = hp + defence;
	if (hp > 100)
		hp = 100;
	cout << name << "'s HP : " << hp << endl;
}


