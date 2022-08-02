#include "Framework.h"

Item::Item(ItemData data)
	:name(data.name), price(data.price), value(data.value)
{
	cout << name << " ����" << endl;
}

Item::~Item()
{
	cout << name << " �Ҹ�" << endl;
}

void Item::ShowInfo()
{
	cout << "----Info----" << endl;
	cout << "Name : " << name << endl;
	cout << "Price : " << price << endl;
	cout << "Value : " << value << endl;
}
