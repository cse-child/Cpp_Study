#pragma once
class GameManager
{
private:
	enum State
	{
		EAT = 1,
		PLAY,
		SHOWER,
		SLEEP
	};
public:
	GameManager();
	~GameManager();

	void SelectMenu();
	void GamePlay();

	bool IsGameOver();

private:
	Pet* myPet;
	int day = 0;
	State state;
	
};

