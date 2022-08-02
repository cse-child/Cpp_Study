#pragma once
class GameManager
{
private:
	enum GameType
	{
		ROCK_SCISSORS_PAPER = 1,	// 가위바위보 게임
		DRAW_RANDOM_NUM,			// 랜덤숫자뽑기
		BINGO,						// 빙고게임
		GAME_EXIT					// 게임 종료
	};

public:
	GameManager();
	~GameManager();
	void SelectMenu();
	void GamePlay();

private:
	GameType gameType;
	RockScissorsPaper* rockScissorsPaper;
	DrawRandomNum* drawRandomNum;
	BingoGame* bingoGame;
};

