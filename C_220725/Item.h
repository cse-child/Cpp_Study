#pragma once

class Item
{
public:
	Item(ItemData data);
	~Item();

	void ShowInfo();

private:
	string name;
	int price;
	int value;
};