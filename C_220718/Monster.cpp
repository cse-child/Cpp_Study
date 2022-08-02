#include "Framework.h"

Monster::Monster(DataManager::MonsterData data)
	:name(data.name), typeName(data.type)
{
	SetType(data.type);
	initStatus.SetData(data);
	curStatus.SetData(data);
}

Monster::~Monster()
{
}

void Monster::ShowInfo()
{
	cout << "----Info----" << endl;
	cout << "Name : " << name << endl;
	cout << "Type : " << typeName << endl;
	cout << "HP : " << initStatus.hp << "/" << curStatus.hp << endl;
	cout << "ATK : " << initStatus.attack << "/" << curStatus.attack << endl;
	cout << "DEF : " << initStatus.defence << "/" << curStatus.defence << endl;
	cout << "SPD : " << initStatus.speed << "/" << curStatus.speed << endl;
	cout << "SPE : " << initStatus.special << "/" << curStatus.special << endl;
}

void Monster::SetType(string type)
{
	int pos = type.find_first_of(',');

	if (pos == string::npos)
	{
		types[0] = StringToType(type);
		types[1] = Type::NONE;
		return;
	}

	string temp = type.substr(0, pos);
	types[0] = StringToType(temp);

	temp = type.substr(pos + 1, temp.length());
	types[1] = StringToType(temp);
}

Type Monster::StringToType(string type)
{
	if (type == "불꽃")
		return Type::FIRE;
	else if (type == "풀")
		return Type::GRASS;
	else if (type == "물")
		return Type::WATER;
	else if (type == "바위")
		return Type::STONE;
	else if (type == "독")
		return Type::POISON;
	else
		return Type::NONE;
}
