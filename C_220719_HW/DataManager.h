#pragma once

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

struct SkillData
{
	string name;
	int elementType; // �Ӽ�Ÿ��
	int skillType; // ��ųŸ��
	int usingCount;
	int power;
};

class DataManager
{
public:
	
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
	SkillData GetSkillData(int key) { return skillDatas[key - 1]; }
private :
	void LoadMonsterData();
	void LoadSkillData();

private:
	static DataManager* instance;

	MonsterData monsterDatas[MAX_MONSTER_NUM];
	SkillData skillDatas[MAX_SKILL_NUM];
};
