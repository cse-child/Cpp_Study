// 포켓몬게임 과제 풀이
#include "Framework.h"

enum Play
{
	FIGHT=1, RUNAWAY
};
// 클래스 배열 동적할당
Monster* poketmon;
Monster* enemy;
int poketCount;

void Init();
void PlayGame();
void CheckDuplicateNum(int arr[], int size);
bool CheckDie(Monster* target);

int main()
{
	srand(time(NULL));
	int inputNum;
	Play inputPlay;

	cout << "------ 포켓 몬스터 ------" << endl;
	Init();
	Sleep(1000);
	system("cls");

	cout << endl << "야생의 " << enemy->GetName() << " (이/가) 나타났다!" << endl;
	cout << "1. 싸운다, 2. 도망간다 : ";
	cin >> inputNum;
	inputPlay = (Play)inputNum;

	switch (inputPlay)
	{
	case FIGHT:
		PlayGame();
		break;
	case RUNAWAY:
		cout << "무사히 도망쳤습니다 !" << endl;
		break;
	}

    delete[] poketmon;
	delete enemy;
    DataManager::Delete();
}

void Init()
{
	cout << "몇 마리의 몬스터를 데려오시겠습니까? ";
	cin >> poketCount;

	poketmon = new Monster[poketCount];

	enemy = new Monster(DataManager::GetInstance()->GetMonsterData((rand() % MAX_MONSTER_NUM) + 1));
	enemy->AddSkill(rand() % MAX_SKILL_NUM + 1);

	for (int i = 0; i < poketCount; i++)
	{
		poketmon[i] = Monster(DataManager::GetInstance()->GetMonsterData((rand() % MAX_MONSTER_NUM) + 1));
		
		int skillCount = rand() % SKILL_NUM + 1;
		int* skillInfo = new int[skillCount];
		CheckDuplicateNum(skillInfo, skillCount);
		for (int j = 0; j < skillCount; j++)
		{
			poketmon[i].AddSkill(skillInfo[j]);
		}
		cout << endl << (i + 1) << "번째 몬스터를 데려왔습니다 !" << endl;
		poketmon[i].ShowInfo();
		Sleep(2500);
	}
}

void PlayGame()
{
	for (int i = 0; i < poketCount; i++)
	{
		while (true)
		{
			cout << endl << "[ 야생의 " << enemy->GetName() << " 상태 ]" << endl;
			enemy->ShowInfo();
			cout << endl << "[ 나의 포켓몬 " << poketmon[i].GetName() << " 상태 ]" << endl;
			poketmon[i].ShowInfo();
			cout << endl;

			poketmon[i].Attack(enemy);
			if (CheckDie(enemy)) 
			{
				cout << "모든 야생 몬스터를 물리쳤습니다 !" << endl;
				i = poketCount; // for문과 while문 둘다 탈출..
				break;
			}
			Sleep(2000);

			enemy->EnemyAttack(&poketmon[i]);
			if (CheckDie(&poketmon[i])) 
			{
				if(i == poketCount-1)
					cout << "나의 모든 포켓몬이 쓰러졌습니다..." << endl;
				break;
			}
			cout << endl << "(다음페이지. 아무키나 누르세요)" << endl;
			if (_getch())
				system("cls");
		}
	}
}

void CheckDuplicateNum(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % MAX_SKILL_NUM + 1; // 1~7
		for (int j = 0; j < i; j++) // 중복없이 스킬 초기화하기
		{
			if (arr[j] == arr[i])
			{
				i--;
				break;
			}
		}
	}
}

bool CheckDie(Monster* target)
{
	if (target->GetHP() <= 0)
	{
		cout << endl << target->GetName() << "(이/가) 쓰러졌습니다 !" << endl;

		cout << endl << "(다음페이지. 아무키나 누르세요)" << endl;
		if (_getch())
			system("cls");
		return true;
	}
		
	return false;
}

