#include "Framework.h"

BoardGame::BoardGame()
{
	cout << "보드의 사이즈를 입력하세요." << endl;
	cin >> BOARD_SIZE;

	ARRAY_SIZE = BOARD_SIZE * 2;

	/* 1차원 배열 동적할당해서 사용하는 방법 */
	// 1차원 배열 크기만큼 동적할당하여 생성
	arr = new int[ARRAY_SIZE];
}

BoardGame::~BoardGame()
{
	delete[] arr; // 동적할당 해제
}
