// while (반복문)

/* 반복문
- do~whle문: 무조건 한번은 실행
 do {
		실행문
 } while(조건문);
 
 - while문
 while(조건문)
 {
	실행문
 }

 - for문
 for(초기문;조건문;증감문)
 {
	실행문
 }

 */

#include <stdio.h>

int main()
{
	// 초기문
	int n = 0;

	//do {
	//	printf("n : %d\n", ++n);
	//} while (n < 10);

	bool isCheck = false; // true(1) or false(0)

	while (true) // 무한반복문
	{
		n++;

		if (n % 2 == 0)
			continue;
		printf("n : %d\n", n);

		if (n > 10)
			break;
	}

	return 0;
}