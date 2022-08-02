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
	cout << "�������ڻ̱� ���� ���� !" << endl;
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
		cout << attempCount << "�� �õ��߽��ϴ�. ���� Ƚ���� " << ATTEMP_NUM - attempCount << "�� �Դϴ�." << endl << endl;
		if (attempCount == ATTEMP_NUM)
		{
			cout << "�õ� Ƚ���� �ʰ��߽��ϴ�." << endl;
			return GAME_OVER;
		}
	}
	return NONE;
}

bool DrawRandomNum::IsAnswer()
{
	if (inputNum == randomNum)
	{
		cout << "�����Դϴ�." << endl;
		return true;
	}
	else if (randomNum > inputNum)
	{
		cout << "�������ڰ� �� Ů�ϴ�." << endl;
		return false;
	}
	else
	{
		cout << "�������ڰ� �� �۽��ϴ�." << endl;
		return false;
	}
}

void DrawRandomNum::GetInputNum()
{
	while (true)
	{
		cout << MIN_NUM << "���� " << MAX_NUM << "������ ���ڸ� �Է��Ͻÿ� : ";
		cin >> inputNum;

		if (inputNum >= MIN_NUM && inputNum <= MAX_NUM)
			break;
		cout << "������ ������ ������ϴ�." << endl;
	}
}


