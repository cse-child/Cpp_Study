#include "Framework.h"

int main()
{
    BoardGame* bg = new BoardGame();

    int size = 0;
    cout << "Size : ";
    cin >> size;

    /* 2차원 배열 동적할당해서 사용하는 방법 */
    int** board; // *board 포인터변수의 주소값을 가지는 포인터변수

    board = new int* [size]; // int* 포인터 배열 5개를 할당하면
    // 메모리에는 board*[0], board*[1], ..., board*[4] 저장됨

    for (int i = 0; i < size; i++)
    {
        board[i] = new int[size];
        // 그안에서 board[0],[1],... 들을 또 할당하면
        // 2차원 배열처럼 사용할 수 있음
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = i * size + j;

            printf("board[%d][%d] : %d\n", i, j, board[i][j]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        delete[] board[i]; // 배열의 내부까지 할당 해제
    }

    delete[] board; // 이렇게만 해제하면 1차원배열만 해제되는 것
    // 내부도 하나씩 해제해줘야함
}

