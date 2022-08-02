// MultiArray
#include <stdio.h>

// 2중 배열을 함수로 사용하기
// void PrintMultiArray(int arr[][5])
void PrintMultiArray(int (*arr)[5])
{
	//for (int i = 0; i < 3; i++) // 행 Row
	//{
	//	for (int j = 0; j < 5; j++) // 열 Column
	//	{
	//		printf("arr[%d][%d] : %d\n", i, j, &arr[i][j]);
	//	}
	//}

	int* start = &arr[0][0]; // 2차원 배열도 메모리는 일렬로 나열되어있다.

	for (; start < &arr[0][0] + 15; start++)
	{
		printf("%d, ", *start);
	}
}

int main()
{
	int arr[3][5] = {};
	for (int i = 0; i < 3; i++) // 행 Row
	{
		for (int j = 0; j < 5; j++) // 열 Column
		{
			arr[i][j] = (i * 1) + (j + 1);
		}
	}
	PrintMultiArray(arr);
}