// MultiArray
#include <stdio.h>

// 2�� �迭�� �Լ��� ����ϱ�
// void PrintMultiArray(int arr[][5])
void PrintMultiArray(int (*arr)[5])
{
	//for (int i = 0; i < 3; i++) // �� Row
	//{
	//	for (int j = 0; j < 5; j++) // �� Column
	//	{
	//		printf("arr[%d][%d] : %d\n", i, j, &arr[i][j]);
	//	}
	//}

	int* start = &arr[0][0]; // 2���� �迭�� �޸𸮴� �Ϸķ� �����Ǿ��ִ�.

	for (; start < &arr[0][0] + 15; start++)
	{
		printf("%d, ", *start);
	}
}

int main()
{
	int arr[3][5] = {};
	for (int i = 0; i < 3; i++) // �� Row
	{
		for (int j = 0; j < 5; j++) // �� Column
		{
			arr[i][j] = (i * 1) + (j + 1);
		}
	}
	PrintMultiArray(arr);
}