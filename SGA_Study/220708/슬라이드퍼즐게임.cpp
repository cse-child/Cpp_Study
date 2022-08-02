// �����̵� ���� ����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define BOARD_SIZE 4
#define X 0
#define Y 1
#define INDEX_COUNT 2 // x, y �ε��� ����
#define SHAKE_COUNT 15 // ���带 ���� Ƚ��

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
	uint answerBoard[BOARD_SIZE][BOARD_SIZE]; // ���� ������
	uint playBoard[BOARD_SIZE][BOARD_SIZE]; // ���� �÷��� ������
	int zeroIndex[INDEX_COUNT] = {0, 0}; // ���� 0�� ��ġ(x,y)
	int oldIndex[INDEX_COUNT] = { zeroIndex[X], zeroIndex[Y] }; // �̵� �� 0�� ��ġ
	int startTime = time(0);
	int curTime = time(0);

	SetIncreasingNumbers(playBoard); // �÷��� ������ �ʱ� ����
	SetIncreasingNumbers(answerBoard); // ���� ������ �ʱ� ���� (���̻� ����X)

	ShakeNumbers(playBoard, oldIndex, zeroIndex); // �������� �÷��� ������ ����

	PrintStartMessage(answerBoard); // ���� ����

	while (!CheckBoardClear(answerBoard, playBoard))
	{
		PrintArray(playBoard);
		uint dir = _getch();
		Move(dir, zeroIndex);
		SwapIndex(playBoard, oldIndex, zeroIndex);
		system("cls");
	}
	PrintArray(playBoard);
	printf("\t�� GAME CLEAR ! ��\n");
}

/* �迭�� ���������� �����ϴ� ���� �ʱ�ȭ �Լ� */
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

/* �迭 ��� �Լ� */
void PrintArray(const uint board[][BOARD_SIZE])
{
	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		printf("\t   ");
		for (uint j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
				printf("�� ");
			else
				printf("%2d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/* ������ 0�� �̵���Ű�� 0�� ��ġ�� �����ϴ� �Լ� */
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

/* 0�� �̵���Ű�� �ڸ� �ٲٱ� �Լ� */
void SwapIndex(uint board[][BOARD_SIZE], int oldIndex[], int newIndex[])
{
	uint temp = board[newIndex[X]][newIndex[Y]];
	board[newIndex[X]][newIndex[Y]] = board[oldIndex[X]][oldIndex[Y]];
	board[oldIndex[X]][oldIndex[Y]] = temp;

	oldIndex[X] = newIndex[X];
	oldIndex[Y] = newIndex[Y];
}

/* ���� �������� 0�� �̵���Ű�� ������ ���� */
void ShakeNumbers(uint board[][BOARD_SIZE], int oldIndex[], int newIndex[])
{
	for (int i = 0; i < SHAKE_COUNT; i++)
	{
		int dir = rand() % 4; // �̵��� ���� �����̱� (�����¿�)
		Move(dir, newIndex);
		SwapIndex(board, oldIndex, newIndex);
	}
}

/* ���� �޽��� */
void PrintStartMessage(uint board[][BOARD_SIZE])
{
	PrintArray(board);
	printf("���� ���� ������ �ϼ���Ű���� !\n");
	printf("\t3�� �� ����\n");
	Sleep(1000);
	printf("\t2�� �� ����\n");
	Sleep(1000);
	printf("\t1�� �� ����\n");
	Sleep(1000);
	system("cls");
}

/* ���� ����� ���� �÷��� ���� �� �Լ� */
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