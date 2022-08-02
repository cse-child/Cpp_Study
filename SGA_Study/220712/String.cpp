// String (문자열)
// 1. 문자열은 char형의 배열이다.
// 2. 문자열의 제일 마지막에는 null 문자가 들어간다.

// null 문자 (\0)
// 1. 문자열의 마지막을 나타낼때 사용된다.
// 2. 포인터의 초기값으로 사용된다. (포인터가 주소값을 가지고 있지 않다)

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
    char str[100] = "HelloWorld"; // 10글자

    printf("%s\n", str);

    printf("str의 크기 : %d\n", sizeof(str));
    printf("str 문자열의 길이 : %d\n", GetStrLength(str));
    return 0;
}