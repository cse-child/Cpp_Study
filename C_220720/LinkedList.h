#pragma once

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void PushBack(int data);
	void PushFront(int data);

	void PopBack();
	/* ���� : ��ũ�� ����Ʈ �Լ� �ϼ���Ű�� */
	void PopFront();
	void Insert(int data, uint pos); // pos ��ġ�� ��� (�߰�)����
	// ex) pos : 0 �̸� ó�� ����, pos : 1 �ι�° ���� ����
	void Erase(uint pos); // (�߰�)����

	void PrintData();

	void Clear();

private:
	Node* head; // ù��° ����� �ּҰ�
	Node* tail; // ������ ����� �ּҰ�

	uint size = 0;
};