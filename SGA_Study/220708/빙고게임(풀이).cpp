// BingoGame
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define BOARD_SIZE 5
#define MIN_NUMBER 1
#define MAX_NUMBER 99
#define MAX_BINGO_COUNT 5
#define MAX_INPUT_CHANCE 30

//const : 특정 지역에서 특정 상수만 사용할 경우

enum GameState
{
	SET_BOARD,
	PRINT_BOARD,
	INPUT_NUMBER,
	CHECK_BINGO,
	GAME_CLEAR,
	GAME_OVER
};

typedef unsigned int uint;

void SetBoard(uint(*board)[BOARD_SIZE]);
uint GetRandomInRange(uint min, uint max);
uint GetBoardNum(uint count, const uint(*board)[BOARD_SIZE]);
void PrintBoard(const uint(*board)[BOARD_SIZE]);
uint InputNumberInRange(const uint(*board)[BOARD_SIZE], uint min, uint max);
void CheckInputNumber(const uint(*answerBoard)[BOARD_SIZE], uint(*inputBoard)[BOARD_SIZE], const uint inputNumber);
GameState CheckBingo(const uint(*board)[BOARD_SIZE], uint& inputCount);

int main()
{
	srand(time(0));

	uint answerBoard[BOARD_SIZE][BOARD_SIZE] = {};
	uint inputBoard[BOARD_SIZE][BOARD_SIZE] = {};

	GameState gameState = SET_BOARD;

	uint bingoCount = 0;
	uint inputCount = 0;

	int curTime = 0;
	int startTime = time(0);
	
	while(true)
	{
		switch (gameState)
		{
		case SET_BOARD:
			SetBoard(answerBoard);
			gameState = PRINT_BOARD;
			break;
		case PRINT_BOARD:
			system("cls");
			/*Sleep(100);
			curTime = time(0);
			printf("Time : %d\n", curTime - startTime);*/
			PrintBoard(answerBoard);
			PrintBoard(inputBoard);
			gameState = INPUT_NUMBER;
			break;
		case INPUT_NUMBER:
		{
			int inputNumber = InputNumberInRange(inputBoard, MIN_NUMBER, MAX_NUMBER);
			CheckInputNumber(answerBoard, inputBoard, inputNumber);
			gameState = CHECK_BINGO;
		}
			break;
		case CHECK_BINGO:
			gameState = CheckBingo(inputBoard, inputCount);
			break;
		case GAME_CLEAR:
			system("cls");
			PrintBoard(answerBoard);
			PrintBoard(inputBoard);
			printf("GameClear!\n");
			return 0;
		case GAME_OVER:
			printf("GameOver!\n");
			return 0;
		}
	}
}

void SetBoard(uint(*board)[BOARD_SIZE])
{
	/* 2차원 배열을 이용한 랜덤숫자 받기 */
	//for (uint i = 0; i < BOARD_SIZE; i++)
	//{
	//	for (uint j = 0; j < BOARD_SIZE; j++)
	//	{
	//		board[i][j] = GetBoardNum(BOARD_SIZE*i+j, board);
	//	}
	//}

	/* 1차원 배열을 이용한 랜덤숫자 받기 */
	uint count = 0;
	for (uint* p = (uint*)board; count < BOARD_SIZE * BOARD_SIZE; p++)
	{
		*p = GetBoardNum(count++, board);
	}
}

uint GetRandomInRange(uint min, uint max)
{
	return rand() % (max - min + 1) + min;
}

uint GetBoardNum(uint count, const uint(*board)[BOARD_SIZE])
{
	uint randomNum = 0;

	while (true)
	{
		randomNum = GetRandomInRange(MIN_NUMBER, MAX_NUMBER);

		bool check = false;
		for (uint i = 0; i < count; i++)
		{
			/* 1차원을 2차원으로 바꾸는 방법 */
			// i = count/5, j = count%5
			uint q = i / BOARD_SIZE; // 몫:quotient
			uint r = i % BOARD_SIZE; // 나머지:remainder

			if (board[q][r] == randomNum)
			{
				check = true; // 중복되는 경우
				break;
			}
		}
		if (!check)
			return randomNum;
	}
}

void PrintBoard(const uint(*board)[BOARD_SIZE])
{
	printf("--------------\n");
	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		for (uint j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
				printf("◎ ");
			else
				printf("%.2d ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------\n");
}

uint InputNumberInRange(const uint(*board)[BOARD_SIZE], uint min, uint max)
{
	uint inputNumber = 0;

	while (true)
	{
		printf("%d부터 %d까지의 숫자를 입력하시오.\n", min, max);
		scanf_s("%d", &inputNumber);

		if (inputNumber < min || inputNumber > max)
		{
			printf("숫자의 범위가 맞지 않습니다.\n");
			continue;
		}

		bool check = false;
		for (uint i = 0; i < BOARD_SIZE; i++)
		{
			for (uint j = 0; j < BOARD_SIZE; j++)
			{
				if (inputNumber == board[i][j])
					check = true;
			}
		}
		if (check)
		{
			printf("이미 입력한 숫자 입니다.\n");
			continue;
		}
		
		return inputNumber;
	}
}

void CheckInputNumber(const uint(*answerBoard)[BOARD_SIZE], uint(*inputBoard)[BOARD_SIZE], const uint inputNumber)
{
	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		for (uint j = 0; j < BOARD_SIZE; j++)
		{
			if (answerBoard[i][j] == inputNumber)
			{
				inputBoard[i][j] = inputNumber;
			}
		}
	}
}

GameState CheckBingo(const uint(*board)[BOARD_SIZE], uint& inputCount)
{
	int rowCount[BOARD_SIZE] = {};
	int colCount[BOARD_SIZE] = {};
	int diagonalCount[2] = {};
	int bingoCount = 0;

	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		for (uint j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] != 0)
			{
				rowCount[j]++;
				colCount[i]++;

				if (i == j)
					diagonalCount[0]++;
				if (i + j == BOARD_SIZE - 1)
					diagonalCount[1]++;
			}
		}
	}

	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		if (rowCount[i] == BOARD_SIZE)
			bingoCount++;
		if (colCount[i] == BOARD_SIZE)
			bingoCount++;
	}

	for (uint i = 0; i < 2; i++)
	{
		if (diagonalCount[i] == BOARD_SIZE)
			bingoCount++;
	}

	printf("%d번 입력했습니다.\n", ++inputCount);
	printf("BingoCount : %d\n", bingoCount);
	Sleep(1000); // 1초 멈춤

	if (bingoCount >= MAX_BINGO_COUNT)
		return GAME_CLEAR;

	if (inputCount == MAX_INPUT_CHANCE)
		return GAME_OVER;

	return PRINT_BOARD;
}
