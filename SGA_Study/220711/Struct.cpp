// Struct (����ü) : �ϳ� �̻��� ������ �׷���� ���ο� �ڷ����� �����ϴ� ��
// �迭�� ������: ����ü�� �ٸ� �ڷ����� �Բ� ������ �� �ִ�.
#include <stdio.h>

typedef unsigned int uint;

/* ����ü ������ �ΰ��� */
//typedef struct
//{
//	char name;
//	int attack;
//	float critical;
//}Monster;

struct Monster
{
	char name;
	int attack;
	float critical;
};

void ShowMonsterInfo(Monster monster);
void SetMonsterInfo(Monster* monster);

int main()
{
	uint a = 10;

	Monster monster;
	monster.name = 'M';
	monster.attack = 10;
	monster.critical = 0.1;

	printf("monster �ּҰ� : %d\n", &monster);
	printf("name �ּҰ� : %d\n", &monster.name);
	printf("attack �ּҰ� : %d\n", &monster.attack);
	printf("critical �ּҰ� : %d\n", &monster.critical);
	printf("\n");

	ShowMonsterInfo(monster);

	SetMonsterInfo(&monster);

	ShowMonsterInfo(monster);

}

void ShowMonsterInfo(Monster monster)
{
	printf("Name : %c\n", monster.name);
	printf("Attack : %d\n", monster.attack);
	printf("Critical : %.1f\n", monster.critical);
	
}

void SetMonsterInfo(Monster* monster)
{
	// (*monster).name = 'A';
	// monster->name = 'A';

	scanf_s("%c", &monster->name);
	scanf_s("%d", &monster->attack);
	scanf_s("%f", &monster->critical);
}
