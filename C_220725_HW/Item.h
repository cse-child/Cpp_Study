#pragma once

class Item
{
public:
	Item(ItemData data);
	~Item();

	void ShowInfo();
	int GetItemMoney() { return price; }

private:
	string name;
	int price;
	int attack;
};