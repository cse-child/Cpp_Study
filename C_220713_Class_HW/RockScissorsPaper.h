#pragma once
class RockScissorsPaper
{
private:
	enum GameMode 
	{
		GAME_START=1,
		GAME_EXIT,
		MENU
	};
	const int MAX_INPUT_NUM = 3;

public:
	RockScissorsPaper();
	~RockScissorsPaper();
	void GetGameMode();
	void GamePlay();
	void GetPlayerInputNum();
	void PrintRockScissorsPaper(uint selectNum);
	void PrintGameResult();
	void GameState();

private:
	GameMode gameMode;
	uint randomNum = 0;
	uint playerNum = 0;
	bool isGameExit = false;
};

