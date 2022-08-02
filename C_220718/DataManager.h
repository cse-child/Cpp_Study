#pragma once

class DataManager
{
private:
	static const int MAX_MONSTER_NUM = 151;
public:
	struct MonsterData
	{
		int key;
		string name;
		string type;
		int hp;
		int attack;
		int defence;
		int speed;
		int special;
	};
private:
	DataManager();
	~DataManager();

public:
	/*static DataManager* GetInstance()
	{
		static DataManager instance;
		return &instance;
	}*/
	static DataManager* GetInstance()
	{
		if (instance == nullptr)
			instance = new DataManager();
		return instance;
	}

	static void Delete()
	{
		delete instance;
	}

	// ������Ͽ��� �Լ��� �����ϸ� �ڵ����� ����� �Լ��� ����ȴ�.
	// �ζ����Լ� : �Լ��� �ν����� �ʰ� ��¥ ������ �νĽ��� �ӵ��� ���� �Լ�
	// ������ �ʰ� ���־��� �Լ��� ���
	//  inline  viud Fun();
	
	MonsterData GetMonsterData(int key) { return monsterDatas[key-1]; }
private :
	void LoadMonsterData();
private:
	static DataManager* instance;

	MonsterData monsterDatas[MAX_MONSTER_NUM];
};
