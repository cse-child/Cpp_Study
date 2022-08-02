// 숫자야구게임
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 3			// 게임에 사용되는 숫자 개수
#define RESULT_COUNT 2		// 게임 결과 배열(Strike, Ball)
#define STRIKE 0			// 결과 배열 - Strike 인덱스
#define BALL 1				// 결과 배열 - Ball 인덱스
#define PLAY_COUNT 5		// 시도 횟수
#define MAX_NUMBER 9		// 숫자야구 게임 최댓값

void PlayGame();
void GetInputThreeNumber(int* playerNum);
bool CheckNumberRange(int* num);
void GetRandomThreeNumber(int* answerNum);
void GameJudgment(int* result, int* playerNum, int* answerNum);
void PrintResult(int* result);

int main()
{
	PlayGame();
	return 0;
}

/* 게임 실행 함수 */
void PlayGame()
{
	srand(time(NULL));
	int answerNum[NUM_COUNT] = {}; // 정답 숫자 3개
	int playerNum[NUM_COUNT] = {};
	int result[RESULT_COUNT] = {};
	int playCount = 1; // 현재 시도 횟수

	printf("*************** 숫자야구 게임 ***************\n");
	printf("\t[ 주어진 기회는 %d 회 입니다 ]\n\n", PLAY_COUNT);

	GetRandomThreeNumber(answerNum);

	while (playCount <= PLAY_COUNT)
	{
		GetInputThreeNumber(playerNum); // 입력 숫자 3개
		GameJudgment(result, playerNum, answerNum); // Strike, Ball 카운트
		PrintResult(result); // 결과 출력
		++playCount;
	}
	printf("▶ 주어진 횟수를 모두 소진하였습니다.\n");
	printf("▶ GAME OVER ◀\n");
}

/* 플레이어에게 숫자 3개를 입력받는 함수 */
void GetInputThreeNumber(int* playerNum)
{
	while (true)
	{
		printf(">> 1~9 사이의 숫자 3개를 입력하세요 : ");
		for (int i = 0; i < NUM_COUNT; i++)
			scanf_s("%d", &playerNum[i]);

		if (CheckNumberRange(playerNum)) // 입력받은 숫자가 1~9 내의 범위인지 확인
			break;
	}
}

/* 1~9 안의 범위 체크 함수 */
bool CheckNumberRange(int* num)
{
	for (int i = 0; i < NUM_COUNT; i++)
	{
		if (num[i] > 9 || num[i] < 1)
		{
			printf("※ 1~9 범위 안의 숫자를 다시 입력해주세요.\n\n");
			return false; // 1~9 범위 밖이면 false 반환
		}
	}
	return true; // 모든 숫자가 범위 내면 true 반환
}

/* 1~9까지 3개의 랜덤숫자 생성 함수 */
void GetRandomThreeNumber(int* answerNum)
{
	for (int i = 0; i < NUM_COUNT; i++)
	{
		answerNum[i] = rand() % MAX_NUMBER + 1;
		for (int j = 0; j < i; j++) // 중복 방지를 위해 이전값들과 같은지 비교
		{
			if (answerNum[i] == answerNum[j]) // 중복된 수가 있다면 랜덤값 다시 받기
				i--;
		}
	}
	printf("\t\t\t\t\t\t\t\t정답: %d %d %d\n", answerNum[0], answerNum[1], answerNum[2]);
}

/* 두 수를 비교하여 스트라이크, 볼 판정 함수 */
void GameJudgment(int* result, int* playerNum, int* answerNum)
{
	result[STRIKE] = 0;
	result[BALL] = 0;
	for (int i = 0; i < NUM_COUNT; i++)
	{
		for (int j = 0; j < NUM_COUNT; j++)
		{
			if (playerNum[i] == answerNum[j])
			{
				if (i == j)
					++result[STRIKE];
				else
					++result[BALL];
			}
		}
	}
}

/* 스트라이크, 볼, 아웃 출력 및 게임종료 함수 */
void PrintResult(int* result)
{
	static int outCount = 0; // OUT Count는 정적변수(함수가 끝나도 값이 살아있음)

	if (result[STRIKE] == 0 && result[BALL] == 0)
	{
		++outCount;
		printf("▶ %d OUT\n", outCount);
		if (outCount == 3)
		{
			printf("▶ GAME OVER ◀\n");
			exit(0); // 게임 종료
		}
	}
	else if (result[STRIKE] == 3)
	{
		printf("▶ 3 STRIKE\n");
		printf("▶ PLAYER WIN ◀\n");
		exit(0); // 게임 종료
	}
	else
	{
		printf("▶ %d STRIKE %d BALL\n", result[STRIKE], result[BALL]);
	}
	printf("\n");
}