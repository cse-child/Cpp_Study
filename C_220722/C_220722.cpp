// Template
// - 함수 또는 클래스를 사용할 때 하나의 자료형에 얽매이지 않고
// 여러 자요형을 쓸 수 있게 도와주는 도구

#include "Framework.h"

// 클래스 템플릿
// template <typename T>
template <class T>
class AddOperator
{
public:
    AddOperator(T x, T y) : x(x), y(y)
    {

    }

    void Print()
    {
        cout << x << " + " << y << " = " << x + y << endl;
    }

private:
    T x, y;
};

// 함수 템플릿
// 사용자 정의 자료형(초록글씨)
template <typename T> 

void Swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10, b = 20;

    //Swap(a, b);
    //printf("a : %d, b : %d\n", a, b);

    AddOperator<int> intAdd(a, b);
    intAdd.Print();

    float c = 3.5f, d = 8.6f;

    AddOperator<float> floatAdd(c, d);
    floatAdd.Print();
    //Swap(c, d);
    //printf("c : %f, d : %f\n", c, d);
}