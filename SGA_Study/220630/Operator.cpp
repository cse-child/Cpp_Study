// Operator (연산자)
#include <stdio.h>

// 연산자
// 1. 기본연산자 (+, -, *, /, %)
// 2. 대입연산자 (=, +=, -=, *=, /=, %=)
// 3. 비교연산자 (==, <, >, <=, >=)
// 4. 논리연산자 (&&, ||)
// 5. 증감연산자 (++, --)
// 6. 비트연산자 (^, >>, <<)


// 디버깅 하기
// 1. 문제가 되는 부분을 찾아서 브레이크 포인트를 찍는다.(F9)
// 2. 디버깅을 시작한다.(F5)
// 3. 브레이크 포인트에 진행이 멈추면 변수 등을 확인한다.
// (마우스를 변수 위에 올려서 보기, 로컬-자동 창을 확인하기)
// 4. F10, F12를 이용하여 다음 부분으로 넘어가면서 프로그램이 어떻게 흘러가는지 확인
// (F10: 소스 바로 밑에 줄로 이동)
// (F11: 다음 실행 코드로 이동)

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

	printf("x가 y보다 작거나 같다? : %d\n", result);

	return 0;
}

int SubtitutionOperator()
{
	int sum = 0;

	printf("sum : %d\n", sum);

	sum += 10; // sum = sum + 10 과 동일

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

	// 정수 / 정수 : 정수
	// 실수 / 정수 : 실수
	// 실수 / 실수 : 실수
	result = (float)x / y;

	// 나머지 연산은 정수만 가능
	result = x % y;

	printf("result : %f\n", result);

	return 0;
}