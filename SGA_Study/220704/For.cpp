// For
#include <stdio.h>

// for(초기문;조건문;증감문)
// {
//		실행문;
// }

int main()
{
	int size = 0;
	printf("Size : ");
	scanf_s("%d", &size);

	// 사각형
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("★");
		}
		printf("\n");
	}

	printf("\n");

	// 삼각형
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		//for (int j = size - i - 1; j < size; j++)
		{
			printf("★");
		}
		printf("\n");
	}

	printf("\n");

	// 역삼각형
	for (int i = 0; i < size; i++)
	{
		for (int j = size; j > i; j--)
		//for (int j = i; j < size; j++)
		{
			printf("★");
		}
		printf("\n");
	}

	printf("\n");

	// 역삼각형2
	// ***
	//  **
	//   *
	for (int i = 0; i < size; i++)
	{
		/*for (int j = 1; j <= i; j++)
		{
			printf("  ");
		}
		for (int j = i; j < size; j++)
		{
			printf("★");
		}*/

		for (int j = 0; j < size; j++)
		{
			if (j < i)
				printf("  ");
			else
				printf("★");
		}
		printf("\n");
	}


	// 정삼각형
	for (int i = 0, k = 1; i < size; i++, k+=2) {
		for (int j = i; j < size; j++) {
			printf(" ");
		}
		for (int j = 0; j < k; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	// 다이아몬드
	for (int i = 0, k = 1; i <= size/2; i++, k+=2)
	{
		for (int j = i; j < size/2; j++)
		{
			printf("?");
		}
		for (int j = 0; j < k; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = 0, k = size/2+1; i < size / 2; i++, k -= 2)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("!");
		}
		for (int j = 0; j < k; j++)
		{
			printf("*");
		}
		printf("\n");
	}


	printf("\n");

}


void TimesTable()
{
	for (int i = 2; i < 10; i++)
	{
		printf("구구단 %d단\n", i);
		for (int j = 1; j < 10; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);
		}
	}
}