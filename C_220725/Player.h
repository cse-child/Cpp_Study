#pragma once

class Player
{
public:
	Player();
	~Player();

	void ShowItems();
	void AddItem(Item* item) { items.push_back(item); }

private:
	vector<Item*> items;
};