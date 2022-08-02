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
	for (Item* item : items)
		item->ShowInfo();
}
