// BaseballGame
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 3
#define MAX_CHANCE 10
#define MAX_OUT_COUNT 3
#define MIN_NUMBER 1
#define MAX_NUMBER 9

typedef unsigned int uint;

// enum: ����� �������� ��Ƶ� �ڷ���
// ������ ������ ��ȣȣȯ ����
// �������� ����
enum GameState
{
	SETTING,
	INPUT,
	CHECK,
	WIN,
	LOSE
};

// void SetComputerNumbers(uint arr[]); // ���� �ǹ�
void SetComputerNumbers(uint* arr); //  Call-By-Address 
// �ּҰ��� �Ѱ��༭ ���������� ������ ������ �� ����
uint GetRandomRange(uint min, uint max);
void SetPlayerNumbers(uint* arr);
uint InputNumberInRange(uint min, uint max);
GameState CheckState(const uint* computerNumbers, const uint* playerNumbers, uint& outCount, uint& playCount);
// Call-By-Address�Ҷ��� const�� ���ִ� ���� ����

int main()
{
	srand(time(0));

	// �迭�� �������� ����������
	uint computerNumbers[LENGTH] = {};
	uint playerNumbers[LENGTH] = {};
	uint outCount = 0;
	uint playCount = 0;

	GameState gameState = SETTING;

	while (true)
	{
		switch (gameState)
		{
		case SETTING:
			SetComputerNumbers(computerNumbers);
			gameState = INPUT;
			break;
		case INPUT:
			SetPlayerNumbers(playerNumbers);
			gameState = CHECK;
			break;
		case CHECK:
			gameState = CheckState(computerNumbers, playerNumbers, outCount, playCount);
			break;
		case WIN:
			printf("Win!\n");
			return 0;
		case LOSE:
			printf("Game Over TT\n");
			return 0;
		}
	};
}

void SetComputerNumbers(uint* arr)
{
	for (uint i = 0; i < LENGTH;)
	{
		arr[i] = GetRandomRange(MIN_NUMBER, MAX_NUMBER);

		bool check = false;
		for (uint j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
				check = true;
		}
		
		// (check == false) == (check != true) == (!check)
		if (!check)
		{
			i++;
		}
	}
}

uint GetRandomRange(uint min, uint max)
{
	return rand() % (max - min + 1) + min;
}

void SetPlayerNumbers(uint* arr)
{	
	
	for (uint i = 0; i < LENGTH; i++)
	{
		arr[i] = InputNumberInRange(MIN_NUMBER, MAX_NUMBER);
	}

	printf("Player Number : ");
	for (uint i = 0; i < LENGTH; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
}

uint InputNumberInRange(uint min, uint max)
{
	while (true)
	{
		printf("%d���� %d���� ���ڸ� �Է��Ͻÿ�.\n", min, max);

		int number;
		scanf_s("%d", &number);
		if (number < min || number > max)
			printf("�߸� �Է��߽��ϴ�.\n");
		else
			return number;
	}
}

GameState CheckState(const uint* computerNumbers, const uint* playerNumbers, uint& outCount, uint& playCount)
{
	uint strikeCount = 0;
	uint ballCount = 0;

	for (uint i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (computerNumbers[i] == playerNumbers[j]) // ���ڰ� ����.
			{
				if (i == j)
					strikeCount++;
				else
					ballCount++;
			}
		}
	}

	if (strikeCount + ballCount == 0)
	{
		printf("%d Out!\n", ++outCount);
		if (outCount == MAX_OUT_COUNT)
			return LOSE;
	}
	else
	{
		printf("%d Strike %d Ball \n", strikeCount, ballCount);
	}

	if (strikeCount == LENGTH)
		return WIN;

	playCount++;
	printf("%d ���� �Ϸ�\n", playCount);

	if (playCount == MAX_CHANCE)
		return LOSE;

	return INPUT;
}
