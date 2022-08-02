#pragma once
class GameManager
{
private:
	enum GameType
	{
		ROCK_SCISSORS_PAPER = 1,	// ���������� ����
		DRAW_RANDOM_NUM,			// �������ڻ̱�
		BINGO,						// �������
		GAME_EXIT					// ���� ����
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

