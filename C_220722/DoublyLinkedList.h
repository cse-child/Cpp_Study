#pragma once

template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void PushBack(T data);
	void PushFront(T data);

	void PopBack();
	void PopFront();

	void Insert(T data, uint pos);
	void Erase(uint pos);

	Node<T>* Find(uint pos);
	T GetData(uint pos);

	uint GetSize() { return size; }

private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int size = 0;
};

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
}

template <typename T>
inline void DoublyLinkedList<T>::PushBack(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (head == nullptr) // 노드가 하나도 없다.
	{
		head = newNode;
	}
	else // 노드가 하나 이상 있다.
	{
		tail->next = newNode;
		newNode->prev = tail;
	}

	tail = newNode;

	size++;
}

template<typename T>
inline void DoublyLinkedList<T>::PushFront(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (head == nullptr)
	{
		tail = newNode;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
	}

	head = newNode;

	size++;
}

template<typename T>
inline void DoublyLinkedList<T>::PopBack()
{
	if (head == nullptr)
	{
		return;
	}
	else if(head->next == nullptr)
	{
		delete head;

		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	else
	{
		Node<T>* prev = tail->prev;
		prev->next = nullptr;
		delete tail;
		tail = prev;
		size--;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::PopFront()
{
	if (head == nullptr)
	{
		return;
	}
	else if (head->next == nullptr)
	{
		delete head;

		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	else
	{
		Node<T>* front = head->next;
		front->prev = nullptr;
		delete head;
		head = front;
		size--;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::Insert(T data, uint pos)
{
	if (pos == 0)
	{
		PushFront(data);
		return;
	}
	else if (pos >= size)
	{
		PushBack(data);
		return;
	}

	Node<T>* newNode = new Node<T>(data);
	Node<T>* prevNode = Find(pos - 1);

	newNode->prev = prevNode;
	newNode->next = prevNode->next;
	
	prevNode->next->prev = newNode;
	prevNode->next = newNode;

	size++;
}

template<typename T>
inline void DoublyLinkedList<T>::Erase(uint pos)
{
	if (head == nullptr)
		return;
	else if (pos == 0)
	{
		PopFront();
		return;
	}
	else if (pos >= size)
	{
		PopBack();
		return;
	}
	Node<T>* deleteNode = Find(pos);

	deleteNode->prev->next = deleteNode->next;
	deleteNode->next->prev = deleteNode->prev;
	
	delete deleteNode;

	size--;
}

template <typename T>
inline Node<T>* DoublyLinkedList<T>::Find(uint pos)
{
	if (pos < 0 || pos >= size)
		return nullptr;

	Node<T>* findNode;

	if (pos < size / 2) // 위치가 앞쪽이면 앞에서부터 검색
	{
		findNode = head;

		for (int i = 0; i < pos; i++)
			findNode = findNode->next;
	}
	else // 위치가 뒤쪽이면 뒤에서부터 검색
	{	
		findNode = tail;

		for (int i = 0; i < size - 1 - pos; i++)
		{
			findNode = findNode->prev;
		}
	}

	return findNode;
}

template<typename T>
inline T DoublyLinkedList<T>::GetData(uint pos)
{
	return Find(pos)->data;
}
