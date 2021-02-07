#pragma once
#include "Unit.h"
#include "Weapon.h"

class GameManager
{
private:
	Draw m_DM;
	Player* m_User;
	Monster* m_Monster_List;
	Weapon** m_Weapon_List;
	int m_iMonster_Count;
	int m_iWeapon_Count;
	int m_iSelect_Index;
public:
	ifstream load;
	ofstream save;
	GameManager();
	~GameManager();
	void Title();
	void Menu();
	void Fight();
	void MonsterLoad();
	void Monster_Info();
	void WeaponLoad();
	void WeaponShop();
	void Save();
	void Load(int slot_number = NULL);
	int FileList();
	bool DG_List();
	bool WinCheck();
};

