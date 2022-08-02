// Variable (���� : ���ϴ� ��)
#include <stdio.h>

// ���� ���� ���ǻ���
// 1. ���� �̸��� ������ �ߺ��ؼ� ������ �� ����.
// 2. ���� �̸� ���� �տ� ���ڰ� �� �� ����.
// 3. ���� �߰��� ���⸦ �� �� ����.
// 4. Ư�����ڸ� ����� �� ����. (��, _ ����)

// ���̹� ��Ģ
// ī�� ǥ��� : �ҹ��ڷ� �����ؼ� ���� �κп��� �빮�� ��� (���� ���� �� ���)
// �Ľ�Į ǥ��� : �빮�ڷ� �����ؼ� ���� �κп��� �빮�� ��� (�Լ�, Ŭ���� ���� �� ���)
// ������ũ ǥ��� : �빮�ڷ� ǥ���ϰ� ���� �κп��� �����'_' ��� (��� ǥ���� �� ���)


int main()
{
	/* �ڷ��� */
	// ������ �ڷ���
	// char:		1byte(=8bit) �� -128 ~ 127 (-2^7 ~ 2^7-1)
	// short:		2byte(=16bit) �� -2^15 ~ 2^15-1
	// int:			4byte(=32bit) �� -2^31 ~ 2^31-1
	// long:		4byte(=32bit) �� -2^31 ~ 2^31-1
	// long long:	8byte

	// �Ǽ��� �ڷ���
	// float:		4byte
	// double:		8byte

	// signed & unsigned
	// �������� �⺻������ signed �� �����Ǿ� ����
	// unsigned : ��ȣ�� ���� ��(only ���)
	// unsigned char : 0 ~ 255
	
	const int MAX_HEALTH_POINT = 100; // �����
	signed int healthPoint = 100;

	printf("HP : %d\n", healthPoint);
	healthPoint = 50;
	printf("HP : %d\n", healthPoint);

	printf("\n");

	printf("char Size: %d\n", (int)sizeof(char));
	printf("short Size: %d\n", (int)sizeof(short));
	printf("int Size: %d\n", (int)sizeof(int));
	printf("long Size: %d\n", (int)sizeof(long));
	printf("long int Size: %d\n", (int)sizeof(long int));
	printf("long long Size: %d\n", (int)sizeof(long long));
	
	printf("\n");
	
	printf("float Size: %d\n", (int)sizeof(float));
	printf("double Size: %d\n", (int)sizeof(double));

	printf("\n");

	char myBlood = 'A';
	float pi = 3.141592f; // float�� f ���̻�, f�� �Ⱥ��̸� double�� �ν�
	int value = 0xff; // 0x ���λ� - 16���� ǥ��
	int color = 0xff0000;

	printf("�� �������� %c�̴�.\n", myBlood);
	printf("������ : %f\n", pi);
	printf("Value : %d\n", value);
	
	
}