#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCISSORS 1 // ����
#define ROCK 2 // ����
#define PAPER 3 // ��

int main()
{
	srand(time(0));
	int user, computer;

	printf("***** ���������� ���� *****\n");
	while (1) { // ���ѹݺ���: ���α׷��� ��� �����
		computer = rand() % 3 + 1; // 0~2������ 1�� ���� 1~3���� �̱�

		printf("1. ����, 2. ����, 3. �� �� �ϳ��� �Է��ϼ���: ");
		scanf_s("%d", &user); // �÷��̾� ���� �Է¹ޱ�

		if (user > 3 || user < 1) { // 1~3 ���� ���� �Է��ϴ��� üũ
			printf("�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�.\n");
			return 0;
		}

		// �÷��̾�� ��ǻ���� ���� Ȯ�� �� ���
		printf("�÷��̾�� '%s'�� �½��ϴ�.\n", (user == SCISSORS ? "����" : user == ROCK ? "����" : "��"));
		printf("��ǻ�ʹ� '%s'�� �½��ϴ�.\n", (computer == SCISSORS ? "����" : computer == ROCK ? "����" : "��"));

		// �� ���� ���Ͽ� ��� ���
		// �÷��̾ �¸��ϴ� ���
		if ((user == SCISSORS && computer == PAPER) || (user == ROCK && computer == SCISSORS) || (user == PAPER && computer == ROCK)) {
			printf("�÷��̾��� �¸� !\n");
		}
		// ��ǻ�Ͱ� �¸��ϴ� ���
		else if ((user == SCISSORS && computer == ROCK) || (user == ROCK && computer == PAPER) || (user == PAPER && computer == SCISSORS)) {
			printf("�÷��̾��� �й�..\n");
		}
		// ���� �и� �� ���
		else {
			printf("-���º�-\n");
		}
		printf("\n");
	}

	return 0;
}