#include "Framework.h"

enum Play
{
	ATTACK = 1, // 공격하기
	HEAL, // 치료하기
	RUN, // 도망치기
	NONE
};

Play SelectMenu();
void CreateMonster();
void MonsterAction(uint index);

Player* player = nullptr;
Monster* monsters[MAX_MONSTER_COUNT];

int main()
{
	srand(time(NULL));
	string name = "";
	Play inputMenu = NONE;
	uint deadCount = MAX_MONSTER_COUNT;

	cout << "포켓몬스터 게임에 입장하신걸 환영합니다!" << endl;
	cout << "플레이어의 이름을 입력해주세요 : ";
	cin >> name;
	player = new Player(name);

	CreateMonster();
	
	//for (uint i = 0; i < MAX_MONSTER_COUNT; i++)
	while(true)
	{
		if (deadCount == 0)
		{
			cout << endl << "축하합니다 ! 모든 몬스터를 쓰러뜨렸습니다! " << endl << endl;
			break;
		}
		for (uint i = 0; i < MAX_MONSTER_COUNT; i++)
		{
			if (!monsters[i]->IsDead(monsters[i]))
			{
				inputMenu = SelectMenu();
				switch (inputMenu)
				{
				case ATTACK:
					player->AttackMonster(monsters[i]);
					break;
				case HEAL:
					player->SelfHeal();
					break;
				case RUN:
					cout << monsters[i]->GetName() << "으로부터 도망쳤습니다 !!" << endl << endl;
					monsters[i]->SetRun(monsters[i]);
					--deadCount;
					continue;
				}
				if (monsters[i]->IsDead(monsters[i]))
				{
					cout << monsters[i]->GetName() << "(을/를) 쓰러뜨렸습니다 !" << endl;
					--deadCount;
					continue;
				}
				MonsterAction(i);
				cout << endl;
			}
		}
	}
}

Play SelectMenu()
{
	uint menu;

	while (true)
	{
		cout << "1.공격하기, 2.치료하기, 3.도망치기 : ";
		cin >> menu;
		cout << endl;

		if (menu < 1 || menu > 3)
			continue;
		return (Play)menu;
	}
}

void CreateMonster()
{
	monsters[0] = new Piery();
	monsters[1] = new Ggobucki();

	for (uint i = 0; i < MAX_MONSTER_COUNT; i++)
	{
		monsters[i]->ShowInfo();
	}
}

void MonsterAction(uint index)
{
	int action = rand() % 3 + 1;

	switch (action)
	{
	case ATTACK:
		player->Damaged(monsters[index]);
		break;
	case HEAL:
		monsters[index]->SelfHeal(monsters[index]);
		break;
	case RUN:
	case NONE:
		break;
	}
}
