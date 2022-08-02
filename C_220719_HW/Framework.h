#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum class Type
{
	NONE, FIRE, WATER, GRASS, STONE, POISON
};

const int MAX_MONSTER_NUM = 151;
const int MAX_SKILL_NUM = 7;
const int SKILL_NUM = 4; // ���� �� �ִ� ��ų ����

#include "DataManager.h"
#include "Monster.h"
#include "Skill.h"
#include "AttackSkill.h"
#include "BuffSkill.h"