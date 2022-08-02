// 포켓몬게임 과제 풀이
#include "Framework.h"

int main()
{
    Monster* player = new Monster(DataManager::GetInstance()->GetMonsterData(4));
    player->AddSkill(1);
    player->AddSkill(2);
    player->AddSkill(6);
    player->ShowInfo();

    Monster* enemy = new Monster(DataManager::GetInstance()->GetMonsterData(8));
    enemy->AddSkill(1);
    enemy->AddSkill(3);
    
    player->Attack(enemy);

    player->ShowInfo();

    delete player;
    delete enemy;
    DataManager::Delete();
}