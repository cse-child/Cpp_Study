// Operator (������)
#include <stdio.h>

// ������
// 1. �⺻������ (+, -, *, /, %)
// 2. ���Կ����� (=, +=, -=, *=, /=, %=)
// 3. �񱳿����� (==, <, >, <=, >=)
// 4. �������� (&&, ||)
// 5. ���������� (++, --)
// 6. ��Ʈ������ (^, >>, <<)


// ����� �ϱ�
// 1. ������ �Ǵ� �κ��� ã�Ƽ� �극��ũ ����Ʈ�� ��´�.(F9)
// 2. ������� �����Ѵ�.(F5)
// 3. �극��ũ ����Ʈ�� ������ ���߸� ���� ���� Ȯ���Ѵ�.
// (���콺�� ���� ���� �÷��� ����, ����-�ڵ� â�� Ȯ���ϱ�)
// 4. F10, F12�� �̿��Ͽ� ���� �κ����� �Ѿ�鼭 ���α׷��� ��� �귯������ Ȯ��
// (F10: �ҽ� �ٷ� �ؿ� �ٷ� �̵�)
// (F11: ���� ���� �ڵ�� �̵�)

int main()
{
	int n = 10;
	printf("n : %d\n", ++n);
	printf("n : %d\n", n);
	return 0;
}

int LosicOperator()
{
	int x, y;
	int result = 0;

	scanf_s("%d%d", &x, &y);

	//result = 3 + 5 * 3;
	result = (x < y) || (x == y);

	printf("x�� y���� �۰ų� ����? : %d\n", result);

	return 0;
}

int SubtitutionOperator()
{
	int sum = 0;

	printf("sum : %d\n", sum);

	sum += 10; // sum = sum + 10 �� ����

	printf("sum : %d\n", sum);
	
	sum += 10;

	printf("sum : %d\n", sum);

	return 0;
}
int BasicOperator()
{
	int x = 0, y = 0;
	float result = 0;

	scanf_s("%d%d", &x, &y);
	
	printf("x : %d, y : %d\n", x, y);

	// ���� / ���� : ����
	// �Ǽ� / ���� : �Ǽ�
	// �Ǽ� / �Ǽ� : �Ǽ�
	result = (float)x / y;

	// ������ ������ ������ ����
	result = x % y;

	printf("result : %f\n", result);

	return 0;
}