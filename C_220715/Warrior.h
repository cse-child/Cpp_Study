#pragma once

// 상속받을 때 접근지정자
// public : 부모의 Public, Protected, Private 그대로 사용
// protected : 부모의 public을 protected로 사용
// private : 부모의 모든 접근지정자 private로 사용

class Warrior : public Character // Character 클래스 상속받기
{
public:
	Warrior();
	Warrior(string name, int attack, int defence);
	~Warrior();

	// 오버라이드 : 부모(상위)클래스에 있는 함수를 자식클래스에서 재정의 하는 것
	virtual void ShowInfo() override;
	virtual void Damage(int damage) override;
	virtual void Skill(Character* target) override;
	// override를 안붙여도 상관없지만 붙이면 실수를 방지할 수 있다.
	// Skill이 아닌 SKIll처럼 잘못쳤을때 에러를 발생하여 실수를 방지한다.
	// 부모가 가상함수(virtual)일때만 override를 붙일 수 있다.

private:
	int maxShield = 20;
	int curShield = 0;
};
