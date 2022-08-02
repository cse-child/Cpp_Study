// ����� ����Ǯ�� - UP & DOWN ����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum GameResult // ��� ����
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
		printf("%d���� %d������ ���ڸ� �Է��Ͻÿ�.\n", min, max);
		scanf_s("%d", &inputNum);

		if (inputNum >= min && inputNum <= max)
			return inputNum;
		printf("������ ������ ������ϴ�.\n");
	}
}

bool IsAnswer(int inputNum, int answerNum)
{
	if (inputNum == answerNum)
	{
		printf("�����Դϴ�.\n");
		return true;
	}
	else if (answerNum > inputNum)
	{
		printf("Ů�ϴ�.\n");
		return false;
	}
	else
	{
		printf("�۽��ϴ�.\n");
		return false;
	}
}


GameResult GetGameResult(int inputNum, int answerNum, int attempCount, int maxAttempCount)
{
	if (IsAnswer(inputNum, answerNum))
		return ANSWER;
	else
	{
		printf("%d�� �õ��߽��ϴ�. ���� Ƚ���� %d�� �Դϴ�.\n", 
			attempCount, maxAttempCount - attempCount);
		if (attempCount == maxAttempCount)
		{
			printf("�õ� Ƚ���� �ʰ��߽��ϴ�.\n");
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
			printf("����!\n");
			return true;
		case GAME_OVER:
			printf("GameOver\n");
			return false;
		}
	}
}
