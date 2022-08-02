#include "Framework.h"

Weapon::Weapon()
{
}

Weapon::Weapon(DataManager::WeaponData data)
{
	//SetType(data.type); // data.type = string형 문자
	wInfo.SetData(data);
}

Weapon::~Weapon()
{
}

void Weapon::ShowInfo()
{
	cout << "------ Info ------" << endl;
	cout << "Name : " << wInfo.name << endl;
	cout << "Type : " << wInfo.type << endl;
	cout << "ATK : " << wInfo.attack << endl;
	cout << "PRICE : " << wInfo.price << "￦" << endl;
	cout << "CLASS : " << wInfo.wClass << endl;
	cout << "------------------" << endl;
}

//void Weapon::SetType(string type)
//{
//	if (type == "방패")
//		Weapon::type = SHIELD;
//	else if (type == "칼")
//		Weapon::type = KNIFE;
//	else if (type == "화살")
//		Weapon::type = ARROW;
//	else if (type == "단검")
//		Weapon::type = DAGGER;
//}
