// Array(배열) : 같은 자료형의 변수를 동시에 여러개 선언하는 방법

#include <stdio.h>

void SetArr(int* arr)
{
	int arrSize = sizeof(arr) / sizeof(int);
	// 왜 arrSize가 2인지???

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = i * 2;
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5 };

	printf("Array Size : %d\n", sizeof(arr));
	// int 1개 4byte -> 배열 5개 = 4byte * 5개 = 20byte
	int arrSize = sizeof(arr) / sizeof(int);

	SetArr(arr);

	for (int i = 0; i < arrSize; i++)
	{
		printf("arr[%d] : %d\n", i, arr[i]);
		printf("&arr[%d] : %d\n", i, &arr[i]);
		// 주소값은 변수가 위치한 첫번째 메모리주소가 출력된다.
	}

	printf("arr : %d\n", arr); 
	// arr 배열 이름은 배열의 첫번째 주소값(arr[0])이랑 같다.
	// 즉, 배열은 컴퓨터에서 '포인터'로 인식한다.
}

int Array()
{
	// 배열 선언 방법
	// 자료형 변수이름[배열길이(상수)]
	// 배열길이가 n이면 0부터 n-1까지 변수가 생성됨.
	const int length = 10;

	// 배열초기화 방법
	// 1. = {}; -> 전부 0으로 초기화
	// 2. arr[] = {a, b, c}; -> 괄호 안에 정의된 숫자만큼 길이가 할당되고 초기화 됨.
	// 3. arr[size] = {a, b, c}; -> 괄호안에 숫자까지만 초기화되고 나머지는 0으로.
	
	//int arr[length] = {};
	//int arr[] = { 2,4,6 };
	int arr[length] = { 2,4,6 };

	for (int i = 0; i < length; i++) {
		//arr[i] = i + 1;
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	return 0;
}