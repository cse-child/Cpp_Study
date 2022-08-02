// �������
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 5			
#define MIN_NUMBER 1
#define MAX_NUMBER 100
#define CHANCE 5

typedef unsigned int uint;

void SetRandomNumbers(uint arr[][LENGTH]);
void PrintArray(const uint arr[][LENGTH]);
uint GetRandomRange(const uint min, const uint max);
void ChangeNumToZero(uint arr[][LENGTH], const uint inputNum);
int CheckBingo(const uint arr[][LENGTH]);

int main()
{
	srand(time(NULL));
	uint arr[LENGTH][LENGTH] = {};
	uint inputNum = 0;
	uint bingoCount = 0;
	uint playCount = 0;

	printf("================ ������� ================\n");
	printf("\t   [ �־��� Ƚ�� %d ȸ ]\n", CHANCE);
	SetRandomNumbers(arr);
	PrintArray(arr);

	while (true)
	{
		if (playCount == CHANCE)
		{
			printf(">> �־��� Ƚ���� ��� �����Ͽ����ϴ�.\n");
			printf(">> GAME OVER..\n");
			break;
		}
		printf(">> ���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &inputNum);

		ChangeNumToZero(arr, inputNum);
		PrintArray(arr);

		bingoCount = CheckBingo(arr);
		printf(">> Bingo Count : %d\n", bingoCount);
		if (bingoCount >= 5)
		{
			printf("\n�� BINGO GAME CLEAR ��\n");
			break;
		}
		++playCount;
	}
	return 0;
}

/* 1~100 ������ �������� �ߺ����� ���� */
void SetRandomNumbers(uint arr[][LENGTH])
{
	uint tmpArr[LENGTH * LENGTH] = {}; // 2���� �迭�� ���Ұ��� ũ���� 1���� �迭 ����

	for (uint i = 0; i < LENGTH * LENGTH; i++)
	{
		tmpArr[i] = GetRandomRange(MIN_NUMBER, MAX_NUMBER);
		for (uint j = 0; j < i; j++)
		{
			if (tmpArr[i] == tmpArr[j]) // 1���� �迭�� �ߺ����� ����
			{
				--i;
				break;
			}
		}
	}
	for (uint i = 0, tmpIndex = 0; i < LENGTH; i++)
	{
		for (uint j = 0; j < LENGTH; j++, tmpIndex++)
		{
			arr[i][j] = tmpArr[tmpIndex]; // 2���� �迭�� 1���� �迭�� ���Ұ� ����
		}
	}
}

/* 2���� �迭 ��� */
void PrintArray(const uint arr[][LENGTH])
{
	printf("\n\t���ѤѤѤѤѤѤѤѤѤѤѦ�\n");
	for (uint i = 0; i < LENGTH; i++)
	{
		printf("\t��");
		for (uint j = 0; j < LENGTH; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf(" ��\n");
	}
	printf("\t���ѤѤѤѤѤѤѤѤѤѤѦ�\n\n");
}

/* �־��� �ִ� �ּ� ������� ���� ���� */
uint GetRandomRange(const uint min, const uint max)
{
	return rand() % (max - min + 1) + min;
}

/* �����ǿ� �Է��� ���ڿ� ���� ���� �ִٸ� 0���� ���� */
void ChangeNumToZero(uint arr[][LENGTH], const uint inputNum)
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (arr[i][j] == inputNum)
			{
				arr[i][j] = 0;
			}
		}
	}
}

/* ���� üũ */
int CheckBingo(const uint arr[][LENGTH])
{
	int bingoCount = 0;
	bool rowBingo = true; // �� �˻�
	bool colBingo = true; // �� �˻�
	bool leftCrossBingo = true; // ���� �밢�� �˻�
	bool rightCrossBingo = true; // ������ �밢�� �˻�

	for (int i = 0; i < LENGTH; i++)
	{
		rowBingo = true;
		colBingo = true;
		for (int j = 0; j < LENGTH; j++)
		{
			if (arr[i][j] != 0)
				rowBingo = false;

			if (arr[j][i] != 0)
				colBingo = false;
		}
		if (rowBingo)
			++bingoCount;
		if (colBingo)
			++bingoCount;
	}

	for (int i = 0; i < LENGTH; i++)
	{
		if (arr[i][i] != 0)
			leftCrossBingo = false;

		if (arr[i][LENGTH - 1 - i] != 0)
			rightCrossBingo = false;

	}
	if (leftCrossBingo)
		++bingoCount;
	if (rightCrossBingo)
		++bingoCount;

	return bingoCount;
}

