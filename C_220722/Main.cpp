#include "Framework.h"

class Item
{
public:
	Item(string name, int price) : name(name), price(price)
	{

	}

	void ShowInfo()
	{
		cout << name << " : " << price << "Gold" << endl;
	}

private:
	string name;
	int price;
};

int main()
{
	DoublyLinkedList<Item *> * itemList = new DoublyLinkedList<Item *>();

	itemList->PushBack(new Item("Knife", 500));
	itemList->PushBack(new Item("Bow", 1000));
	itemList->PushBack(new Item("Spear", 5500));

	for (int i = 0; i < itemList->GetSize(); i++)
	{
		itemList->GetData(i)->ShowInfo();
	}

	delete itemList;
}

int ListTest()
{
	DoublyLinkedList<int> list;

	list.PushBack(1);
	list.PushBack(3);
	list.PushBack(5);

	list.PushFront(10);
	list.PushFront(11);

	//list.PopBack();
	//list.PopFront();4, 2;

	list.Insert(2, 1);
	list.Insert(4, 3);

	list.Erase(3);

	for (int i = 0; i < list.GetSize(); i++)
	{
		printf("%d ³ëµå : %d\n", i, list.Find(i)->data);
	}

	return 0;
}