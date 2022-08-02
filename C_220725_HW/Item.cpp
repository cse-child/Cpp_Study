#include "Framework.h"

Item::Item(ItemData data)
	:name(data.name), price(data.price), attack(data.attack)
{
}

Item::~Item()
{
}

void Item::ShowInfo()
{
	cout <<"\t" << name << "\t" << price << "\t" << attack << endl;
}
