// Conditional (���ǹ�)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x, y;
	char c;
	scanf_s("%d %c %d", &x, &c, 1, &y);
	
	// break�� �Ⱦ��� ���� case���� �����.
	// case�� �ȿ� {} ���� ���� ���� �ȵ�.
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
		printf("�ش� ������ �����ϴ�.\n");
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

	// if(���ǹ�)
	// {
	//		// ���ǹ��� 0�� �ƴϸ� ����
	// }
	if (random < 5)
	{
		printf("random�� 5���� �۴�.\n");
	}
	else if (random > 5) 
	{
		printf("random�� 5���� ũ��.\n");
	}
	else
	{
		printf("random�� 5�� ����.\n");
	}
	return 0;
}