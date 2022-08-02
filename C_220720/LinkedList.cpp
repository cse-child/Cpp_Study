#include "Framework.h"

LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::PushBack(int data)
{
	// 1. 노드 생성(newNode는 생성된 노드의 주소값)
	Node* newNode = new Node(data); // 할당됨(instancing)
	// 'new' 는 할당된 변수의 '주소값'을 반환함

	// 2. 생성된 노드가 하나도 없는경우 head가 가르키는 값이 없다.
	// head는 생성된 노드의 주소값을 가르킨다.
	if (head == nullptr)
		head = newNode;
	else // 노드가 하나 이상 있을 경우 마지막 노드의 다음 주소값은 생성된 노드의 주소값을 가르킨다.
		tail->next = newNode;

	// 3. tail은 생성된 노드의 주소값을 가르킨다.
	tail = newNode;

	++size;
}

void LinkedList::PushFront(int data)
{
	// 노드 
	Node* newNode = new Node(data);

	if (head == nullptr)
		tail = newNode;
	else
		newNode->next = head;
	
	head = newNode;

	++size;
}

void LinkedList::PopBack()
{
	if (head == nullptr)
		return;

	if (head->next == nullptr) // 노드가 하나밖에 없는 상황
	{
		delete head;

		head = nullptr;
		tail = nullptr;
		size = 0;

		return;
	}

	Node* prevNode = head; // 마지막 이전 노드

	while (prevNode->next != tail) // 마지막 노드가 아닐때까지
	{
		prevNode = prevNode->next;
	}

	delete tail;

	tail = prevNode;
	tail->next = nullptr;

	--size;
}

void LinkedList::PopFront()
{
	if (head == nullptr) // 데이터가 없을 때
		return;
	
	if (head->next == nullptr) // 데이터가 한 개일 때
	{
		delete head;

		head = nullptr;
		tail = nullptr;
		size = 0;

		return;
	}

	Node* headNextNode = head->next; // 두번째 데이터

	delete head;

	head = headNextNode;
	--size;
}

void LinkedList::Insert(int data, uint pos) 
{
	if (pos > size || pos < 0) // 현재 있는 tail보다 뒤에 추가할 경우 - 오류 인덱스
	{
		cout << "데이터가 존재하는 범위 밖의 위치를 입력하셨습니다." << endl;
		return;
	}
	else if (pos == 0) // 맨 앞에 추가할 경우
	{
		PushFront(data);
		return;
	}
	else if (pos == size) // 맨 뒤에 추가할 경우
	{
		PushBack(data);
		return;
	}
	
	// 중간에 추가할 경우
	Node* newNode = new Node(data);
	Node* prevNode = head; // pos 이전 노드를 저장할 것

	int nextCount = 0;

	while (nextCount != pos - 1)
	{
		prevNode = prevNode->next;
		++nextCount;
	}
	newNode->next = prevNode->next;
	prevNode->next = newNode;

	++size;
}

void LinkedList::Erase(uint pos) // pos = 2
{
	if (head == nullptr) // 데이터가 없을 때
		return;
	else if (size <= pos) // tail 밖 위치일때
	{
		cout << "데이터가 존재하는 범위 밖의 위치를 입력하셨습니다." << endl;
		return;
	}
	else if (pos == size-1) // 맨 끝 데이터를 지울 때
	{
		PopBack();
		return;
	}
	else if (pos == 0) // 맨 앞 데이터를 지울 때
	{
		PopFront();
		return;
	}

	// 중간에 위치하는 데이터를 지울 때
	Node* prevNode = head; // pos 이전 노드를 저장할 것
	int nextCount = 0;

	while (nextCount != pos-1)
	{
		prevNode = prevNode->next;
		++nextCount;
	}

	Node* nextNode = prevNode->next->next; // 지울 노드(pos)의 다음노드 저장
	delete prevNode->next;
	prevNode->next = nextNode;
	--size;
}

void LinkedList::PrintData()
{
	if (head == nullptr)
	{
		cout << "Empty" << endl << endl;
		return;
	}

	uint count = 0;

	for (Node* node = head; node != nullptr; node = node->next)
	{
		cout << count++ << "번째 노드 : " << node->data << endl;
	}
	cout << endl;
}

void LinkedList::Clear()
{
	while (size != 0)
	{
		PopBack();
	}
}
