// ����� ����
#include <stdio.h>
#include <stdlib.h>

#define MAX_MENU_NUM 4

int selectMenu();
void printStars(int selectNum);
void printRectangle(int sizeNum);
void printTriangle(int sizeNum);
void printDiamond(int sizeNum);
int getSize();

/* ����� �޴� */
enum StarMenu
{
	RECTANGLE,
	TRIANGLE,
	DIAMOND,
	EXIT
};

int main()
{
	printf("============ �� ��� ���α׷� ============\n\n");
	while (true)
	{
		int selectNum = selectMenu();
		printStars(selectNum);
	}
	printf("=========================================\n\n");
	return 0;
}

/* ��� ������ �����ϱ� ���� �޴� ��� �� ���� */
int selectMenu()
{
	int selectNum;

	while (true)
	{
		printf("1.�簢��, 2.�ﰢ��, 3.���̾Ƹ��, 4.����\n\n");
		printf(">> �޴��� �����ϼ��� : ");
		scanf_s("%d", &selectNum);

		if (selectNum < 1 || selectNum > MAX_MENU_NUM)
			printf("\n>> �߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n\n");
		else
			return selectNum;
	}
}

/* ���� ��� ���ǹ� */
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
		if (diamondSize % 2 == 0) // Ȧ������ Ȯ��
			printf(">> ���̾Ƹ�� ������ \'Ȧ��\'ũ�⸦ �Է��ؾ� �մϴ�.\n\n");

		else
			printDiamond(diamondSize);

	}
	break;
	case EXIT:
		printf("\n>> ���α׷��� �����մϴ�.\n");
		exit(0);
	}
}

/* �簢�� ����� */
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

/* ���ﰢ�� ����� */
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

/* ���̾Ƹ�� ����� (Ȧ����) */
void printDiamond(int sizeNum)
{
	printf("\n");
	// ���̾Ƹ�� ���κ�
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
	// ���̾Ƹ�� �Ʒ��κ�
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

/* ������ ũ�� �Է¹ޱ� */
int getSize()
{
	int size;

	while (true)
	{
		printf(">> ����� ������ ũ�⸦ �Է��ϼ��� : ");
		scanf_s("%d", &size);

		if (size <= 0)
			printf("\n>> �߸��� ũ�� �Է��Դϴ�.\n\n");
		else
			return size;
	}
}
