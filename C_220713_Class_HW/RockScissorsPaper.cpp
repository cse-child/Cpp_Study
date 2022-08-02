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
	cout << "\n���������� ���� ����!" << endl;
	cout << "1.���ӽ���, 2. �������� : ";
	cin >> selectMenu;
	cout << endl;

	gameMode = (GameMode)selectMenu;
}

void RockScissorsPaper::GamePlay()
{
	randomNum = rand() % MAX_INPUT_NUM + 1;
	GetPlayerInputNum();

	cout << "�÷��̾�� ";
	PrintRockScissorsPaper(playerNum);

	cout << "��ǻ�ʹ� ";
	PrintRockScissorsPaper(randomNum);

	PrintGameResult();

	gameMode = MENU;
}

void RockScissorsPaper::GetPlayerInputNum()
{
	while (true)
	{
		cout << "���� �� �ϳ��� �����Ͻÿ�." << endl;
		cout << "1.����, 2.����, 3.�� : ";

		cin >> playerNum;

		if (playerNum < 1 || playerNum > MAX_INPUT_NUM)
		{
			cout << "�߸� �Է��߽��ϴ�." << endl;
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
		printf("������ �½��ϴ�.\n");
	break;
	case 2:
		printf("������ �½��ϴ�.\n");
	break;
	case 3:
		printf("���� �½��ϴ�.\n");
	break;
	}
}

void RockScissorsPaper::PrintGameResult()
{
	cout << ">> ���� ��� : ";

	if (playerNum == randomNum)
	{
		cout << "�����ϴ�." << endl;
	}
	else if ((playerNum % MAX_INPUT_NUM) + 1 == randomNum)
	{
		cout << "�����ϴ�." << endl;
	}
	else
	{
		cout << "�̰���ϴ�." << endl;
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
			cout << "���������� ������ �����մϴ�." << endl << endl;
			isGameExit = true;
			break;
		case RockScissorsPaper::MENU:
			GetGameMode();
			break;
		}
	}
}