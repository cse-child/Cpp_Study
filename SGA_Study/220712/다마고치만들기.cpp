#include <iostream>
#include <string>

using namespace std;

enum Menu
{
	PLAY,
	SLEEP,
	WASHING,
	FEEDING,
	EXIT
};

class Pet
{
public:
	Pet()
		:hunger(50), dirty(50), tired(50), happy(50)
	{
		cout << "\t\t[ �ٸ���ġ Ű��� ]" << endl << endl;
		cout << "\t���� ���´� ������/������/�Ƿε�/�ູ�� 4����" << endl;
		cout << "������/������/�ູ���� '0' �� �ǰų� �Ƿε��� '100' �� �Ǹ� Game Over" << endl << endl;
	}

	void Play()
	{
		happy += 40;
		tired += 10;
		dirty -= 15;
		hunger -= 10;
		cout << name << "�� �ų��� ����־����ϴ� !" << endl;
		cout << "[ �ູ��/�Ƿε� ����, ������/������ ���� ]" << endl;
		PrintState();
	}

	void Sleep()
	{
		tired = 0;
		hunger -= 15;
		dirty -= 10;
		cout << name << "(��/��) ���� �ῡ �������ϴ� !" << endl;
		cout << "[ �Ƿε��� ���� ��������ϴ�. ������/������ ���� ]" << endl;
		PrintState();
	}

	void Washing()
	{
		dirty = 100;
		tired += 10;
		hunger -= 10;
		happy -= 20;

		cout << name << "(��/��) �����ϰ� �İ������ϴ� !" << endl;
		cout << "[ ������/�Ƿε� ����,/������/�ູ�� ���� ]" << endl;
		PrintState();
	}

	void Peeding()
	{
		hunger = 100;
		happy += 15;
		dirty -= 15;
		cout << name << "(��/��) ��� ��Ḧ �� �Ծ����ϴ� !" << endl;
		cout << "[ ������/�ູ�� ����, ������ ���� ]" << endl;
		PrintState();
	}

	void PrintState()
	{
		CheckState(&hunger, "������");
		CheckState(&dirty, "������");
		CheckState(&tired, "�Ƿε�");
		CheckState(&happy, "�ູ��");

		cout << endl << "----------- " << name << "(" << age << "��)�� ���� -----------" << endl;
		cout << "\t������\t\t" << hunger << endl;
		cout << "\t������\t\t" << dirty << endl;
		cout << "\t�Ƿε�\t\t" << tired << endl;
		cout << "\t�ູ��\t\t" << happy << endl;
		cout << "------------------------------------" << endl << endl;
	}

	void CheckState(int* state, string stateName)
	{
		if (*state >= 100)
			*state = 100;
		if (*state <= 0)
			*state = 0;

		if (((stateName == "������" || stateName == "������" || stateName == "�ູ��") && *state == 0)
			|| (stateName == "�Ƿε�" && *state == 100)) {
			cout << endl << stateName << " ���°� �����ʾ� " << name << "(��)�� ���������ϴ�." << endl;
			cout << "Game Over...." << endl;
			exit(0);
		}
	}

	void NewPet()
	{
		cout << "���ο� ���� �̸��� �����ּ��� : ";
		cin >> name;
		cout << name << "(��/��) ����ΰ���? ";
		cin >> age;
		cout << endl;
		PrintState();
	}

private:
	string name = "";	// �̸�
	int age;		// ����
	int hunger;		// ������
	int dirty;		// ������
	int tired;		// �Ƿε�
	int happy;		// �ູ��
};

int main()
{
	Pet pet;
	int menuNum = 0;

	pet.NewPet();

	Menu menu;

	while (true)
	{
		cout << "1.����ֱ�, 2.���ڱ�, 3.�ı�, 4.���ֱ�, 5.��������" << endl;
		cout << "��� � �ൿ�� �Ͻðڽ��ϱ�?";
		cin >> menuNum;
		cout << endl;
		menu = (Menu)(menuNum - 1);

		switch (menu)
		{
		case PLAY:
			pet.Play();
			break;
		case SLEEP:
			pet.Sleep();
			break;
		case WASHING:
			pet.Washing();
			break;
		case FEEDING:
			pet.Peeding();
			break;
		case EXIT:
			cout << "������ �����մϴ� !" << endl;
			return 0;
		}
	}
}