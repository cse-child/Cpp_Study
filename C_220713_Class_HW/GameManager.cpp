#include "Framework.h"

GameManager::GameManager()
{
	rockScissorsPaper = new RockScissorsPaper();
	drawRandomNum = new DrawRandomNum();
	bingoGame = new BingoGame();
}

GameManager::~GameManager()
{
	delete rockScissorsPaper;
	delete drawRandomNum;
	delete bingoGame;
}

void GameManager::SelectMenu()
{
	uint selectMenu = 0;

	Sleep(1000);
	system("cls");
	cout << "================ �پ��� ���� ������ ================" << endl;
	cout << endl << "�÷��� �� ������ �����ϼ���." << endl;
	cout << "1.����������, 2.�������ڻ̱�, 3.����, 4.�������� : ";
	cin >> selectMenu;
	cout << endl;
	gameType = (GameType)selectMenu;
}

void GameManager::GamePlay()
{
	switch (gameType)
	{
	case GameManager::ROCK_SCISSORS_PAPER:
		rockScissorsPaper->GameState();
		break;
	case GameManager::DRAW_RANDOM_NUM:
		drawRandomNum->GamePlay();
		break;
	case GameManager::BINGO:
		bingoGame->GamePlay();
		break;
	case GameManager::GAME_EXIT:
		cout << "���α׷� ���� !!" << endl;
		exit(0);
	}
}
