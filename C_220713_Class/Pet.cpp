#include "Framework.h"

Pet::Pet()
{
	CreateName();
}

Pet::~Pet()
{
	cout << name << "이 퇴장했습니다." << endl;
}

void Pet::Eat()
{
	cout << "식사시간! 냠냠쩝쩝!\n";
	CalcState(hunger, -20, -40);
	CalcState(clean, -10, -30);
	CalcState(hp, 20, 40);

	IncreaseExp(50);
}

void Pet::Play()
{
	cout << "신난다!!!\n";
	CalcState(hunger, 40, 60);
	CalcState(clean, -30, -50);
	CalcState(hp, -40, -60);

	IncreaseExp(300);
}

void Pet::Shower()
{
	cout << "쓱쓱싹싹!!!\n";
	CalcState(hunger, 10, 30);
	CalcState(clean, 60, 80);
	CalcState(hp, -10, -20);

	IncreaseExp(30);
}

void Pet::Sleep()
{
	cout << "Zzzzzzzzzzzzz....\n";
	CalcState(hunger, 20, 40);
	CalcState(clean, -20, -40);
	CalcState(hp, 60, 80);

	IncreaseExp(100);
}

void Pet::ShowInfo()
{
	cout << "ShowInfo" << endl;
	cout << "Name : " << name << endl;
	cout << "Age : " << age << endl;
	cout << "Exp : " << exp << endl;
	cout << "체력 : " << hp << endl;
	cout << "배고픔 : " << hunger<< endl;
	cout << "청결도 : " << clean << endl;
}

bool Pet::IsDead()
{
	if (hp <= MIN_STATE)
	{
		cout << "힘들어서 죽음 ㅠ" << endl;
		return true;
	}
	else if (hunger <= MIN_STATE)
	{
		cout << "배불러서 죽음 ㅠ" << endl;
		return true;
	}
	else if (hunger >= MAX_STATE)
	{
		cout << "배고파서 죽음 ㅠ" << endl;
		return true;
	}
	else if (clean <= MIN_STATE)
	{
		cout << "드러워서 죽음 ㅠ" << endl;
		return true;
	}
	return false;
}

void Pet::CreateName()
{
	cout << "펫의 이름을 지어주세요\n";
	cin >> name;

	cout << name << "이 탄생했습니다.\n";

	age++;
}

int Pet::Clamp(int value, const int& min, const int& max)
{
	if (value < min)
		value = min;

	if (value > max)
		value = max;

	return value;
}

int Pet::RandomInRange(const int& min, const int& max)
{
	return rand() % (max - min + 1) + min;
}

void Pet::CalcState(int& value, const int& min, const int& max)
{
	value += RandomInRange(min, max);

	value = Clamp(value, MIN_STATE, MAX_STATE);
}

void Pet::IncreaseExp(const uint& exp)
{
	// this 포인터 : 자기 자신의 주소값을 가지는 포인터
	// this->exp == (*this).exp
	this->exp = exp;

	//cout << "This Pointer : " << this << endl;

	if (age * MAX_STATE <= this->exp)
	{
		this->exp -= age * MAX_STATE;
		age++;
		cout << name << "이 한살 더 먹어서 " << age << "살이 되었습니다." << endl;
	}
}
