#pragma once
#include "Draw.h"

class Inventory
{
	Inventory* m_pParent;
	string m_strName;
	TYPE m_eType;
	int m_iAtt;
	int m_iPrice;
	static int m_iLine;
public:
	Inventory(string _name, TYPE _type = NON, int _att = NULL, int _price = NULL);
	Inventory(const Inventory* other);
	virtual void View() = 0;
	virtual void AddInventory(Inventory* _inventory) = 0;
	virtual void RemoveInventory(Inventory* _inventory) = 0;
	virtual void InventoryView()  = 0;
	int GetLevel();
	inline void SetParent(Inventory* _parent) { m_pParent = _parent; }
	inline void SetLine() { m_iLine = 11; }
	inline Inventory* GetParent() { return m_pParent; }
	inline string GetName() { return m_strName; }
	inline int GetLine() { return m_iLine++; }
	inline TYPE GetType() { return m_eType; }
	inline int GetAtt() { return m_iAtt; }
	inline int GetPrice() { return m_iPrice; }
	inline int GetSize() { return m_strName.size() + GetLevel() * 2; }
};

class Bag : public Inventory
{
	vector<Inventory*> m_vecInventoryList;
public:
	Bag(string _name);
	~Bag();
	void View() override;
	void AddInventory(Inventory* _inventory) override;
	void RemoveInventory(Inventory* _inventory) override;
	void RemoveAll();
	void Save(string _save);
	void InventoryView() override;
};

class Item : public Inventory
{
public:
	Item(string _name, TYPE _type = NON, int _att = NULL, int _price = NULL);
	Item(const Item* other);
	void View() override;
	void InventoryView() override;
	void AddInventory(Inventory* _inventory) {};
	void RemoveInventory(Inventory* _inventory) {};
	void Item_Info(int line, bool show = false); // 대기
	virtual void Skill(int* damage, int* hp) = 0; //순수 가상
};

class Material : public Item
{
public:
	Material(string _name);
	void Skill(int* damage, int* hp) {};
};

class Bow : public Item
{
public:
	Bow(string _name, TYPE _type, int _att, int _price);
	Bow(const Item* other);
	void Skill(int* damage, int* hp) override;
};

class Spear : public Item
{
public:
	Spear(string _name, TYPE _type, int _att, int _price);
	Spear(const Item* other);
	void Skill(int* damage, int* hp) override;
};

class Sword : public Item
{
public:
	Sword(string _name, TYPE _type, int _att, int _price);
	Sword(const Item* other);
	void Skill(int* damage, int* hp) override;
};

class Wand : public Item
{
public:
	Wand(string _name, TYPE _type, int _att, int _price);	
	Wand(const Item* other);
	void Skill(int* damage, int* hp) override;
};