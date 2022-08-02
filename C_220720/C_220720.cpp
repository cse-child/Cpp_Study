// Data Structure (자료구조)
// - 컴퓨터에서 자료를 처리할 때 효율적으로 관리하고 구조화시키기 위한 학문

/* 자료구조 종류
 -단순
 : 문자형, 정수형, 실수형

- 복합
    - 선형
    : 배열, 리스트, 스택, 큐 등등
    - 비선형
    : 그래프, 트리(재귀함수) 등

    // 리스트는 배열과 달리 중간 삽입/삭제가 자유롭다는 장점이 있지만
    // 실제 게임 프로그램에서는 중간 삽입/삭제를 지양해야 하므로
    // 잘 사용하지 않는다ㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏ
    // But 링크드 리스트는 취업할때 손코딩으로 보기도해서 외워야함

*/

#include "Framework.h"

int main()
{
    LinkedList list;

	cout << "-------- Data Print --------" << endl;
	list.PrintData();

    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
	list.PushBack(4);

	cout << "-------- Push Back 1,2,3,4 --------" << endl;
	list.PrintData();

	list.PushFront(50);
	cout << "-------- Push Front 50 --------" << endl;
	list.PrintData();

    list.PopBack();
	cout << "-------- Pop Back --------" << endl;
	list.PrintData();

	list.PopFront();
	cout << "-------- Pop Front --------" << endl;
	list.PrintData();
	
	list.Insert(10, 2);
	cout << "-------- Insert Data:10, pos:2 --------" << endl;
	list.PrintData();

	list.Erase(2);
	cout << "-------- Erase pos:2 --------" << endl;
	list.PrintData();

	list.Clear();
	cout << "-------- Clear --------" << endl;
	list.PrintData();
}
