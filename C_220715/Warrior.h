#pragma once

// ��ӹ��� �� ����������
// public : �θ��� Public, Protected, Private �״�� ���
// protected : �θ��� public�� protected�� ���
// private : �θ��� ��� ���������� private�� ���

class Warrior : public Character // Character Ŭ���� ��ӹޱ�
{
public:
	Warrior();
	Warrior(string name, int attack, int defence);
	~Warrior();

	// �������̵� : �θ�(����)Ŭ������ �ִ� �Լ��� �ڽ�Ŭ�������� ������ �ϴ� ��
	virtual void ShowInfo() override;
	virtual void Damage(int damage) override;
	virtual void Skill(Character* target) override;
	// override�� �Ⱥٿ��� ��������� ���̸� �Ǽ��� ������ �� �ִ�.
	// Skill�� �ƴ� SKIlló�� �߸������� ������ �߻��Ͽ� �Ǽ��� �����Ѵ�.
	// �θ� �����Լ�(virtual)�϶��� override�� ���� �� �ִ�.

private:
	int maxShield = 20;
	int curShield = 0;
};
