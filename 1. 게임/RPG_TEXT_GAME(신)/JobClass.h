#pragma once
#include "Inventory.h"

class JobClass
{
public:
	virtual void JobClass_Info() = 0;
	virtual bool EquipCheck(Item* weapon) = 0;
	virtual int GetJobClass() = 0;
};

class Knight : public JobClass
{
public:
	void JobClass_Info();
	bool EquipCheck(Item* weapon);
	int GetJobClass();
};

class Lancer : public JobClass
{
public:
	void JobClass_Info();
	bool EquipCheck(Item* weapon);
	int GetJobClass();
};

class Archer : public JobClass
{
public:
	void JobClass_Info();
	bool EquipCheck(Item* weapon);
	int GetJobClass();
};

class Wizard : public JobClass
{
public:
	void JobClass_Info();
	bool EquipCheck(Item* weapon);
	int GetJobClass();
};
