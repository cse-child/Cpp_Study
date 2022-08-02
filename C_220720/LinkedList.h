#pragma once

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void PushBack(int data);
	void PushFront(int data);

	void PopBack();
	/* 과제 : 링크드 리스트 함수 완성시키기 */
	void PopFront();
	void Insert(int data, uint pos); // pos 위치에 노드 (중간)삽입
	// ex) pos : 0 이면 처음 삽입, pos : 1 두번째 노드로 삽입
	void Erase(uint pos); // (중간)삭제

	void PrintData();

	void Clear();

private:
	Node* head; // 첫번째 노드의 주소값
	Node* tail; // 마지막 노드의 주소값

	uint size = 0;
};