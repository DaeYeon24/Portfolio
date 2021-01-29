#include "JobClass.h"

bool Knight::EquipCheck(Item* weapon)
{
	Sword* sword = dynamic_cast<Sword*>(weapon);
	if (sword == NULL)
		return false;
	return true;
}

void Knight::JobClass_Info()
{
	Draw().Text("전 사", 4);
}

int Knight::GetJobClass()
{
	return KNIGHT;
}

bool Lancer::EquipCheck(Item* weapon)
{
	Spear* spear = dynamic_cast<Spear*>(weapon);
	if (spear == NULL)
		return false;
	return true;
}

int Lancer::GetJobClass()
{
	return LANCER;
}

void Lancer::JobClass_Info()
{
	Draw().Text("창 병", 4);
}

bool Archer::EquipCheck(Item* weapon)
{
	Bow* bow = dynamic_cast<Bow*>(weapon);
	if (bow == NULL)
		return false;
	return true;
}

int Archer::GetJobClass()
{
	return ARCHER;
}

void Archer::JobClass_Info()
{
	Draw().Text("궁 수", 4);
}

bool Wizard::EquipCheck(Item* weapon)
{
	Wand* wand = dynamic_cast<Wand*>(weapon);
	if (wand == NULL)
		return false;
	return true;
}

int Wizard::GetJobClass()
{
	return WIZARD;
}

void Wizard::JobClass_Info()
{
	Draw().Text("법 사", 4);
}