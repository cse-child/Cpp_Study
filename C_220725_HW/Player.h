#pragma once

class Player
{
public:
	Player();
	~Player();

	void ShowItems();
	void CheckBuyItem(Item* item);
	void CheckSellItem(int index);
	void SetPlayerMoney(int m) { money = m; }
	int GetPlayerMoney() { return money; }
	int GetPlayerItemCount() { return items.size(); }

private:
	vector<Item*> items;
	int money = 0;
	int itemCount = 0;
};