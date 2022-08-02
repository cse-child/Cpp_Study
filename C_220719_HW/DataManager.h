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
	int elementType; // 속성타입
	int skillType; // 스킬타입
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

	// 헤더파일에서 함수를 정의하면 자동으로 언라인 함수로 선언된다.
	// 인라인함수 : 함수로 인식하지 않고 통짜 스스로 인식시켜 속도를 높인 함수
	// 무겁지 않고 자주쓰는 함수에 사용
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
