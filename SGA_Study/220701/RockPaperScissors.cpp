// RockPaperScissors (가위바위보 게임) - 반복문 + 함수 기능 추가

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetPlayerInputNum(); 
// 자동완성 단축키 : Ctrl + '.'  / Alt + Enter
// 함수가 선언된 곳으로 이동 : F12
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
			printf("게임 종료\n");
			return 0;
		}
		printf("\n가위바위보 게임 시작!\n");
		int randomNum = rand() % MAX_INPUT_NUM + 1;
		int playerNum = GetPlayerInputNum();

		printf("플레이어는 ");
		PrintRockPaperScissors(playerNum);


		printf("컴퓨터는 ");
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
		printf("다음 중 하나를 선택하시오.\n");
		printf("1.가위, 2.바위, 3.보\n");

		scanf_s("%d", &playerNum);

		if (playerNum < 1 || playerNum > 3)
		{
			printf("잘못 입력했습니다.\n");
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
		printf("가위를 냈습니다.\n");
	}
	break;
	case 2:
	{
		printf("바위를 냈습니다.\n");
	}
	break;
	case 3:
	{
		printf("보를 냈습니다.\n");
	}
	break;
	}
}

void PrintGameResult(int playerNum, int randomNum)
{
	printf("\n게임 결과\n");

	if (playerNum == randomNum)
	{
		printf("비겼습니다.\n");
	}
	else if ((playerNum % MAX_INPUT_NUM) + 1 == randomNum)
	{
		printf("졌습니다.\n");
	}
	else
	{
		printf("이겼습니다.\n");
	}
}

int GetGameMode()
{
	int inputGameMode = 0;
	printf("1. 게임시작, 2. 게임종료\n");
	scanf_s("%d", &inputGameMode);

	return inputGameMode;
}

// 검색: C++ 네이밍 규칙
