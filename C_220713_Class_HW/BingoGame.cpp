#include "Framework.h"

BingoGame::BingoGame() : gameState(SET_BOARD)
{
	srand(time(NULL));
}

BingoGame::~BingoGame()
{
}

void BingoGame::GamePlay()
{
	cout << "빙고게임 시작 !" << endl;
	while (!isGameExit)
	{
		switch (gameState)
		{
		case BingoGame::SET_BOARD:
			SetBoard();
			gameState = PRINT_BOARD;
			break;
		case BingoGame::PRINT_BOARD:
			system("cls");
			PrintBoard(answerBoard);
			PrintBoard(inputBoard);
			gameState = INPUT_NUMBER;
			break;
		case BingoGame::INPUT_NUMBER:
			InputNumberInRange();
			CheckInputNumber();
			gameState = CHECK_BINGO;
			break;
		case BingoGame::CHECK_BINGO:
			gameState = (GameState)CheckBingo();
			break;
		case BingoGame::GAME_CLEAR:
			system("cls");
			PrintBoard(answerBoard);
			PrintBoard(inputBoard);
			cout << "Game Clear !" << endl;
			isGameExit = true;
			break;
		case BingoGame::GAME_OVER:
			cout << "Game Over ...." << endl;
			isGameExit = true;
			break;
		}
	}
}

void BingoGame::SetBoard()
{
	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		for (uint j = 0; j < BOARD_SIZE; j++)
		{
			answerBoard[i][j] = GetBoardNum(BOARD_SIZE*i+j);
		}
	}
}

uint BingoGame::GetRandomInRange()
{
	return rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
}

uint BingoGame::GetBoardNum(uint count)
{
	uint randomNum = 0;
	while (true)
	{
		randomNum = GetRandomInRange();
		bool check = false;

		for (uint i = 0; i < count; i++)
		{
			uint q = i / BOARD_SIZE; // 몫:quotient
			uint r = i % BOARD_SIZE; // 나머지:remainder

			if (answerBoard[q][r] == randomNum)
			{
				check = true; // 중복되는 경우
				break;
			}
		}
		if (!check)
			return randomNum;
	}
}

void BingoGame::PrintBoard(const uint(*board)[BOARD_SIZE])
{
	cout << "--------------" << endl;
	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		for (uint j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
				cout << "◎ ";
			else
				printf("%.2d ", board[i][j]);
		}
		printf("\n");
	}
	cout << "--------------" << endl;
}

void BingoGame::InputNumberInRange()
{
	while (true)
	{
		cout << MIN_NUMBER << "부터 " << MAX_NUMBER << "까지의 숫자를 입력하시오 : ";
		cin >> inputNumber;

		if (inputNumber < MIN_NUMBER || inputNumber > MAX_NUMBER)
		{
			cout << "숫자의 범위가 맞지 않습니다." << endl;
			continue;
		}

		bool check = false;
		for (uint i = 0; i < BOARD_SIZE; i++)
		{
			for (uint j = 0; j < BOARD_SIZE; j++)
			{
				if (inputNumber == inputBoard[i][j])
					check = true;
			}
		}
		if (check)
		{
			cout << "이미 입력한 숫자 입니다." << endl;
			continue;
		}
		break;
	}
}

void BingoGame::CheckInputNumber()
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

uint BingoGame::CheckBingo()
{
	int rowCount[BOARD_SIZE] = {};
	int colCount[BOARD_SIZE] = {};
	int diagonalCount[2] = {};
	int bingoCount = 0;

	for (uint i = 0; i < BOARD_SIZE; i++)
	{
		for (uint j = 0; j < BOARD_SIZE; j++)
		{
			if (inputBoard[i][j] != 0)
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

	cout << ++inputCount << "번 입력했습니다." << endl;
	cout << "BingoCount : " << bingoCount << endl;
	Sleep(1000); // 1초 멈춤

	if (bingoCount >= MAX_BINGO_COUNT)
		return GAME_CLEAR;

	if (inputCount == MAX_INPUT_CHANCE)
		return GAME_OVER;

	return PRINT_BOARD;
}
