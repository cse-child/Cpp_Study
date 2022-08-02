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
	cout << "================ 다양한 게임 모음집 ================" << endl;
	cout << endl << "플레이 할 게임을 선택하세요." << endl;
	cout << "1.가위바위보, 2.랜덤숫자뽑기, 3.빙고, 4.게임종료 : ";
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
		cout << "프로그램 종료 !!" << endl;
		exit(0);
	}
}
