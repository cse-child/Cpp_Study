// Slide Puzzle Game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define BOARD_SIZE 4
#define SHUFFLE_COUNT 10

enum GameState
{
	SET_BOARD,
	SHUFFLE,
	PRINT_BOARD,
	INPUT_MOVE,
	CHECK_BOARD,
	GAME_CLEAR
};

enum Direction
{
	//UP = 'w',
	//DOWN = 's',
	//LEFT = 'a',
	//RIGHT = 'd'

	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};

typedef unsigned int uint;

struct Point
{
	uint x = 0, y = 0;
};

uint puzzleBoard[BOARD_SIZE][BOARD_SIZE] = {};

void SetBoard();
void PrintBoard();
void MoveSpace(Point* pos, Direction dir);
void Swap(uint& x, uint& y);
void InputDirection(Point* pos);
void ShuffleBoard(Point* pos);
GameState CheckBoard();

int main()
{
	srand(time(0));

	GameState gameState = SET_BOARD;
	Point spacePos = {};

	while (true)
	{
		switch (gameState)
		{
		case SET_BOARD:
			SetBoard();
			gameState = SHUFFLE;
			break;
		case SHUFFLE:
			ShuffleBoard(&spacePos);
			gameState = PRINT_BOARD;
			break;
		case PRINT_BOARD:
			PrintBoard();
			gameState = INPUT_MOVE;
			break;
		case INPUT_MOVE:
			InputDirection(&spacePos);
			gameState = CHECK_BOARD;
			break;
		case CHECK_BOARD:
			gameState = CheckBoard();
			break;
		case GAME_CLEAR:
			PrintBoard();
			printf("Game Clear!\n");
			return 0;
		}
	}
}

void SetBoard()
{
	for (uint y = 0; y < BOARD_SIZE; y++)
	{
		for (uint x = 0; x < BOARD_SIZE; x++)
		{
			int index = y * BOARD_SIZE + x; // 2차원을 1차원으로 변경
			puzzleBoard[y][x] = index;
		}
	}
}

void PrintBoard()
{
	system("cls");

	for (uint y = 0; y < BOARD_SIZE; y++)
	{
		for (uint x = 0; x < BOARD_SIZE; x++)
		{
			if (puzzleBoard[y][x]) // 0이 아니면 숫자 출력
				printf("%2d ", puzzleBoard[y][x]);
			else // 0이면 특수문자 출력
				printf("□ ");
		}
		printf("\n");
	}
}

void MoveSpace(Point* pos, Direction dir)
{
	switch (dir)
	{
	case UP:
		if (pos->y == 0) return;

		Swap(puzzleBoard[pos->y][pos->x], puzzleBoard[pos->y - 1][pos->x]);
		pos->y--;
		break;
	case DOWN:
		if (pos->y == BOARD_SIZE - 1) return;
		Swap(puzzleBoard[pos->y][pos->x], puzzleBoard[pos->y + 1][pos->x]);
		pos->y++;
		break;
	case LEFT:
		if (pos->x == 0) return;
		Swap(puzzleBoard[pos->y][pos->x], puzzleBoard[pos->y][pos->x-1]);
		pos->x--;
		break;
	case RIGHT:
		if (pos->x == BOARD_SIZE - 1) return;
		Swap(puzzleBoard[pos->y][pos->x], puzzleBoard[pos->y][pos->x+1]);
		pos->x++;
		break;
	}
}

void Swap(uint& x, uint& y)
{
	uint temp = x;
	x = y;
	y = temp;
}

void InputDirection(Point* pos)
{
	char direction;

	printf("움직일 방향을 입력하시오.\n");
	// scanf_s("%c", &direction);

	while (true)
	{
		if (_kbhit()) // 키보드가 눌러졌는지 체크
		{
			direction = _getch(); // 어떤 키가 눌러졌는지 반환
			break;
		}
	}
	MoveSpace(pos, (Direction)direction);
}

void ShuffleBoard(Point* pos)
{
	for (uint i = 0; i < SHUFFLE_COUNT; i++)
	{
		uint random = rand() % 4;

		switch (random)
		{
		case 0:
			MoveSpace(pos, UP);
			break;
		case 1:
			MoveSpace(pos, DOWN);
			break;
		case 2:
			MoveSpace(pos, LEFT);
			break;
		case 3:
			MoveSpace(pos, RIGHT);
			break;
		}
	}
}

GameState CheckBoard()
{
	for (uint y = 0; y < BOARD_SIZE; y++)
	{
		for (uint x = 0; x < BOARD_SIZE; x++)
		{
			int index = y * BOARD_SIZE + x;
			if (puzzleBoard[y][x] != index)
				return PRINT_BOARD;
		}
	}
	return GAME_CLEAR;
}
