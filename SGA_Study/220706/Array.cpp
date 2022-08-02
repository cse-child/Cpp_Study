// Array(�迭) : ���� �ڷ����� ������ ���ÿ� ������ �����ϴ� ���

#include <stdio.h>

void SetArr(int* arr)
{
	int arrSize = sizeof(arr) / sizeof(int);
	// �� arrSize�� 2����???

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = i * 2;
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5 };

	printf("Array Size : %d\n", sizeof(arr));
	// int 1�� 4byte -> �迭 5�� = 4byte * 5�� = 20byte
	int arrSize = sizeof(arr) / sizeof(int);

	SetArr(arr);

	for (int i = 0; i < arrSize; i++)
	{
		printf("arr[%d] : %d\n", i, arr[i]);
		printf("&arr[%d] : %d\n", i, &arr[i]);
		// �ּҰ��� ������ ��ġ�� ù��° �޸��ּҰ� ��µȴ�.
	}

	printf("arr : %d\n", arr); 
	// arr �迭 �̸��� �迭�� ù��° �ּҰ�(arr[0])�̶� ����.
	// ��, �迭�� ��ǻ�Ϳ��� '������'�� �ν��Ѵ�.
}

int Array()
{
	// �迭 ���� ���
	// �ڷ��� �����̸�[�迭����(���)]
	// �迭���̰� n�̸� 0���� n-1���� ������ ������.
	const int length = 10;

	// �迭�ʱ�ȭ ���
	// 1. = {}; -> ���� 0���� �ʱ�ȭ
	// 2. arr[] = {a, b, c}; -> ��ȣ �ȿ� ���ǵ� ���ڸ�ŭ ���̰� �Ҵ�ǰ� �ʱ�ȭ ��.
	// 3. arr[size] = {a, b, c}; -> ��ȣ�ȿ� ���ڱ����� �ʱ�ȭ�ǰ� �������� 0����.
	
	//int arr[length] = {};
	//int arr[] = { 2,4,6 };
	int arr[length] = { 2,4,6 };

	for (int i = 0; i < length; i++) {
		//arr[i] = i + 1;
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	return 0;
}