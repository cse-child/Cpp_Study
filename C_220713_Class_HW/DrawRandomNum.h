#pragma once
class DrawRandomNum
{
public:
	enum GameResult
	{
		NONE,
		ANSWER,
		GAME_OVER
	};

public:
	DrawRandomNum();
	~DrawRandomNum();
	void GamePlay();
	bool UpDownGame();
	int GetRandomRange();
	int GetGameResult();
	bool IsAnswer();
	void GetInputNum();

private:
	GameResult gameResult;
	uint stage = 0;
	uint randomNum = 0;
	uint inputNum = 0;
	uint attempCount = 0;
	uint stageLevel = 0;
	bool isGameExit = false;
	const uint ATTEMP_NUM = 10 - stage;
	const uint MIN_NUM = 1;
	const uint MAX_NUM = 100 + (stage * 10);
};

