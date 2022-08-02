// 포켓몬게임 과제 풀이
#include "Framework.h"

void Save()
{
    //ofstream saveFile;
    //saveFile.open("save.txt", ios::out);
    ofstream saveFile("save.txt", ios::out);

    saveFile << "Hello World";

    saveFile.close();
}

void Load()
{
    ifstream loadFile("save.txt", ios::in);

    string str;

    loadFile >> str;

    cout << str << endl;

    loadFile >> str;

    cout << str << endl;
}

int main()
{
    Monster* monster = new Monster(DataManager::GetInstance()->GetMonsterData(4));

    monster->ShowInfo();

    delete monster;
}