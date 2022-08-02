#include "Framework.h"

Player::Player()
{
}

Player::~Player()
{
	for (Item* item : items)
		delete item;
}

void Player::ShowItems()
{
	if (items.size() == 0)
	{
		cout << endl << "Empty Inventory.." << endl;
		return;
	}

	int count = 1;
	cout << endl << "------------ My Inventory ------------" << endl;
	cout << "����\t�����۸�\t����\t���ݷ�" << endl;
	for (Item* item : items)
	{
		cout << "  " << count++;
		item->ShowInfo();
	}
		
	cout << "--------------------------------------" << endl;
}

void Player::CheckBuyItem(Item * item)
{
	if (money >= item->GetItemMoney())
	{
		money -= item->GetItemMoney();
		items.push_back(item);
		cout << "���� ����! ���� �ܾ� : " << money << endl << endl;
	}
	else // �������� ������ ���� ������ ���
	{
		cout << "�÷��̾��� �������� �����մϴ�.." << endl << endl;
	}
}

void Player::CheckSellItem(int index)
{
	money += items[index]->GetItemMoney() * SELL_PERCENT; // ������ ���ȶ� �������� �� ����
	items.erase(items.begin() + index);
	cout << "�Ǹ� ����! ���� ���� �ܾ� : " << money << endl << endl;

}
