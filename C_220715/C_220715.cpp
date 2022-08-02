// 상속 (Inheritance)
// : 코드를 재사용할 수 있는 방법 중 하나
// 규모 확장, 관계의 한 유형

// 객체 지향 4대 요소
// 추상화, 캡슐화, 상속성, 다형성

#include "Framework.h"

int main()
{
    int selectClassNum = 0;
    Character* player = nullptr; // NULL = 0, nullptr = *0..?
    Character* monster = new Warrior("트롤", 10, 10);

    cout << "직업을 선택하시오." << endl;
    cout << "1. 전사, 2. 마법사" << endl;
    cin >> selectClassNum;

    switch (selectClassNum)
    {
    case 1:
        player = new Warrior();
        break;
    case 2:
        player = new Magician();
        break;
    default:
        break;
    }

    player->ShowInfo();

    player->Skill(monster);
}

int Inheritance()
{
    Warrior* warrior = new Warrior();
    warrior->ShowInfo();

    Magician* magician = new Magician();
    magician->ShowInfo();

    // Casting(형변환)
    // Warrior -> Character
    // 자식 -> 부모

    // 업캐스팅 : 자식클래스가 부모클래스로 형변환 하는 경우
    magician->Attack(warrior);

    warrior->Attack(magician);

    return 0;
}

