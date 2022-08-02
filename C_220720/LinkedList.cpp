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
	// 1. ��� ����(newNode�� ������ ����� �ּҰ�)
	Node* newNode = new Node(data); // �Ҵ��(instancing)
	// 'new' �� �Ҵ�� ������ '�ּҰ�'�� ��ȯ��

	// 2. ������ ��尡 �ϳ��� ���°�� head�� ����Ű�� ���� ����.
	// head�� ������ ����� �ּҰ��� ����Ų��.
	if (head == nullptr)
		head = newNode;
	else // ��尡 �ϳ� �̻� ���� ��� ������ ����� ���� �ּҰ��� ������ ����� �ּҰ��� ����Ų��.
		tail->next = newNode;

	// 3. tail�� ������ ����� �ּҰ��� ����Ų��.
	tail = newNode;

	++size;
}

void LinkedList::PushFront(int data)
{
	// ��� 
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

	if (head->next == nullptr) // ��尡 �ϳ��ۿ� ���� ��Ȳ
	{
		delete head;

		head = nullptr;
		tail = nullptr;
		size = 0;

		return;
	}

	Node* prevNode = head; // ������ ���� ���

	while (prevNode->next != tail) // ������ ��尡 �ƴҶ�����
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
	if (head == nullptr) // �����Ͱ� ���� ��
		return;
	
	if (head->next == nullptr) // �����Ͱ� �� ���� ��
	{
		delete head;

		head = nullptr;
		tail = nullptr;
		size = 0;

		return;
	}

	Node* headNextNode = head->next; // �ι�° ������

	delete head;

	head = headNextNode;
	--size;
}

void LinkedList::Insert(int data, uint pos) 
{
	if (pos > size || pos < 0) // ���� �ִ� tail���� �ڿ� �߰��� ��� - ���� �ε���
	{
		cout << "�����Ͱ� �����ϴ� ���� ���� ��ġ�� �Է��ϼ̽��ϴ�." << endl;
		return;
	}
	else if (pos == 0) // �� �տ� �߰��� ���
	{
		PushFront(data);
		return;
	}
	else if (pos == size) // �� �ڿ� �߰��� ���
	{
		PushBack(data);
		return;
	}
	
	// �߰��� �߰��� ���
	Node* newNode = new Node(data);
	Node* prevNode = head; // pos ���� ��带 ������ ��

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
	if (head == nullptr) // �����Ͱ� ���� ��
		return;
	else if (size <= pos) // tail �� ��ġ�϶�
	{
		cout << "�����Ͱ� �����ϴ� ���� ���� ��ġ�� �Է��ϼ̽��ϴ�." << endl;
		return;
	}
	else if (pos == size-1) // �� �� �����͸� ���� ��
	{
		PopBack();
		return;
	}
	else if (pos == 0) // �� �� �����͸� ���� ��
	{
		PopFront();
		return;
	}

	// �߰��� ��ġ�ϴ� �����͸� ���� ��
	Node* prevNode = head; // pos ���� ��带 ������ ��
	int nextCount = 0;

	while (nextCount != pos-1)
	{
		prevNode = prevNode->next;
		++nextCount;
	}

	Node* nextNode = prevNode->next->next; // ���� ���(pos)�� ������� ����
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
		cout << count++ << "��° ��� : " << node->data << endl;
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
