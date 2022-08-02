// Variable (변수 : 변하는 수)
#include <stdio.h>

// 변수 선언 유의사항
// 1. 같은 이름의 변수를 중복해서 선언할 수 없다.
// 2. 변수 이름 제일 앞에 숫자가 올 수 없다.
// 3. 변수 중간에 띄어쓰기를 할 수 없다.
// 4. 특수문자를 사용할 수 없다. (단, _ 제외)

// 네이밍 규칙
// 카멜 표기법 : 소문자로 시작해서 띄어쓰기 부분에서 대문자 사용 (변수 선언 시 사용)
// 파스칼 표기법 : 대문자로 시작해서 띄어쓰기 부분에서 대문자 사용 (함수, 클래스 선언 시 사용)
// 스네이크 표기법 : 대문자로 표기하고 띄어쓰기 부분에서 언더바'_' 사용 (상수 표기할 때 사용)


int main()
{
	/* 자료형 */
	// 정수형 자료형
	// char:		1byte(=8bit) → -128 ~ 127 (-2^7 ~ 2^7-1)
	// short:		2byte(=16bit) → -2^15 ~ 2^15-1
	// int:			4byte(=32bit) → -2^31 ~ 2^31-1
	// long:		4byte(=32bit) → -2^31 ~ 2^31-1
	// long long:	8byte

	// 실수형 자료형
	// float:		4byte
	// double:		8byte

	// signed & unsigned
	// 변수에는 기본적으로 signed 가 생략되어 있음
	// unsigned : 부호가 없는 수(only 양수)
	// unsigned char : 0 ~ 255
	
	const int MAX_HEALTH_POINT = 100; // 상수형
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
	float pi = 3.141592f; // float는 f 접미사, f를 안붙이면 double로 인식
	int value = 0xff; // 0x 접두사 - 16진수 표현
	int color = 0xff0000;

	printf("내 혈액형은 %c이다.\n", myBlood);
	printf("원주율 : %f\n", pi);
	printf("Value : %d\n", value);
	
	
}