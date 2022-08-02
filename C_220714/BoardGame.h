#pragma once
class BoardGame
{
public:
	BoardGame();
	~BoardGame();

private:
	int BOARD_SIZE = 0;
	int ARRAY_SIZE = 0;
	int* arr;
};

