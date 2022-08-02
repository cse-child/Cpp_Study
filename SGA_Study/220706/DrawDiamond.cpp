// DrawDiamond

#include <stdio.h>

typedef unsigned int uint;

uint GetDiamondSize();
uint GetAbsolute(int value);

// 오버로딩(Overloading): 함수 이름이 같고 매개변수가 다른 경우
void PrintChar(uint size, char word);
void PrintChar(uint size, char* str);

int main()
{
	uint diamondSize = 0;
	uint halfSize = 0;

	printf("DrawDiamond!\n");

	diamondSize = GetDiamondSize();
	halfSize = diamondSize / 2;

	for (uint i = 0; i < diamondSize; i++)
	{
		uint spaceSize = GetAbsolute(halfSize - i);
		//PrintChar(spaceSize, ' ');
		char space[] = "  ";
		PrintChar(spaceSize, space);

		uint starSize = diamondSize - spaceSize * 2;
		//PrintChar(starSize, '*');
		char star[] = "★";
		PrintChar(starSize, star);
		
		printf("\n");
		
	}
	return 0;
}

uint GetDiamondSize()
{
	int size = 0;

	do {
		printf("홀수를 입력하시오 : \n");
		scanf_s("%d", &size);

		if (size % 2 == 0)
			printf("잘못입력했습니다. 다시 입력하시오.\n");
	} while (size <= 0 || size % 2 == 0);

	return size;
}

uint GetAbsolute(int value)
{
	if (value < 0)
		value *= -1;

	return value;
}

void PrintChar(uint size, char word)
{
	for (uint i = 0; i < size; i++)
		printf("%c", word);
}

void PrintChar(uint size, char* str)
{
	for (uint i = 0; i < size; i++)
		printf("%s", str);
}
