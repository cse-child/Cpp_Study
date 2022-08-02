/* STL(Standard Template Library)

▶ 컨테이너
   - 연속 컨테이너 : ★vector, list, deque
   - 연관 컨테이너 : ★map(완전 이진 트리, 자동정렬, O(log n)), ★unordered_map(해시 테이블, O(1)), set, unordered_set
   - 컨테이너 어댑터 : queue, stack
   * 중간에 삽입삭제가 자주 일어나면 '연속', 데이터 검색을 자주하면 '연관'

▶ 이터레이터 (Iterator)
   - 컨테이너를 사용하기 위한 도구
   - 노드의 주소값을 가지는 변수

▶ 알고리즘
   - 검색, 정렬
*/

#include "Framework.h"

int main()
{
    DataManager::Get()->LoadItemData();

    Player* player = new Player();

    player->AddItem(new Item(DataManager::Get()->GetItemData(1)));
    player->AddItem(new Item(DataManager::Get()->GetItemData(1)));
    player->AddItem(new Item(DataManager::Get()->GetItemData(3)));
    player->AddItem(new Item(DataManager::Get()->GetItemData(4)));
    player->AddItem(new Item(DataManager::Get()->GetItemData(2)));

    player->ShowItems();

    delete player;
}

int vectorTest()
{
    //vector<int> intVec;
    //intVec.resize(10); // resize: 값을 0으로 초기화
    //intVec.reserve(10); // 초기화 X

    // vector<int> intVec(10); // 하지만 이게 베스트, 0으로 초기화
    vector<int> intVec(10, 1); // 1로 10개 초기화


    for (int i = 0; i < 10; i++)
    {
        intVec[i] = rand() % 10;
       // intVec.push_back(rand() % 10); // 메모리 소모 多
    }

    for (int i = 0; i < intVec.size(); i++)
    {
        cout << i << "번째 노드 : " << intVec[i] << endl;
    }
    
    sort(intVec.begin(), intVec.end());

    for (int n : intVec)
    {
        cout << n << endl;
    }

    return 0;
}

int ListTest()
{
    list<int> intList;

    intList.push_back(1);
    intList.push_back(3);
    intList.push_back(5);

    intList.push_front(10);
    intList.push_front(11);

    intList.sort();

    // begin : 노드의 첫번째 주소값을 가르키는 노드
    // end : 노드의 마지막 추소값을 가르키는 노드
    list<int>::iterator iter = intList.begin();
    
    int count = 0;
    for (; iter != intList.end(); iter++)
    {
        cout << count++ << "번째 노드 : " << *iter << endl;
    }
    
    int value = 0;
    cout << "찾고싶은 값을 입력하시오." << endl;
    cin >> value;

    iter = find(intList.begin(), intList.end(), value);

    if (iter != intList.end()) {
        cout << "값이 있습니다." << endl;
    }
    else
    {    
        cout << "값이 없습니다." << endl;
    }

    return 0;
}
