// String (���ڿ�)
// 1. ���ڿ��� char���� �迭�̴�.
// 2. ���ڿ��� ���� ���������� null ���ڰ� ����.

// null ���� (\0)
// 1. ���ڿ��� �������� ��Ÿ���� ���ȴ�.
// 2. �������� �ʱⰪ���� ���ȴ�. (�����Ͱ� �ּҰ��� ������ ���� �ʴ�)

#include <stdio.h>
#include <time.h>

int GetStrLength(const char* str)
{
    int count = 0;
    while (true)
    {
        if (str[count] == NULL) // =='\0'
            return count;
        ++count;
    }
}

int main()
{
    time(NULL);
    char str[100] = "HelloWorld"; // 10����

    printf("%s\n", str);

    printf("str�� ũ�� : %d\n", sizeof(str));
    printf("str ���ڿ��� ���� : %d\n", GetStrLength(str));
    return 0;
}