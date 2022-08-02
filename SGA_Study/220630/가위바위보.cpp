#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCISSORS 1 // 가위
#define ROCK 2 // 바위
#define PAPER 3 // 보

int main()
{
	srand(time(0));
	int user, computer;

	printf("***** 가위바위보 게임 *****\n");
	while (1) { // 무한반복문: 프로그램을 계속 재실행
		computer = rand() % 3 + 1; // 0~2범위에 1을 더해 1~3범위 뽑기

		printf("1. 가위, 2. 바위, 3. 보 중 하나를 입력하세요: ");
		scanf_s("%d", &user); // 플레이어 숫자 입력받기

		if (user > 3 || user < 1) { // 1~3 범위 내로 입력하는지 체크
			printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
			return 0;
		}

		// 플레이어와 컴퓨터의 숫자 확인 후 출력
		printf("플레이어는 '%s'를 냈습니다.\n", (user == SCISSORS ? "가위" : user == ROCK ? "바위" : "보"));
		printf("컴퓨터는 '%s'를 냈습니다.\n", (computer == SCISSORS ? "가위" : computer == ROCK ? "바위" : "보"));

		// 두 수를 비교하여 결과 출력
		// 플레이어가 승리하는 경우
		if ((user == SCISSORS && computer == PAPER) || (user == ROCK && computer == SCISSORS) || (user == PAPER && computer == ROCK)) {
			printf("플레이어의 승리 !\n");
		}
		// 컴퓨터가 승리하는 경우
		else if ((user == SCISSORS && computer == ROCK) || (user == ROCK && computer == PAPER) || (user == PAPER && computer == SCISSORS)) {
			printf("플레이어의 패배..\n");
		}
		// 같은 패를 낸 경우
		else {
			printf("-무승부-\n");
		}
		printf("\n");
	}

	return 0;
}