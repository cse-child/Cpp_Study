// 별찍기 과제
#include <stdio.h>
#include <stdlib.h>

#define MAX_MENU_NUM 4

int selectMenu();
void printStars(int selectNum);
void printRectangle(int sizeNum);
void printTriangle(int sizeNum);
void printDiamond(int sizeNum);
int getSize();

/* 별찍기 메뉴 */
enum StarMenu
{
	RECTANGLE,
	TRIANGLE,
	DIAMOND,
	EXIT
};

int main()
{
	printf("============ 별 찍기 프로그램 ============\n\n");
	while (true)
	{
		int selectNum = selectMenu();
		printStars(selectNum);
	}
	printf("=========================================\n\n");
	return 0;
}

/* 출력 도형을 선택하기 위한 메뉴 출력 및 선택 */
int selectMenu()
{
	int selectNum;

	while (true)
	{
		printf("1.사각형, 2.삼각형, 3.다이아몬드, 4.종료\n\n");
		printf(">> 메뉴를 선택하세요 : ");
		scanf_s("%d", &selectNum);

		if (selectNum < 1 || selectNum > MAX_MENU_NUM)
			printf("\n>> 잘못된 숫자입니다. 다시 입력하세요.\n\n");
		else
			return selectNum;
	}
}

/* 도형 찍기 조건문 */
void printStars(int selectNum)
{
	switch (selectNum - 1)
	{
	case RECTANGLE:
		printRectangle(getSize());
		break;
	case TRIANGLE:
		printTriangle(getSize());
		break;
	case DIAMOND:
	{
		int diamondSize = getSize();
		if (diamondSize % 2 == 0) // 홀수인지 확인
			printf(">> 다이아몬드 도형은 \'홀수\'크기를 입력해야 합니다.\n\n");

		else
			printDiamond(diamondSize);

	}
	break;
	case EXIT:
		printf("\n>> 프로그램을 종료합니다.\n");
		exit(0);
	}
}

/* 사각형 별찍기 */
void printRectangle(int sizeNum)
{
	printf("\n");
	for (int i = 0; i < sizeNum; i++)
	{
		for (int j = 0; j < sizeNum; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("\n-----------------------------------------\n\n");
}

/* 정삼각형 별찍기 */
void printTriangle(int sizeNum)
{
	printf("\n");
	for (int i = 0, k = 1; i < sizeNum; i++, k += 2) {
		for (int j = i; j < sizeNum; j++) {
			printf(" ");
		}
		for (int j = 0; j < k; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n-----------------------------------------\n\n");
}

/* 다이아몬드 별찍기 (홀수만) */
void printDiamond(int sizeNum)
{
	printf("\n");
	// 다이아몬드 윗부분
	for (int i = 0, k = 1; i < sizeNum / 2 + 1; i++, k += 2)
	{
		for (int j = i; j < sizeNum / 2; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < k; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	// 다이아몬드 아랫부분
	for (int i = 0, k = sizeNum - 2; i < sizeNum / 2; i++, k -= 2)
	{
		for (int j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < k; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n-----------------------------------------\n\n");
}

/* 도형의 크기 입력받기 */
int getSize()
{
	int size;

	while (true)
	{
		printf(">> 출력할 도형의 크기를 입력하세요 : ");
		scanf_s("%d", &size);

		if (size <= 0)
			printf("\n>> 잘못된 크기 입력입니다.\n\n");
		else
			return size;
	}
}
