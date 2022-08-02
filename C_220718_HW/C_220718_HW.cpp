// 과제: 무기 테이블 만들어서 무기 정보 출력하기

#include "Framework.h"

int main()
{
	int inputNum;
	Weapon* weapon = nullptr;
	
	while (true)
	{
		cout << endl << "******* 무기 목록 *******" << endl;
		DataManager::GetInstance()->ShowWeaponsName();
		cout << endl << "정보를 확인할 무기의 번호를 입력하새요 : ";
		cin >> inputNum;
		cout << endl;

		weapon = new Weapon(DataManager::GetInstance()->GetWeaponData(inputNum));
		weapon->ShowInfo();

		cout << endl << "1. 목록으로, 2. 종료 : ";
		cin >> inputNum;

		if (inputNum == 2)
			break;
		Sleep(1000);
		system("cls");
		
	}
	DataManager::Delete();
	delete weapon;
}
