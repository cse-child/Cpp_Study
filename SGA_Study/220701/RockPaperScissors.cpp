// RockPaperScissors (���������� ����) - �ݺ��� + �Լ� ��� �߰�

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetPlayerInputNum(); 
// �ڵ��ϼ� ����Ű : Ctrl + '.'  / Alt + Enter
// �Լ��� ����� ������ �̵� : F12
void PrintRockPaperScissors(int selectNum);
void PrintGameResult(int playerNum, int randomNum);
int GetGameMode();

const int MAX_INPUT_NUM = 3;

int main()
{
	srand(time(NULL));

	while (true)
	{
		int gameMode = GetGameMode();
		if (gameMode == 2) 
		{
			printf("���� ����\n");
			return 0;
		}
		printf("\n���������� ���� ����!\n");
		int randomNum = rand() % MAX_INPUT_NUM + 1;
		int playerNum = GetPlayerInputNum();

		printf("�÷��̾�� ");
		PrintRockPaperScissors(playerNum);


		printf("��ǻ�ʹ� ");
		PrintRockPaperScissors(randomNum);

		PrintGameResult(playerNum, randomNum);
	}

	return 0;
}

int GetPlayerInputNum()
{
	int playerNum;

	while (true)
	{
		printf("���� �� �ϳ��� �����Ͻÿ�.\n");
		printf("1.����, 2.����, 3.��\n");

		scanf_s("%d", &playerNum);

		if (playerNum < 1 || playerNum > 3)
		{
			printf("�߸� �Է��߽��ϴ�.\n");
			continue;
		}

		return playerNum;
	}
}

void PrintRockPaperScissors(int selectNum)
{
	switch (selectNum)
	{
	case 1:
	{
		printf("������ �½��ϴ�.\n");
	}
	break;
	case 2:
	{
		printf("������ �½��ϴ�.\n");
	}
	break;
	case 3:
	{
		printf("���� �½��ϴ�.\n");
	}
	break;
	}
}

void PrintGameResult(int playerNum, int randomNum)
{
	printf("\n���� ���\n");

	if (playerNum == randomNum)
	{
		printf("�����ϴ�.\n");
	}
	else if ((playerNum % MAX_INPUT_NUM) + 1 == randomNum)
	{
		printf("�����ϴ�.\n");
	}
	else
	{
		printf("�̰���ϴ�.\n");
	}
}

int GetGameMode()
{
	int inputGameMode = 0;
	printf("1. ���ӽ���, 2. ��������\n");
	scanf_s("%d", &inputGameMode);

	return inputGameMode;
}

// �˻�: C++ ���̹� ��Ģ
