// Class
#include <iostream>
#include <string>

using namespace std;

// ���������� : Ŭ���� �Ǵ� ����ü ���ٿ� ������ �δ� ��ɾ�
// private : Ŭ����(����ü) �������� ������ ������. (��, friend Ŭ������ ����)
// protected : ������� �� �ڽı��� ������ ������.
// public : ��� ������ ������ ������.

// default ���� ������ : �⺻������ ����Ǵ� ����������
// ����ü : public
// Ŭ���� : private

// C++�� ����ü ���ο� �Լ��� ���� �� �ִ�.
// C++���� ����ü�� Ŭ������ ���� �����ϴ�.
class Monster
{	
public:
	Monster() // ������ : ��ü�� �޸𸮰� �Ҵ�� �� ȣ��Ǵ� �Լ�
//		:name("NoName"), attack(0), hp(0)
	{
		// �� ������� �ʱ�ȭ �� ����
		// name = "NoName";
		// attack = 0;
		// hp = 0;
		cout << "���� ������ ȣ��" << endl;
	}
	~Monster() // �Ҹ��� : ��ü�� �޸𸮰� ������ �� ȣ��Ǵ� �Լ�
	{
		cout << "���� �Ҹ��� ȣ��" << endl;
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
	// ������� : Ŭ������ ����ü�ȿ� ���� ����
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