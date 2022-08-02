#include "Framework.h"

enum Menu
{
	STORE = 1,
	INVEN,
	EXIT
};

enum ItemAction
{
	BUY = 1,
	SELL,
	EXITFUC
};

Player* player;

void ItemBuyAndSell();

int main()
{
	DataManager::Get()->LoadItemData();
	player = new Player();
	Menu menu;
	int inputNum = 0;

	cout << "플레이어의 초기 자본금을 입력하세요 : ";
	cin >> inputNum;
	player->SetPlayerMoney(inputNum);
	cout << endl;
	
	while (true)
	{
		Sleep(1000);
		system("cls");
		cout << "\t▶ 인벤토리 시스템 ◀" << endl;
		cout << endl << "1.상점, 2.인벤토리, 3.종료 : ";
		cin >> inputNum;
		menu = (Menu)inputNum;
		cout << endl;

		switch (menu)
		{
		case STORE:
			DataManager::Get()->PrintAllData();
			cout << "현재 소유 금액 : " << player->GetPlayerMoney() << endl << endl;
			
			ItemBuyAndSell();
			break;
		case INVEN:
			player->ShowItems();
			cout << endl << "아무키나 누르세요.." << endl;
			if(_getch())
				break;
		case EXIT:
			cout << "프로그램 종료" << endl;
			return 0;
		}
	}

	delete player;
	DataManager::Delete();
}

void ItemBuyAndSell()
{
	ItemAction itemAction;
	int inputNum;
	cout << "1.구매하기, 2.판매하기, 3.돌아가기 : ";
	cin >> inputNum;
	itemAction = (ItemAction)inputNum;

	switch (itemAction)
	{
	case BUY:
		cout << "구매할 아이템 번호를 입력하세요 : ";
		cin >> inputNum;
		player->CheckBuyItem(new Item(DataManager::Get()->GetItemData(inputNum - 1)));
		return;
	case SELL:
		player->ShowItems();
		if (player->GetPlayerItemCount() == 0)
		{
			cout << "판매할 아이템이 없습니다." << endl << endl;
			return;
		}
		cout << "판매할 아이템 번호를 입력하세요 : ";
		cin >> inputNum;
		player->CheckSellItem(inputNum-1);
		return;
	case EXITFUC:
		return;
	}
}
