// C++
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1 = "Hello";
	string str2 = "World";

	cin >> str1 >> str2;

	cout << str1 << str2 << endl;

	cout << "str1 Length : " << str1.length() << endl;
	if (str1 == str2)
	{
		cout << "같다." << endl;
	}
	else
	{
		cout << "다르다." << endl;
	}
}

int For()
{
	int arr[] = { 1,2,3,4,5 };
	
	// for (int i = 0; i < 5; i++)
	// {
	// 	cout << "arr[" << i << "] : " << arr[i] << endl;
	// 	printf("arr[%d] : %d\n", i, arr[i]);
	// }

	// int를 참조형(int&)으로 쓰면 배열안에 내용이 바뀐다.
	for (int& n : arr) 
	{
		n++;
	}

	for (int n : arr) // 여기선 바꿔도 안바뀜 (Call-By-Value라서)
	{
		cout << n << endl;
	}

	return 0;
}

int InputOutput()
{
	srand(time(0)); // iostream 파일에 전부 포함됨

	//std::cout << "HelloWorld\n";
	// namespace 사용 : std 생략
	cout << "HelloWorld\n";

	int n;

	cin >> n;

	cout << "N : " << n << endl;
	
	int random = rand() % 10;

	printf("Random : %d\n", random); // C++에서도 C문법 전부 사용가능



	return 0;
}