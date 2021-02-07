//#pragma once
//#include "Header.h"
//#include "Draw.h"
//
//class Weapon
//{
//private:
//	int m_iWeaponType;
//	string m_strWeaponName;
//	int m_iWeaponAtt;
//	int m_iWeaponPrice;
//protected:
//	Draw m_DM;
//public:
//	Weapon(int type, string name, int att, int price);
//	~Weapon();
//	inline int GetType()
//	{
//		return m_iWeaponType;
//	}
//	inline string GetName()
//	{
//		return m_strWeaponName;
//	}
//	inline int GetAtt()
//	{
//		return m_iWeaponAtt;
//	}
//	inline int GetPrice()
//	{
//		return m_iWeaponPrice;
//	}
//	void Weapon_Info(int line, bool show = false);
//	virtual void Skill(int* damage, int* hp) = 0; //순수 가상
//};
//
//class Bow : public Item
//{
//public:
//	Bow(int type, string name, int att, int price);
//	~Bow();
//	void Skill(int* damage, int* hp);
//};
//
//class Spear : public Item
//{
//public:
//	Spear(int type, string name, int att, int price);
//	~Spear();
//	void Skill(int* damage, int* hp);
//};
//
//class Sword : public Item
//{
//public:
//	Sword(int type, string name, int att, int price);
//	~Sword();
//	void Skill(int* damage, int* hp);
//};
//
//class Wand : public Item
//{
//public:
//	Wand(int type, string name, int att, int price);
//	~Wand();
//	void Skill(int* damage, int* hp);
//};