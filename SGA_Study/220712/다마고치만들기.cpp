#include <iostream>
#include <string>

using namespace std;

enum Menu
{
	PLAY,
	SLEEP,
	WASHING,
	FEEDING,
	EXIT
};

class Pet
{
public:
	Pet()
		:hunger(50), dirty(50), tired(50), happy(50)
	{
		cout << "\t\t[ 다마고치 키우기 ]" << endl << endl;
		cout << "\t펫의 상태는 포만감/깨끗함/피로도/행복도 4가지" << endl;
		cout << "포만감/깨끗함/행복도가 '0' 이 되거나 피로도가 '100' 이 되면 Game Over" << endl << endl;
	}

	void Play()
	{
		happy += 40;
		tired += 10;
		dirty -= 15;
		hunger -= 10;
		cout << name << "와 신나게 놀아주었습니다 !" << endl;
		cout << "[ 행복도/피로도 증가, 깨끗함/포만감 감소 ]" << endl;
		PrintState();
	}

	void Sleep()
	{
		tired = 0;
		hunger -= 15;
		dirty -= 10;
		cout << name << "(은/는) 깊은 잠에 빠졌습니다 !" << endl;
		cout << "[ 피로도가 전부 사라졌습니다. 포만감/깨끗함 감소 ]" << endl;
		PrintState();
	}

	void Washing()
	{
		dirty = 100;
		tired += 10;
		hunger -= 10;
		happy -= 20;

		cout << name << "(은/는) 깨끗하게 씻겨졌습니다 !" << endl;
		cout << "[ 깨끗함/피로도 증가,/포만감/행복도 감소 ]" << endl;
		PrintState();
	}

	void Peeding()
	{
		hunger = 100;
		happy += 15;
		dirty -= 15;
		cout << name << "(은/는) 모든 사료를 다 먹었습니다 !" << endl;
		cout << "[ 포만감/행복도 증가, 깨끗함 감소 ]" << endl;
		PrintState();
	}

	void PrintState()
	{
		CheckState(&hunger, "포만감");
		CheckState(&dirty, "깨끗함");
		CheckState(&tired, "피로도");
		CheckState(&happy, "행복도");

		cout << endl << "----------- " << name << "(" << age << "세)의 상태 -----------" << endl;
		cout << "\t포만감\t\t" << hunger << endl;
		cout << "\t깨끗함\t\t" << dirty << endl;
		cout << "\t피로도\t\t" << tired << endl;
		cout << "\t행복도\t\t" << happy << endl;
		cout << "------------------------------------" << endl << endl;
	}

	void CheckState(int* state, string stateName)
	{
		if (*state >= 100)
			*state = 100;
		if (*state <= 0)
			*state = 0;

		if (((stateName == "포만감" || stateName == "깨끗함" || stateName == "행복도") && *state == 0)
			|| (stateName == "피로도" && *state == 100)) {
			cout << endl << stateName << " 상태가 좋지않아 " << name << "(이)가 쓰러졌습니다." << endl;
			cout << "Game Over...." << endl;
			exit(0);
		}
	}

	void NewPet()
	{
		cout << "새로운 펫의 이름을 지어주세요 : ";
		cin >> name;
		cout << name << "(은/는) 몇살인가요? ";
		cin >> age;
		cout << endl;
		PrintState();
	}

private:
	string name = "";	// 이름
	int age;		// 나이
	int hunger;		// 포만감
	int dirty;		// 깨끗함
	int tired;		// 피로도
	int happy;		// 행복도
};

int main()
{
	Pet pet;
	int menuNum = 0;

	pet.NewPet();

	Menu menu;

	while (true)
	{
		cout << "1.놀아주기, 2.잠자기, 3.씻기, 4.밥주기, 5.게임종료" << endl;
		cout << "펫과 어떤 행동을 하시겠습니까?";
		cin >> menuNum;
		cout << endl;
		menu = (Menu)(menuNum - 1);

		switch (menu)
		{
		case PLAY:
			pet.Play();
			break;
		case SLEEP:
			pet.Sleep();
			break;
		case WASHING:
			pet.Washing();
			break;
		case FEEDING:
			pet.Peeding();
			break;
		case EXIT:
			cout << "게임을 종료합니다 !" << endl;
			return 0;
		}
	}
}