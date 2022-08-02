// 빙고게임
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

	printf("================ 빙고게임 ================\n");
	printf("\t   [ 주어진 횟수 %d 회 ]\n", CHANCE);
	SetRandomNumbers(arr);
	PrintArray(arr);

	while (true)
	{
		if (playCount == CHANCE)
		{
			printf(">> 주어진 횟수를 모두 소진하였습니다.\n");
			printf(">> GAME OVER..\n");
			break;
		}
		printf(">> 숫자를 입력하세요 : ");
		scanf_s("%d", &inputNum);

		ChangeNumToZero(arr, inputNum);
		PrintArray(arr);

		bingoCount = CheckBingo(arr);
		printf(">> Bingo Count : %d\n", bingoCount);
		if (bingoCount >= 5)
		{
			printf("\n★ BINGO GAME CLEAR ★\n");
			break;
		}
		++playCount;
	}
	return 0;
}

/* 1~100 사이의 랜덤숫자 중복없이 생성 */
void SetRandomNumbers(uint arr[][LENGTH])
{
	uint tmpArr[LENGTH * LENGTH] = {}; // 2차원 배열의 원소개수 크기의 1차원 배열 생성

	for (uint i = 0; i < LENGTH * LENGTH; i++)
	{
		tmpArr[i] = GetRandomRange(MIN_NUMBER, MAX_NUMBER);
		for (uint j = 0; j < i; j++)
		{
			if (tmpArr[i] == tmpArr[j]) // 1차원 배열을 중복없이 생성
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
			arr[i][j] = tmpArr[tmpIndex]; // 2차원 배열에 1차원 배열의 원소값 저장
		}
	}
}

/* 2차원 배열 출력 */
void PrintArray(const uint arr[][LENGTH])
{
	printf("\n\t┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐\n");
	for (uint i = 0; i < LENGTH; i++)
	{
		printf("\t｜");
		for (uint j = 0; j < LENGTH; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf(" ｜\n");
	}
	printf("\t└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘\n\n");
}

/* 주어진 최대 최소 범위대로 난수 생성 */
uint GetRandomRange(const uint min, const uint max)
{
	return rand() % (max - min + 1) + min;
}

/* 빙고판에 입력한 숫자와 같은 수가 있다면 0으로 변경 */
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

/* 빙고 체크 */
int CheckBingo(const uint arr[][LENGTH])
{
	int bingoCount = 0;
	bool rowBingo = true; // 행 검사
	bool colBingo = true; // 열 검사
	bool leftCrossBingo = true; // 왼쪽 대각선 검사
	bool rightCrossBingo = true; // 오른쪽 대각선 검사

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

