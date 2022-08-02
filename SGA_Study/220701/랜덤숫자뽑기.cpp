// 1~100 사이의 랜덤숫자 뽑기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 3 // 게임을 3단계 까지 구성

int GetPlayerNum();
bool NumberCompare(int playerNum, int computerNum);

int main()
{
	int playerNum, computerNum;
	int playCount = 1;
	int tryCount[MAX_LEVEL] = { 10, 7, 5 }; // 레벨에 따라 시도 가능 횟수가 줄어듬
	int levelCount = 1;

	srand(time(NULL));

	printf("================= 1 ~ 100 사이의 랜덤숫자 뽑기 =================\n");

	while (true)
	{
		if (levelCount > MAX_LEVEL)
		{
			printf("\n>> 모든 게임을 클리어하셨습니다 !!\n");
			printf(">> Game Clear !\n");
			printf("\n==============================================================\n");
			return 0; // 게임 종료
		}
		printf("\n\t\t\t[ %d 단계 시작 ! ]\n", levelCount);
		printf("\t\t[ 시도 가능 횟수는 총 %d 회 입니다 ]\n", tryCount[levelCount-1]);

		computerNum = rand() % 100 + 1; // 1~100 사이 랜덤뽑기
		playerNum = GetPlayerNum(); // 사용자 숫자 입력받기

		while (!NumberCompare(playerNum, computerNum)) // 두 수가 같을때 까지 반복
		{
			if (playCount == tryCount[levelCount-1]) // 시도 횟수를 초과한 경우
			{
				printf(">> 주어진 시도 횟수를 초과했습니다 !\n");
				printf(">> Game Over...\n");
				return 0; // 게임 종료
			}
			playerNum = GetPlayerNum(); // 플레이어의 숫자 재입력
			++playCount;
		}

		printf(">> %d 단계 성공 !\n", levelCount);
		printf("\n>> 총 플레이 횟수 : %d\n", playCount);

		playCount = 1;
		++levelCount;
	}
}

/* 플레이어로부터 1~100 사이의 숫자를 입력받는 함수 */
int GetPlayerNum()
{
	int playerNum;

	while (true)
	{
		printf("\n>> 1 ~ 100 사이의 숫자를 입력해주세요 : ");
		scanf_s("%d", &playerNum);

		if (playerNum > 100 || playerNum < 1)
		{
			printf(">> 범위 밖의 숫자를 입력하였습니다. 다시 입력하세요.\n");
			continue;
		}
		return playerNum;
	}
}

/* 플레이어와 컴퓨터의 숫자 비교 후 출력 함수 */
bool NumberCompare(int playerNum, int computerNum)
{
	if (playerNum > computerNum)
	{
		printf(">> 랜덤숫자가 더 작습니다.\n");
		return false;
	}
	else if (playerNum < computerNum)
	{
		printf(">> 랜덤숫자가 더 큽니다.\n");
		return false;
	}
	else
	{
		printf(">> 랜덤숫자와 일치합니다 !\n");
		return true;
	}
}
