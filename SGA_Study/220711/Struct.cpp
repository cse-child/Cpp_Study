// Struct (구조체) : 하나 이상의 변수를 그룹지어서 새로운 자료형을 정의하는 것
// 배열과 차이점: 구조체는 다른 자료형을 함께 정의할 수 있다.
#include <stdio.h>

typedef unsigned int uint;

/* 구조체 선언방법 두가지 */
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

	printf("monster 주소값 : %d\n", &monster);
	printf("name 주소값 : %d\n", &monster.name);
	printf("attack 주소값 : %d\n", &monster.attack);
	printf("critical 주소값 : %d\n", &monster.critical);
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
