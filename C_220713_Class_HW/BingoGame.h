#pragma once
class BingoGame
{
#define BOARD_SIZE 5
private:
	enum GameState
	{
		SET_BOARD,
		PRINT_BOARD,
		INPUT_NUMBER,
		CHECK_BINGO,
		GAME_CLEAR,
		GAME_OVER
	};
	//const uint BOARD_SIZE = 5;
	const uint MIN_NUMBER = 1;
	const uint MAX_NUMBER = 99;
	const uint MAX_BINGO_COUNT = 1;
	const uint MAX_INPUT_CHANCE = 30;

public:
	BingoGame();
	~BingoGame();
	void GamePlay();
	void SetBoard();
	uint GetRandomInRange();
	uint GetBoardNum(uint count);
	void PrintBoard(const uint(*board)[BOARD_SIZE]);
	void InputNumberInRange();
	void CheckInputNumber();
	uint CheckBingo();

private:
	
	GameState gameState;
	uint answerBoard[BOARD_SIZE][BOARD_SIZE] = {}; // 비정적 멤버 참조는 특정 개체에 상대적이어야 합니다.
	uint inputBoard[BOARD_SIZE][BOARD_SIZE] = {};
	uint inputCount = 0;
	uint inputNumber = 0;
	bool isGameExit = false;

};

