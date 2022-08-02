#include "Framework.h"

Weapon::Weapon()
{
}

Weapon::Weapon(DataManager::WeaponData data)
{
	//SetType(data.type); // data.type = string�� ����
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
	cout << "PRICE : " << wInfo.price << "��" << endl;
	cout << "CLASS : " << wInfo.wClass << endl;
	cout << "------------------" << endl;
}

//void Weapon::SetType(string type)
//{
//	if (type == "����")
//		Weapon::type = SHIELD;
//	else if (type == "Į")
//		Weapon::type = KNIFE;
//	else if (type == "ȭ��")
//		Weapon::type = ARROW;
//	else if (type == "�ܰ�")
//		Weapon::type = DAGGER;
//}
