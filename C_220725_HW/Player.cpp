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
	cout << "개수\t아이템명\t가격\t공격력" << endl;
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
		cout << "구매 성공! 남은 잔액 : " << money << endl << endl;
	}
	else // 아이템을 구매할 돈이 부족한 경우
	{
		cout << "플레이어의 소지금이 부족합니다.." << endl << endl;
	}
}

void Player::CheckSellItem(int index)
{
	money += items[index]->GetItemMoney() * SELL_PERCENT; // 물건을 되팔땐 원가에서 좀 깎음
	items.erase(items.begin() + index);
	cout << "판매 성공! 현재 보유 잔액 : " << money << endl << endl;

}
