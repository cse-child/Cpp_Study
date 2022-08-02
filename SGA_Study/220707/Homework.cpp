#include <stdio.h>
#include <stdlib.h>

// �迭�� �Լ��� �ְ�޴� �پ��� ���,,

void ChangeArr(int* arr);
int* ChangeArr2();

int main()
{
	int arr[3] = {};

	ChangeArr(arr);

	for (int i = 0; i < 3; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	int* arr2 = ChangeArr2();

	for (int i = 0; i < 3; i++)
	{
		printf("%d  ", arr2[i]);
	}
	printf("\n");
}

void ChangeArr(int* arr) // Call-By-Address
{
	for (int i = 0; i < 3; i++)
	{
		arr[i] = i + 1;
	}
}

int* ChangeArr2()
{
	int* arr = (int*)malloc(sizeof(int) * 3);

	for (int i = 0; i < 3; i++)
	{
		arr[i] = 50 + i;
	}

	return arr;
}



