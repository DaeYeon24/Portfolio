#include "Inventory.h"
int Inventory::m_iLine = 11;

Inventory::Inventory(string _name, TYPE _type, int _att, int _price)
{
	m_strName = _name;
	m_pParent = NULL;
	m_eType = _type;
	m_iAtt = _att;
	m_iPrice = _price;
}

Inventory::Inventory(const Inventory* other)
{
	m_strName = other->m_strName;
	m_pParent = other->m_pParent;
	m_eType = other->m_eType;
	m_iAtt = other->m_iAtt;
	m_iPrice = other->m_iPrice;
}

int Inventory::GetLevel()
{
	int level = 0;
	Inventory* inventory = GetParent();
	while (inventory != NULL)
	{
		level++;
		inventory = inventory->GetParent();
	}
	return level;
}

Bag::Bag(string _name) : Inventory(_name)
{}

Bag::~Bag()
{
	m_vecInventoryList.clear();
}

void Bag::View()
{
	cout << setiosflags(ios::right) << setw(GetSize());
	cout << setfill(' ') << GetName().c_str() << " - Bag" << endl;
	vector<Inventory*>::iterator begin = m_vecInventoryList.begin();
	vector<Inventory*>::iterator end = m_vecInventoryList.end();
	while (begin != end)
	{
		(*begin)->View();
		begin++;
	}
}

void Bag::InventoryView()
{
	Draw().gotoxy((WIDTH / 2) - 6, (HEIGHT / 10) + GetLine());
	cout << setiosflags(ios::right) << setw(GetSize());
	cout << setfill(' ') << GetName().c_str() << " - Bag" << endl;
	vector<Inventory*>::iterator begin = m_vecInventoryList.begin();
	vector<Inventory*>::iterator end = m_vecInventoryList.end();
	while (begin != end)
	{
		(*begin)->InventoryView();
		begin++;
	}
}

void Bag::AddInventory(Inventory* _inventory)
{
	_inventory->SetParent(this);
	m_vecInventoryList.push_back(_inventory);
}

void Bag::RemoveInventory(Inventory* _inventory)
{
	vector<Inventory*>::iterator remove = find(m_vecInventoryList.begin(), m_vecInventoryList.end(), _inventory);
	if (remove != m_vecInventoryList.end())
	{
		m_vecInventoryList.erase(remove);
	}
}

void Bag::RemoveAll()
{
	for (auto iter = m_vecInventoryList.begin(); iter != m_vecInventoryList.end(); iter++)
		delete* iter;
}

void Bag::Save(string _save)
{
	ofstream save;
	save.open(_save, ios::app);
	for (auto iter = m_vecInventoryList.begin(); iter != m_vecInventoryList.end(); iter++)
	{
		save << endl << (*iter)->GetType() << " " << (*iter)->GetName() << " " << (*iter)->GetAtt() << " " << (*iter)->GetPrice();
	}
	save.close();
}

Item::Item(string _name, TYPE _type, int _att, int _price) : Inventory(_name, _type, _att, _price)
{}

Item::Item(const Item* other) : Inventory(other)
{}

void Item::View()
{
	cout << setiosflags(ios::right) << setw(GetSize());
	cout << setfill(' ') << GetName().c_str() << " - Item" << endl;
}

void Item::InventoryView()
{
	Draw().gotoxy((WIDTH / 2) - 6, (HEIGHT / 10) + GetLine());
	cout << setiosflags(ios::right) << setw(GetSize());
	cout << setfill(' ') << GetName().c_str() << " - Item" << endl;
}

void Item::Item_Info(int line, bool show)
{
	string str;
	str = GetName() + " 공격력 = " + to_string(GetAtt());
	Draw().Text(str, line);
	if (show == true)
	{
		str = "구매 가격 = " + to_string(GetPrice());
		Draw().Text(str, line + 1);
	}
}

Material::Material(string _name) : Item(_name)
{}

Bow::Bow(string _name, TYPE _type, int _att, int _price) : Item(_name, _type, _att, _price)
{}

Bow::Bow(const Item* other) : Item(other)
{}

void Bow::Skill(int* damage, int* hp)
{
	*damage += GetAtt();
	YELLOW
		Draw().Text("저격! 무기 추가 피해", 20);
	cout << " " << *damage;
	ORIGINAL
}

Spear::Spear(string _name, TYPE _type, int _att, int _price) : Item(_name, _type, _att, _price)
{}

Spear::Spear(const Item* other) : Item(other)
{}

void Spear::Skill(int* damage, int* hp)
{
	PUPPLE
		if (*damage % 3 == 0)
		{
			*damage += 30000;
			Draw().Text("즉사시도! 성공!!!", 20);
			getch();
		}
		else
		{
			Draw().Text("즉사시도! 실패", 20);
			cout << " " << *damage;
		}
	ORIGINAL
}

Sword::Sword(string _name, TYPE _type, int _att, int _price) : Item(_name, _type, _att, _price)
{}

Sword::Sword(const Item* other) : Item(other)
{}

void Sword::Skill(int* damage, int* hp)
{
	*damage *= 2;
	RED
		Draw().Text("검기! 데미지 두배 피해", 20);
	cout << " " << *damage;
	ORIGINAL
}

Wand::Wand(string _name, TYPE _type, int _att, int _price) : Item(_name, _type, _att, _price)
{}

Wand::Wand(const Item* other) : Item(other)
{}

void Wand::Skill(int* damage, int* hp)
{
	*hp += *damage;
	GREEN
		Draw().Text("회복! 체력 회복", 20);
	cout << " " << *damage;
	ORIGINAL
		* damage = 0;
}