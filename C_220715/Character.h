#pragma once

// �����ε� : �Լ����� ���� �Ű������� �ٸ� ���
// -�Լ� �����ε�, -������ �����ε�. -������ �����ε�

// ���漱��
class Warrior;

class Character
{
public:
	Character();
	Character(string name, int attack, int defence);
	~Character();

	// �����Լ� : ��ĳ������ ���� �� �ڽ��� �������̵� �� �Լ��� ȣ���ϰ� ���� ��� ����ϴ� ���
	virtual void ShowInfo();

	//void Attack(Warrior* warrior); 
	// �پ��� �������� ���� ������ �� �ֵ��� Character�� ����
	void Attack(Character* target);
	
	
	virtual void Damage(int damage) = 0;
	// ���� ���� �Լ� (�Լ��� =0���� �����ϴ°�)
	// : ��� �ڽ� Ŭ������ ������ ������ �ؾ��ϴ� �Լ�
	// ����: �Լ��� �ڵ��ϼ� �ȴ�.
	// ���������Լ��� ���� Ŭ������ '�߻�Ŭ����'�� �ȴ�.
	// ������ �Ǿ������� ���Ǵ� �Ǿ����� ���� ���� -> �߻���
	// �߻�Ŭ������ �Ǹ� Character��� ��ü�� �Ҵ���� �ʴ´�.
	virtual void Skill(Character* target) = 0;
	
	string GetName() { return name; }

protected: // �ڽ�(�Ļ�)Ŭ�������� ���� ����
	string name = "NoName";
	int hp = 100;
	int mp = 100;
	int attack = 0;
	int defence = 0;
};

