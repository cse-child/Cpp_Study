#include "Framework.h"

Monster::Monster()
{
}

Monster::Monster(MonsterData data)
	:name(data.name), typeName(data.type)
{
	SetType(data.type);
	initStatus.SetData(data);
	curStatus.SetData(data);
}

Monster::~Monster()
{
}

void Monster::Damage(Type type, int damage)
{
	int resultDamage = damage - curStatus.defence;

	if (resultDamage < 0)
		resultDamage = 0;

	int attackType = (int)type;
	int defenceType = (int)types[0];

	// �� < ��, �� < Ǯ, Ǯ < ��
	if (attackType % 3 == defenceType - 1) // ���� �Ӽ�
	{
		resultDamage *= 0.5;
	}
	else if ((attackType+1) % 3 == defenceType - 1) // ��� �Ӽ�
	{
		resultDamage *= 1.5;
	}

	curStatus.hp -= resultDamage;
	cout << name << " �� " << resultDamage << "��ŭ ü�� ���� !" << endl;
	cout << name << " HP : " << curStatus.hp << " / " << initStatus.hp << endl;	
}

void Monster::Attack(Monster* target)
{
	ShowSkillInfo();
	cout << endl << name << "�� ��ų ���� : ";
	int selectSkill;
	cin >> selectSkill;
	cout << endl;

	if (selectSkill > skillCount) return;

	Skill* skill = skills[selectSkill - 1];

	cout << name << "(��/��) ";

	if (skill->GetSkillType() == Skill::SkillType::ATTACK)
		skills[selectSkill - 1]->Attack(target, curStatus);
	else
		skills[selectSkill - 1]->Buff(this);
}

void Monster::EnemyAttack(Monster * target)
{
	int selectSkill = rand() % skillCount + 1;

	if (selectSkill > skillCount) return;

	Skill* skill = skills[selectSkill - 1];

	cout << endl << name << "(��/��) ";

	if (skill->GetSkillType() == Skill::SkillType::ATTACK)
		skills[selectSkill - 1]->Attack(target, curStatus);
	else
		skills[selectSkill - 1]->Buff(this);
}

void Monster::ShowInfo()
{
	cout << "----Info----" << endl;
	cout << "Name : " << name << endl;
	cout << "Type : " << typeName << endl;
	cout << "HP : " << curStatus.hp << "/" << initStatus.hp << endl;
	cout << "ATK : " << curStatus.attack << "/" << initStatus.attack << endl;
	cout << "DEF : " << curStatus.defence << "/" << initStatus.defence << endl;
	cout << "SPD : " << curStatus.speed << "/" << initStatus.speed << endl;
	cout << "SPE : " << curStatus.special << "/" << initStatus.special << endl;
}

void Monster::ShowSkillInfo()
{
	//cout << "-----SkillInfo-----" << endl;
	for (int i = 0; i < skillCount; i++)
	{
		cout << (i + 1) << ". ";
		skills[i]->ShowInfo();
	}
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
	if (type == "�Ҳ�")
		return Type::FIRE;
	else if (type == "Ǯ")
		return Type::GRASS;
	else if (type == "��")
		return Type::WATER;
	else if (type == "����")
		return Type::STONE;
	else if (type == "��")
		return Type::POISON;
	else
		return Type::NONE;
}

void Monster::AddSkill(int skillKey)
{
	if (skillCount >= SKILL_NUM) return;

	SkillData data = DataManager::GetInstance()->GetSkillData(skillKey);

	if (data.skillType == Skill::ATTACK)
		skills[skillCount++] = new AttackSkill(data);
	else
		skills[skillCount++] = new BuffSkill(data);
		
}

void Monster::IncreaseStatus(StatusType statusType, int value)
{
	switch (statusType)
	{
	case Monster::HP:
		curStatus.hp += value;
		if (curStatus.hp > initStatus.hp)
			curStatus.hp = initStatus.hp;

		cout << name << " ü�� ȸ�� !" << endl;
		break;
	case Monster::ATK:
		curStatus.attack += value;
		cout << name << "���ݷ� ��� !" << endl;
		break;
	case Monster::DEF:
		curStatus.defence += value;
		cout << name << "���� ��� !" << endl;
		break;
	case Monster::SPD:
		curStatus.speed += value;
		cout << name << "�ӵ� ��� !" << endl;
		break;
	case Monster::SPE:
		curStatus.special += value;
		cout << name << "����� ?" << endl;
		break;
	}
}
