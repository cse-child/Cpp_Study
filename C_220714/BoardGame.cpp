#include "Framework.h"

BoardGame::BoardGame()
{
	cout << "������ ����� �Է��ϼ���." << endl;
	cin >> BOARD_SIZE;

	ARRAY_SIZE = BOARD_SIZE * 2;

	/* 1���� �迭 �����Ҵ��ؼ� ����ϴ� ��� */
	// 1���� �迭 ũ�⸸ŭ �����Ҵ��Ͽ� ����
	arr = new int[ARRAY_SIZE];
}

BoardGame::~BoardGame()
{
	delete[] arr; // �����Ҵ� ����
}
