#include "Framework.h"

RockScissorsPaper::RockScissorsPaper() : gameMode(MENU)
{
	srand(time(NULL));
}

RockScissorsPaper::~RockScissorsPaper()
{
}

void RockScissorsPaper::GetGameMode()
{
	uint selectMenu;
	Sleep(1000);
	system("cls");
	cout << "\n가위바위보 게임 시작!" << endl;
	cout << "1.게임시작, 2. 게임종료 : ";
	cin >> selectMenu;
	cout << endl;

	gameMode = (GameMode)selectMenu;
}

void RockScissorsPaper::GamePlay()
{
	randomNum = rand() % MAX_INPUT_NUM + 1;
	GetPlayerInputNum();

	cout << "플레이어는 ";
	PrintRockScissorsPaper(playerNum);

	cout << "컴퓨터는 ";
	PrintRockScissorsPaper(randomNum);

	PrintGameResult();

	gameMode = MENU;
}

void RockScissorsPaper::GetPlayerInputNum()
{
	while (true)
	{
		cout << "다음 중 하나를 선택하시오." << endl;
		cout << "1.가위, 2.바위, 3.보 : ";

		cin >> playerNum;

		if (playerNum < 1 || playerNum > MAX_INPUT_NUM)
		{
			cout << "잘못 입력했습니다." << endl;
			continue;
		}
		break;
	}
}

void RockScissorsPaper::PrintRockScissorsPaper(uint selectNum)
{
	switch (selectNum)
	{
	case 1:
		printf("가위를 냈습니다.\n");
	break;
	case 2:
		printf("바위를 냈습니다.\n");
	break;
	case 3:
		printf("보를 냈습니다.\n");
	break;
	}
}

void RockScissorsPaper::PrintGameResult()
{
	cout << ">> 게임 결과 : ";

	if (playerNum == randomNum)
	{
		cout << "비겼습니다." << endl;
	}
	else if ((playerNum % MAX_INPUT_NUM) + 1 == randomNum)
	{
		cout << "졌습니다." << endl;
	}
	else
	{
		cout << "이겼습니다." << endl;
	}
}

void RockScissorsPaper::GameState()
{
	while (!isGameExit)
	{
		switch (gameMode)
		{
		case RockScissorsPaper::GAME_START:
			GamePlay();
			break;
		case RockScissorsPaper::GAME_EXIT:
			cout << "가위바위보 게임을 종료합니다." << endl << endl;
			isGameExit = true;
			break;
		case RockScissorsPaper::MENU:
			GetGameMode();
			break;
		}
	}
}