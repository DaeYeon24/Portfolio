#pragma once
#include "ClassFactory.h"

class Unit
{
protected:
	Draw m_DM;
	string m_strName;
	int m_iLevel;
	int m_iAtt;
	int m_iDef;
	int m_iFullHp;
	int m_iHp;
	int m_iExp;
	int m_iMaxCost;
	int m_iCurCost;
	int m_iGold;
	int m_iCostClock;
public:
	ifstream load;
	ofstream save;
	Unit();
	inline string GetName() { return m_strName; }
	inline int GetDef() { return m_iDef; }
	inline int GetHp() { return m_iHp; }
	inline int GetGold() { return m_iGold; }
	inline int GetExp() { return m_iExp; }
	inline void Damage(int damage) { m_iHp -= damage; }
	inline void ResetHp() { m_iHp = m_iFullHp; }
	inline void ResetCost() { m_iCurCost = 0; }
	inline void AddGold(int gold) { m_iGold += gold; }
	inline void AddHp(int recovery) { m_iHp += recovery; }
	inline void AddExp(int exp) { m_iExp += exp; }
};

class Player : public Unit
{
private:
	Item* m_Weapon; // 장착 무기
	int m_iNeed_Exp; // 필요 경험치
	int m_iSumAtt; // 캐릭 공격력 + 무기 공격력
	Bag* m_Main_Bag;
	Bag* m_Weapon_Bag;
	Bag* m_Material_Bag;
	JobClass* m_Class;
public:
	Player();
	~Player();
	void Load(int slot_number = NULL);
	void Save(int slot_number);
	void SelectJobClass();
	void ShowUnit(int line, bool info = false);
	void Costing();
	bool Attack(Unit* Defender);
	void BuyWeapon(Item* weapon);
	void LevelUp();
	void AddMaterial(Material* material);
	Item* GetWeapon();
};

class Monster : public Unit
{
private:
	Material* m_Material;
public:
	void ShowUnit(int line = NULL, bool info = false);
	bool Costing(Unit* Defender);
	void Attack(Unit* Defender);
	void MonsterSetting(string name, int level, int att, int def, int hp, int exp, int cost, int gold, string material);
	void GetMaterial(Player* user);
	Monster();
	~Monster();
};
