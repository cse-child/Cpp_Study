// 강사님 과제풀이 - UP & DOWN 게임
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum GameResult // 상수 선언
{
	NONE,
	ANSWER,
	GAME_OVER
};

int GetRandomRange(int min, int max);
int GetInputNum(int min, int max);
bool IsAnswer(int inputNum, int answerNum);
GameResult GetGameResult(int inputNum, int answerNum, int attempCount, int maxAttempCount);
bool UpDownGame(int stage);

int main()
{
	srand(time(NULL));

	int stageLevel = 0;

	while (true)
	{
		if (UpDownGame(stageLevel))
		{
			stageLevel++;
		}
		else {
			return 0;
		}
	}
}

int GetRandomRange(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int GetInputNum(int min, int max)
{
	int inputNum = 0;

	while (true)
	{
		printf("%d부터 %d까지의 숫자를 입력하시오.\n", min, max);
		scanf_s("%d", &inputNum);

		if (inputNum >= min && inputNum <= max)
			return inputNum;
		printf("숫자의 범위가 벗어났습니다.\n");
	}
}

bool IsAnswer(int inputNum, int answerNum)
{
	if (inputNum == answerNum)
	{
		printf("정답입니다.\n");
		return true;
	}
	else if (answerNum > inputNum)
	{
		printf("큽니다.\n");
		return false;
	}
	else
	{
		printf("작습니다.\n");
		return false;
	}
}


GameResult GetGameResult(int inputNum, int answerNum, int attempCount, int maxAttempCount)
{
	if (IsAnswer(inputNum, answerNum))
		return ANSWER;
	else
	{
		printf("%d번 시도했습니다. 남은 횟수는 %d번 입니다.\n", 
			attempCount, maxAttempCount - attempCount);
		if (attempCount == maxAttempCount)
		{
			printf("시도 횟수를 초과했습니다.\n");
			return GAME_OVER;
		}
	}
	return NONE;
}

bool UpDownGame(int stage)
{
	const int ATTEMP_NUM = 10 - stage;
	const int MIN_NUM = 1;
	const int MAX_NUM = 100 + (stage * 10);

	int randomNum = 0;
	int inputNum = 0;
	int attempCount = 0;

	printf("%d Level Up & Down Game Start!\n", ++stage);

	randomNum = GetRandomRange(MIN_NUM, MAX_NUM);

	while (true)
	{
		inputNum = GetInputNum(MIN_NUM, MAX_NUM);
		attempCount++;

		GameResult result = GetGameResult(inputNum, randomNum, attempCount, ATTEMP_NUM);

		switch (result)
		{
		case ANSWER:
			printf("정답!\n");
			return true;
		case GAME_OVER:
			printf("GameOver\n");
			return false;
		}
	}
}
