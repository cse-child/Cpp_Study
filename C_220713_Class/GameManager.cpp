#include "Framework.h"

GameManager::GameManager()
{
	// new : 객체의 메모리를 할당하고 그 주소값을 반환해주는 함수
	myPet = new Pet();
}

GameManager::~GameManager()
{
	delete myPet;
}

void GameManager::SelectMenu()
{
	system("cls");
	int inputNum = 0;

	myPet->ShowInfo();

	cout << ++day << "일차" << endl;
	cout << "1.Eat, 2.Play, 3.Shower, 4.Sleep" << endl;
	cin >> inputNum;

	state = (State)inputNum;
}

void GameManager::GamePlay()
{
	switch (state)
	{
	case GameManager::EAT:
		myPet->Eat();
		break;
	case GameManager::PLAY:
		myPet->Play();
		break;
	case GameManager::SHOWER:
		myPet->Shower();
		break;
	case GameManager::SLEEP:
		myPet->Sleep();
		break;
	}
	Sleep(1000);
}

bool GameManager::IsGameOver()
{
	return myPet->IsDead();
}
