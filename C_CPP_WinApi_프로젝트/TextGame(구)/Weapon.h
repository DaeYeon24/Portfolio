#pragma once
#include "Draw.h"

class Weapon
{
protected:
	Draw m_DM;
	int m_iWeaponType;
	string m_strWeaponName;
	int m_iWeaponAtt;
	int m_iWeaponPrice;
public:
	Weapon();
	~Weapon();
	inline int GetType()
	{
		return m_iWeaponType;
	}
	inline string GetName()
	{
		return m_strWeaponName;
	}
	inline int GetAtt()
	{
		return m_iWeaponAtt;
	}
	inline int GetPrice()
	{
		return m_iWeaponPrice;
	}
	void Weapon_Info(int line, bool show = false);
	void WeaponSetting(int type, string name, int att, int price);
	virtual void Skill(int* damage, int* hp) = 0; //순수 가상
};

class Sword : public Weapon
{
public:
	Sword();
	~Sword();
	void Skill(int* damage, int* hp);
};

class Bow : public Weapon
{
public:
	Bow();
	~Bow();
	void Skill(int* damage, int* hp);
};

class Spear : public Weapon
{
public:
	Spear();
	~Spear();
	void Skill(int* damage, int* hp);
};

class Wand : public Weapon
{
public:
	Wand();
	~Wand();
	void Skill(int* damage, int* hp);
};