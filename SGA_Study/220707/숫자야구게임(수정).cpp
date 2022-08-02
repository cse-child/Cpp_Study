// ���ھ߱�����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 3			// ���ӿ� ���Ǵ� ���� ����
#define RESULT_COUNT 2		// ���� ��� �迭(Strike, Ball)
#define STRIKE 0			// ��� �迭 - Strike �ε���
#define BALL 1				// ��� �迭 - Ball �ε���
#define PLAY_COUNT 5		// �õ� Ƚ��
#define MAX_NUMBER 9		// ���ھ߱� ���� �ִ�

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

/* ���� ���� �Լ� */
void PlayGame()
{
	srand(time(NULL));
	int answerNum[NUM_COUNT] = {}; // ���� ���� 3��
	int playerNum[NUM_COUNT] = {};
	int result[RESULT_COUNT] = {};
	int playCount = 1; // ���� �õ� Ƚ��

	printf("*************** ���ھ߱� ���� ***************\n");
	printf("\t[ �־��� ��ȸ�� %d ȸ �Դϴ� ]\n\n", PLAY_COUNT);

	GetRandomThreeNumber(answerNum);

	while (playCount <= PLAY_COUNT)
	{
		GetInputThreeNumber(playerNum); // �Է� ���� 3��
		GameJudgment(result, playerNum, answerNum); // Strike, Ball ī��Ʈ
		PrintResult(result); // ��� ���
		++playCount;
	}
	printf("�� �־��� Ƚ���� ��� �����Ͽ����ϴ�.\n");
	printf("�� GAME OVER ��\n");
}

/* �÷��̾�� ���� 3���� �Է¹޴� �Լ� */
void GetInputThreeNumber(int* playerNum)
{
	while (true)
	{
		printf(">> 1~9 ������ ���� 3���� �Է��ϼ��� : ");
		for (int i = 0; i < NUM_COUNT; i++)
			scanf_s("%d", &playerNum[i]);

		if (CheckNumberRange(playerNum)) // �Է¹��� ���ڰ� 1~9 ���� �������� Ȯ��
			break;
	}
}

/* 1~9 ���� ���� üũ �Լ� */
bool CheckNumberRange(int* num)
{
	for (int i = 0; i < NUM_COUNT; i++)
	{
		if (num[i] > 9 || num[i] < 1)
		{
			printf("�� 1~9 ���� ���� ���ڸ� �ٽ� �Է����ּ���.\n\n");
			return false; // 1~9 ���� ���̸� false ��ȯ
		}
	}
	return true; // ��� ���ڰ� ���� ���� true ��ȯ
}

/* 1~9���� 3���� �������� ���� �Լ� */
void GetRandomThreeNumber(int* answerNum)
{
	for (int i = 0; i < NUM_COUNT; i++)
	{
		answerNum[i] = rand() % MAX_NUMBER + 1;
		for (int j = 0; j < i; j++) // �ߺ� ������ ���� ��������� ������ ��
		{
			if (answerNum[i] == answerNum[j]) // �ߺ��� ���� �ִٸ� ������ �ٽ� �ޱ�
				i--;
		}
	}
	printf("\t\t\t\t\t\t\t\t����: %d %d %d\n", answerNum[0], answerNum[1], answerNum[2]);
}

/* �� ���� ���Ͽ� ��Ʈ����ũ, �� ���� �Լ� */
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

/* ��Ʈ����ũ, ��, �ƿ� ��� �� �������� �Լ� */
void PrintResult(int* result)
{
	static int outCount = 0; // OUT Count�� ��������(�Լ��� ������ ���� �������)

	if (result[STRIKE] == 0 && result[BALL] == 0)
	{
		++outCount;
		printf("�� %d OUT\n", outCount);
		if (outCount == 3)
		{
			printf("�� GAME OVER ��\n");
			exit(0); // ���� ����
		}
	}
	else if (result[STRIKE] == 3)
	{
		printf("�� 3 STRIKE\n");
		printf("�� PLAYER WIN ��\n");
		exit(0); // ���� ����
	}
	else
	{
		printf("�� %d STRIKE %d BALL\n", result[STRIKE], result[BALL]);
	}
	printf("\n");
}