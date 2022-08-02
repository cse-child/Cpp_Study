#include "Framework.h"

DrawRandomNum::DrawRandomNum() : gameResult(NONE)
{
	srand(time(NULL));
}

DrawRandomNum::~DrawRandomNum()
{
}

void DrawRandomNum::GamePlay()
{
	Sleep(1000);
	system("cls");
	cout << "랜덤숫자뽑기 게임 시작 !" << endl;
	while (!isGameExit)
	{
		if (UpDownGame())
		{
			stageLevel++;
			attempCount = 0;
			Sleep(1000);
			system("cls");
		}
	}
}

bool DrawRandomNum::UpDownGame()
{
	cout << "Stage Level " << stageLevel << endl;
	randomNum = GetRandomRange();

	while (true)
	{
		GetInputNum();
		++attempCount;

		gameResult = (GameResult)GetGameResult();

		switch (gameResult)
		{
		case DrawRandomNum::ANSWER:
			return true;
		case DrawRandomNum::GAME_OVER:
			cout << "Game Over ..." << endl;
			isGameExit = true;
			return false;
		}
	}
}

int DrawRandomNum::GetRandomRange()
{
	return rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
}

int DrawRandomNum::GetGameResult()
{
	if (IsAnswer())
	{
		return ANSWER;
	}
	else
	{
		cout << attempCount << "번 시도했습니다. 남은 횟수는 " << ATTEMP_NUM - attempCount << "번 입니다." << endl << endl;
		if (attempCount == ATTEMP_NUM)
		{
			cout << "시도 횟수를 초과했습니다." << endl;
			return GAME_OVER;
		}
	}
	return NONE;
}

bool DrawRandomNum::IsAnswer()
{
	if (inputNum == randomNum)
	{
		cout << "정답입니다." << endl;
		return true;
	}
	else if (randomNum > inputNum)
	{
		cout << "랜덤숫자가 더 큽니다." << endl;
		return false;
	}
	else
	{
		cout << "랜덤숫자가 더 작습니다." << endl;
		return false;
	}
}

void DrawRandomNum::GetInputNum()
{
	while (true)
	{
		cout << MIN_NUM << "부터 " << MAX_NUM << "까지의 숫자를 입력하시오 : ";
		cin >> inputNum;

		if (inputNum >= MIN_NUM && inputNum <= MAX_NUM)
			break;
		cout << "숫자의 범위를 벗어났습니다." << endl;
	}
}


