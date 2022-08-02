#pragma once

// 오버로딩 : 함수명이 같고 매개변수가 다른 경우
// -함수 오버로딩, -생성자 오버로딩. -연산자 오버로딩

// 전방선언
class Warrior;

class Character
{
public:
	Character();
	Character(string name, int attack, int defence);
	~Character();

	// 가상함수 : 업캐스팅을 했을 때 자식의 오버라이드 된 함수를 호출하고 싶은 경우 사용하는 방법
	virtual void ShowInfo();

	//void Attack(Warrior* warrior); 
	// 다양한 직업끼리 서로 공격할 수 있도록 Character로 선언
	void Attack(Character* target);
	
	
	virtual void Damage(int damage) = 0;
	// 순수 가상 함수 (함수를 =0으로 선언하는것)
	// : 모든 자식 클래스가 무조건 재정의 해야하는 함수
	// 장점: 함수가 자동완성 된다.
	// 순수가상함수가 사용된 클래스는 '추상클래스'가 된다.
	// 선언은 되어있지만 정의는 되어있지 않은 상태 -> 추상적
	// 추상클래스가 되면 Character라는 객체가 할당되지 않는다.
	virtual void Skill(Character* target) = 0;
	
	string GetName() { return name; }

protected: // 자식(파생)클래스에서 접근 가능
	string name = "NoName";
	int hp = 100;
	int mp = 100;
	int attack = 0;
	int defence = 0;
};

