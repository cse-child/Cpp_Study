#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class Type
{
	NONE, FIRE, WATER, GRASS, STONE, POISON
};

#include "DataManager.h"
#include "Monster.h"
#include "Skill.h"
#include "AttackSkill.h"
#include "BuffSkill.h"