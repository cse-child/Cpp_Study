// Class
#include <iostream>
#include <string>

using namespace std;

// 접근지정자 : 클래스 또는 구조체 접근에 제한을 두는 명령어
// private : 클래스(구조체) 내에서만 접근이 가능함. (단, friend 클래스는 제외)
// protected : 상속했을 때 자식까지 접근이 가능함.
// public : 모든 곳에서 접근이 가능함.

// default 접근 지정자 : 기본적으로 적용되는 접근지정자
// 구조체 : public
// 클래스 : private

// C++은 구조체 내부에 함수를 만들 수 있다.
// C++에서 구조체는 클래스와 거의 동일하다.
class Monster
{	
public:
	Monster() // 생성자 : 객체의 메모리가 할당될 때 호출되는 함수
//		:name("NoName"), attack(0), hp(0)
	{
		// 이 방법으론 초기화 잘 안함
		// name = "NoName";
		// attack = 0;
		// hp = 0;
		cout << "몬스터 생성자 호출" << endl;
	}
	~Monster() // 소멸자 : 객체의 메모리가 해제될 때 호출되는 함수
	{
		cout << "몬스터 소멸자 호출" << endl;
	}

	void InputData()
	{
		cout << "Name : ";
		cin >> name;
		cout << "Attack : ";
		cin >> attack;
		cout << "HP : ";
		cin >> hp;
	}

	void PrintData()
	{
		cout << "Name : " << name << endl;
		cout << "Attack : " << attack << endl;
		cout << "HP : " << hp << endl;
	}

private:
	// 멤버변수 : 클래스나 구조체안에 쓰는 변수
	string name = "NoName";
	int attack = 0;
	int hp = 0;
};

int main()
{
	Monster monster;

	//monster.InputData();
	monster.PrintData();
}