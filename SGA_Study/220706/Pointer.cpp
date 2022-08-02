// Pointer 포인터 : 메모리의 주소값을 가지는 변수
// Point(er) -> 의인화

#include <stdio.h>

// Call-By-Value : 값만 참조 void Func(int a)
// Call-By-Address : 주소를 참조 void Func(int *a)
// Call-By-Reference : 변수자체를 참조 void Func(int& a);

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
	int n = 10; // 4byte 메모리가 RAM에 저장됨
	// RAM : 속도가 빠르다, 휘발성 메모리

	int* pN = &n; // &: 주소값을 반환

	//*pN = 20; // 간접참조연산자
	// *pN++; 
	// 증감연산자++은 10을 11로 변경하는것이 아닌 pN이 가진 주소값을 하나 증가시킴
	// 이때 pN은 int형 포인터이기 때문에 4byte만큼 이동함
	// 즉, *pN++을 했을때 pN이 가르키는 상수는 그대로 출력되고
	// 주소값이 10 이었다면 14로 출력됨

	printf("n : %d\n", n);
	printf("n의 주소값 : %d\n", &n);
	printf("pN : %d\n", pN);
	printf("pN이 참조하는 값 : %d\n", *pN);
	printf("pN Size : %d\n", sizeof(pN));

	double d = 3.14;

	double* pD = &d;

	printf("d Size : %d\n", sizeof(d));
	printf("pD Size : %d\n", sizeof(pD));
	// 디버그를 x64로 하기 때문에 포인터의 크기는 8byte
	// 어떤 자료형이든 포인터는 같은 크기를 갖는다.

	return 0;
}