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
		cout << "����." << endl;
	}
	else
	{
		cout << "�ٸ���." << endl;
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

	// int�� ������(int&)���� ���� �迭�ȿ� ������ �ٲ��.
	for (int& n : arr) 
	{
		n++;
	}

	for (int n : arr) // ���⼱ �ٲ㵵 �ȹٲ� (Call-By-Value��)
	{
		cout << n << endl;
	}

	return 0;
}

int InputOutput()
{
	srand(time(0)); // iostream ���Ͽ� ���� ���Ե�

	//std::cout << "HelloWorld\n";
	// namespace ��� : std ����
	cout << "HelloWorld\n";

	int n;

	cin >> n;

	cout << "N : " << n << endl;
	
	int random = rand() % 10;

	printf("Random : %d\n", random); // C++������ C���� ���� ��밡��



	return 0;
}