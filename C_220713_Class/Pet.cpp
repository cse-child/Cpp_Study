#include "Framework.h"

Pet::Pet()
{
	CreateName();
}

Pet::~Pet()
{
	cout << name << "�� �����߽��ϴ�." << endl;
}

void Pet::Eat()
{
	cout << "�Ļ�ð�! �ȳ�����!\n";
	CalcState(hunger, -20, -40);
	CalcState(clean, -10, -30);
	CalcState(hp, 20, 40);

	IncreaseExp(50);
}

void Pet::Play()
{
	cout << "�ų���!!!\n";
	CalcState(hunger, 40, 60);
	CalcState(clean, -30, -50);
	CalcState(hp, -40, -60);

	IncreaseExp(300);
}

void Pet::Shower()
{
	cout << "�����Ͻ�!!!\n";
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
	cout << "ü�� : " << hp << endl;
	cout << "����� : " << hunger<< endl;
	cout << "û�ᵵ : " << clean << endl;
}

bool Pet::IsDead()
{
	if (hp <= MIN_STATE)
	{
		cout << "���� ���� ��" << endl;
		return true;
	}
	else if (hunger <= MIN_STATE)
	{
		cout << "��ҷ��� ���� ��" << endl;
		return true;
	}
	else if (hunger >= MAX_STATE)
	{
		cout << "����ļ� ���� ��" << endl;
		return true;
	}
	else if (clean <= MIN_STATE)
	{
		cout << "�巯���� ���� ��" << endl;
		return true;
	}
	return false;
}

void Pet::CreateName()
{
	cout << "���� �̸��� �����ּ���\n";
	cin >> name;

	cout << name << "�� ź���߽��ϴ�.\n";

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
	// this ������ : �ڱ� �ڽ��� �ּҰ��� ������ ������
	// this->exp == (*this).exp
	this->exp = exp;

	//cout << "This Pointer : " << this << endl;

	if (age * MAX_STATE <= this->exp)
	{
		this->exp -= age * MAX_STATE;
		age++;
		cout << name << "�� �ѻ� �� �Ծ " << age << "���� �Ǿ����ϴ�." << endl;
	}
}
