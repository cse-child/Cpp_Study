// 슬라이드 퍼즐 게임
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define BOARD_SIZE 4
#define X 0
#define Y 1
#define INDEX_COUNT 2 // x, y 인덱스 개수
#define SHAKE_COUNT 15 // 보드를 섞을 횟수

typedef unsigned int uint;

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

void SetIncreasingNumbers(uint board[][BOARD_SIZE]);
void ShakeNumbers(uint board[][BOARD_SIZE], int oldIndex[], int newIndex[]);
void PrintStartMessage(uint board[][BOARD_SIZE]);
void PrintArray(const uint board[][BOARD_SIZE]);
void Move(uint dir, int zeroIndex[]);
void SwapIndex(uint board[][BOARD_SIZE], int oldIndex[], int newIndex[]);
bool CheckBoardClear(const uint answerBoard[][BOARD_SIZE], const uint playBoard[][BOARD_SIZE]);

int main()
{
	srand(time(NULL));
	uint answerBoard[BOARD_SIZE][BOARD_SIZE]; // 정답 보드판
	uint playBoard[BOARD_SIZE][BOARD_SIZE]; // 현재 플레이 보드판
	int zeroIndex[INDEX_COUNT] = {0, 0}; // 현재 0의 위치(x,y)
	int oldIndex[INDEX_COUNT] = { zeroIndex[X], zeroIndex[Y] }; // 이동 전 0의 위치
	int startTime = time(0);
	int curTime = time(0);

	SetIncreasingNumbers(playBoard); // 플레이 보드판 초기 셋팅
	SetIncreasingNumbers(answerBoard); // 정답 보드판 초기 셋팅 (더이상 변경X)

	ShakeNumbers(playBoard, oldIndex, zeroIndex); // 랜덤으로 플레이 보드판 섞기

	PrintStartMessage(answerBoard); // 시작 문구

	while (!CheckBoardClear(answerBoard, playBoard))
	{
		PrintArray(playBoard);
		uint dir = _getch();
		Move(dir, zeroIndex);
		SwapIndex(playBoard, oldIndex, zeroIndex);
		system("cls");
	}
	PrintArray(playBoard);
	printf("\t★ GAME CLEAR ! ★\n");
}

/* 배열에 순차적으로 증가하는 숫자 초기화 함수 */
void SetIncreasingNumbers(uint board[][BOARD_SIZE])
{
	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		for (uint j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = BOARD_SIZE * i + j;
		}
	}
}

/* 배열 출력 함수 */
void PrintArray(const uint board[][BOARD_SIZE])
{
	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		printf("\t   ");
		for (uint j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
				printf("◎ ");
			else
				printf("%2d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/* 방향대로 0을 이동시키고 0의 위치를 저장하는 함수 */
void Move(uint dir, int zeroIndex[])
{
	switch (dir)
	{
	case LEFT:
	case 'a':
	case 'A':
		--zeroIndex[Y];
		if (zeroIndex[Y] < 0)
			zeroIndex[Y] = 0;
		break;
	case RIGHT:
	case 'd':
	case 'D':
		++zeroIndex[Y];
		if (zeroIndex[Y] > BOARD_SIZE - 1)
			zeroIndex[Y] = BOARD_SIZE - 1;
		break;
	case UP:
	case 'w':
	case 'W':
		--zeroIndex[X];
		if (zeroIndex[X] < 0)
			zeroIndex[X] = 0;
		break;
	case DOWN:
	case 's':
	case 'S':
		++zeroIndex[X];
		if (zeroIndex[X] > BOARD_SIZE - 1)
			zeroIndex[X] = BOARD_SIZE - 1;
		break;
	}
}

/* 0을 이동시키며 자리 바꾸기 함수 */
void SwapIndex(uint board[][BOARD_SIZE], int oldIndex[], int newIndex[])
{
	uint temp = board[newIndex[X]][newIndex[Y]];
	board[newIndex[X]][newIndex[Y]] = board[oldIndex[X]][oldIndex[Y]];
	board[oldIndex[X]][oldIndex[Y]] = temp;

	oldIndex[X] = newIndex[X];
	oldIndex[Y] = newIndex[Y];
}

/* 랜덤 방향으로 0을 이동시키며 보드판 섞기 */
void ShakeNumbers(uint board[][BOARD_SIZE], int oldIndex[], int newIndex[])
{
	for (int i = 0; i < SHAKE_COUNT; i++)
	{
		int dir = rand() % 4; // 이동할 방향 랜덤뽑기 (상하좌우)
		Move(dir, newIndex);
		SwapIndex(board, oldIndex, newIndex);
	}
}

/* 시작 메시지 */
void PrintStartMessage(uint board[][BOARD_SIZE])
{
	PrintArray(board);
	printf("위와 같은 퍼즐을 완성시키세요 !\n");
	printf("\t3초 후 시작\n");
	Sleep(1000);
	printf("\t2초 후 시작\n");
	Sleep(1000);
	printf("\t1초 후 시작\n");
	Sleep(1000);
	system("cls");
}

/* 정답 보드와 현재 플레이 보드 비교 함수 */
bool CheckBoardClear(const uint answerBoard[][BOARD_SIZE], const uint playBoard[][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (answerBoard[i][j] != playBoard[i][j])
				return false;
		}
	}
	return true;
}