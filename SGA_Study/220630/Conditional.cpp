// Conditional (조건문)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x, y;
	char c;
	scanf_s("%d %c %d", &x, &c, 1, &y);
	
	// break를 안쓰면 다음 case문이 실행됨.
	// case문 안에 {} 없이 변수 선언 안됨.
	switch (c)
	{
	case '+':
	{
		printf("%d %c %d = %d\n", x, c, y, (x+y));
	}
		break;

	case '-':
	{
		printf("%d %c %d = %d\n", x, c, y, (x - y));
	}
	break;

	case '*':
	{
		printf("%d %c %d = %d\n", x, c, y, (x * y));
	}
	break;

	case '/':
	{
		printf("%d %c %d = %d\n", x, c, y, (x / y));
	}
	break;
		
	default:
	{
		printf("해당 연산이 없습니다.\n");
	}
		break;
	}
	return 0;
}

int If()
{
	srand(time(0));
	int random = rand() % 11;

	printf("radom : %d\n", random);

	// if(조건문)
	// {
	//		// 조건문이 0이 아니면 실행
	// }
	if (random < 5)
	{
		printf("random은 5보다 작다.\n");
	}
	else if (random > 5) 
	{
		printf("random은 5보다 크다.\n");
	}
	else
	{
		printf("random은 5와 같다.\n");
	}
	return 0;
}