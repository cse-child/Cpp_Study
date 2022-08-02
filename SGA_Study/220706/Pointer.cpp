// Pointer ������ : �޸��� �ּҰ��� ������ ����
// Point(er) -> ����ȭ

#include <stdio.h>

// Call-By-Value : ���� ���� void Func(int a)
// Call-By-Address : �ּҸ� ���� void Func(int *a)
// Call-By-Reference : ������ü�� ���� void Func(int& a);

// Call-By-Value
void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

	printf("a : %d, b : %d\n", a, b);
}

// Call-By-Address
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	printf("a : %d, b : %d\n", *a, *b);
}

// Call-By-Reference
void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

	printf("a : %d, b : %d\n", a, b);
}

int main()
{
	int x = 10, y = 20;

	Swap(&x, &y);

	printf("x : %d, y : %d\n", x, y);
}

int Pointer()
{
	int n = 10; // 4byte �޸𸮰� RAM�� �����
	// RAM : �ӵ��� ������, �ֹ߼� �޸�

	int* pN = &n; // &: �ּҰ��� ��ȯ

	//*pN = 20; // ��������������
	// *pN++; 
	// ����������++�� 10�� 11�� �����ϴ°��� �ƴ� pN�� ���� �ּҰ��� �ϳ� ������Ŵ
	// �̶� pN�� int�� �������̱� ������ 4byte��ŭ �̵���
	// ��, *pN++�� ������ pN�� ����Ű�� ����� �״�� ��µǰ�
	// �ּҰ��� 10 �̾��ٸ� 14�� ��µ�

	printf("n : %d\n", n);
	printf("n�� �ּҰ� : %d\n", &n);
	printf("pN : %d\n", pN);
	printf("pN�� �����ϴ� �� : %d\n", *pN);
	printf("pN Size : %d\n", sizeof(pN));

	double d = 3.14;

	double* pD = &d;

	printf("d Size : %d\n", sizeof(d));
	printf("pD Size : %d\n", sizeof(pD));
	// ����׸� x64�� �ϱ� ������ �������� ũ��� 8byte
	// � �ڷ����̵� �����ʹ� ���� ũ�⸦ ���´�.

	return 0;
}