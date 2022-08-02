// 1~100 ������ �������� �̱�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 3 // ������ 3�ܰ� ���� ����

int GetPlayerNum();
bool NumberCompare(int playerNum, int computerNum);

int main()
{
	int playerNum, computerNum;
	int playCount = 1;
	int tryCount[MAX_LEVEL] = { 10, 7, 5 }; // ������ ���� �õ� ���� Ƚ���� �پ��
	int levelCount = 1;

	srand(time(NULL));

	printf("================= 1 ~ 100 ������ �������� �̱� =================\n");

	while (true)
	{
		if (levelCount > MAX_LEVEL)
		{
			printf("\n>> ��� ������ Ŭ�����ϼ̽��ϴ� !!\n");
			printf(">> Game Clear !\n");
			printf("\n==============================================================\n");
			return 0; // ���� ����
		}
		printf("\n\t\t\t[ %d �ܰ� ���� ! ]\n", levelCount);
		printf("\t\t[ �õ� ���� Ƚ���� �� %d ȸ �Դϴ� ]\n", tryCount[levelCount-1]);

		computerNum = rand() % 100 + 1; // 1~100 ���� �����̱�
		playerNum = GetPlayerNum(); // ����� ���� �Է¹ޱ�

		while (!NumberCompare(playerNum, computerNum)) // �� ���� ������ ���� �ݺ�
		{
			if (playCount == tryCount[levelCount-1]) // �õ� Ƚ���� �ʰ��� ���
			{
				printf(">> �־��� �õ� Ƚ���� �ʰ��߽��ϴ� !\n");
				printf(">> Game Over...\n");
				return 0; // ���� ����
			}
			playerNum = GetPlayerNum(); // �÷��̾��� ���� ���Է�
			++playCount;
		}

		printf(">> %d �ܰ� ���� !\n", levelCount);
		printf("\n>> �� �÷��� Ƚ�� : %d\n", playCount);

		playCount = 1;
		++levelCount;
	}
}

/* �÷��̾�κ��� 1~100 ������ ���ڸ� �Է¹޴� �Լ� */
int GetPlayerNum()
{
	int playerNum;

	while (true)
	{
		printf("\n>> 1 ~ 100 ������ ���ڸ� �Է����ּ��� : ");
		scanf_s("%d", &playerNum);

		if (playerNum > 100 || playerNum < 1)
		{
			printf(">> ���� ���� ���ڸ� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���.\n");
			continue;
		}
		return playerNum;
	}
}

/* �÷��̾�� ��ǻ���� ���� �� �� ��� �Լ� */
bool NumberCompare(int playerNum, int computerNum)
{
	if (playerNum > computerNum)
	{
		printf(">> �������ڰ� �� �۽��ϴ�.\n");
		return false;
	}
	else if (playerNum < computerNum)
	{
		printf(">> �������ڰ� �� Ů�ϴ�.\n");
		return false;
	}
	else
	{
		printf(">> �������ڿ� ��ġ�մϴ� !\n");
		return true;
	}
}
