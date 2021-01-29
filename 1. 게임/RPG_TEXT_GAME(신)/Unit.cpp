#include "Unit.h"

Unit::Unit()
{}

Player::Player()
{
	m_Main_Bag = new Bag("��ü");
	m_Weapon_Bag = new Bag("����");
	m_Material_Bag = new Bag("���");
	m_Main_Bag->AddInventory(m_Weapon_Bag);
	m_Main_Bag->AddInventory(m_Material_Bag);
	m_Weapon = NULL;
}

void Player::ShowUnit(int line, bool info)
{
	string str;
	str = "====== " + m_strName + " (" + to_string(m_iLevel) + "Lv) ======";
	m_DM.Text(str, line);
	str = "���ݷ� = " + to_string(m_iAtt) + "      ���� = " + to_string(m_iDef);
	m_DM.Text(str, line + 2);
	str = "����� = " + to_string(m_iHp) + "/" + to_string(m_iFullHp) + "   ����ġ = " + to_string(m_iExp) + "/" + to_string(m_iNeed_Exp);
	m_DM.Text(str, line + 3);
	str = "��� = " + to_string(m_iGold);
	m_DM.Text(str, line + 4);
	str = "�� ���ݷ� = " + to_string(m_iSumAtt);
	RED
		m_DM.Text(str, line + 5);
	if (m_Weapon != NULL)
	{
		str = "���� = " + m_Weapon->GetName() + " ���ݷ� = " + to_string(m_Weapon->GetAtt());
		SKY_BLUE
			m_DM.Text(str, line + 6);
	}
	ORIGINAL
	if (info)
	{
		m_Class->JobClass_Info();
		m_Main_Bag->InventoryView();
		m_Main_Bag->SetLine();
	}
}

void Player::Load(int slot_number)
{
	string slot;
	string weapon_name;
	int weapon_att, weapon_type, weapon_price;
	if (slot_number == NULL)
	{
		m_DM.Text("Player �̸� �Է� : ", FIRSTLINE);
		cin >> m_strName;
		load.open("DefaultUser.txt");
	}
	else
	{
		slot = "SaveUser" + to_string(slot_number) + ".txt";
		load.open(slot);
		load >> m_strName;
	}
	load >> m_iLevel >> m_iAtt >> m_iDef >> m_iFullHp >> m_iHp >> m_iNeed_Exp >> m_iExp >> m_iGold;
	m_iSumAtt = m_iAtt;
	m_iMaxCost = 10;
	m_iCurCost = 0;
	if (!load.eof())
	{
		load >> weapon_type >> weapon_name >> weapon_att >> weapon_price;
		switch (weapon_type)
		{
		case BOW:
			m_Weapon = new Bow(weapon_name, (TYPE)weapon_type, weapon_att, weapon_price);
			break;
		case SWORD:
			m_Weapon = new Sword(weapon_name, (TYPE)weapon_type, weapon_att, weapon_price);
			break;
		case WAND:
			m_Weapon = new Wand(weapon_name, (TYPE)weapon_type, weapon_att, weapon_price);
			break;
		case SPEAR:
			m_Weapon = new Spear(weapon_name, (TYPE)weapon_type, weapon_att, weapon_price);
			break;
		}
		m_iSumAtt += m_Weapon->GetAtt();
	}
	else
		SelectJobClass();
	load.close();
}

void Player::SelectJobClass()
{
	ClassFactory* Factory = new Class;
	int select;
	m_DM.BorderLine();
	m_DM.Text("�� �� �� ������ ���ÿ� �� �� �� ", FIRSTLINE);
	m_DM.MenuText("1.  �� ��", 3);
	m_DM.MenuText("2.  �� ��", 5);
	m_DM.MenuText("3.  �� ��", 7);
	m_DM.MenuText("4.  â ��", 9);
	select = m_DM.MenuSelectCursor(4, 2, 15, (HEIGHT / 3) + 3);
	m_DM.BorderLine();
	switch (select)
	{
	case 1:
		m_Class = Factory->CreateJobClass(KNIGHT);
		break;
	case 2:
		m_Class = Factory->CreateJobClass(ARCHER);
		break;
	case 3:
		m_Class = Factory->CreateJobClass(WIZARD);
		break;
	case 4:
		m_Class = Factory->CreateJobClass(LANCER);
		break;
	}
	delete Factory;
}

bool Player::Attack(Unit* Defender)
{
	int Damage;
	char key;
	if (kbhit())
	{
		key = getch();
		if (key == SKILL || key == ENTER)
		{
			if (Defender->GetDef() >= m_iSumAtt)
				Damage = 1;
			else
				Damage = (rand() % (m_iSumAtt - Defender->GetDef())) + 1;
			switch (key)
			{
			case SKILL:
				if (m_iCurCost >= 7)
				{
					if (m_Weapon == NULL)
					{
						m_DM.EraseText(20);
						m_DM.Text("���Ⱑ �����ϴ�!", 20);
					}
					else if(m_Class->EquipCheck(m_Weapon))
					{
						m_Weapon->Skill(&Damage, &m_iHp);
						m_iCurCost -= 7;
					}
					else
					{
						m_DM.EraseText(20);
						m_DM.Text("������ ����� ����� �� ���� �����Դϴ�!", 20);
					}
				}
				else
					return false;
				break;
			case ENTER:
				if (m_iCurCost >= 3)
				{
					m_iCurCost -= 3;
					m_DM.EraseText(20);
					m_DM.Text("�⺻����! ����", 20);
					cout << " " << Damage;
				}
				else
					return false;
				break;
			}
			Defender->Damage(Damage);
			m_DM.EraseText(26);
			m_DM.DrawCost(26, m_iCurCost);
			return true;
		}
		else
			return false;
	}
	return false;
}

void Player::Costing()
{
	if (clock() - m_iCostClock >= COOLTIME)
	{
		if (m_iCurCost < m_iMaxCost)
			m_iCurCost++;
		m_DM.DrawCost(26, m_iCurCost);
		m_iCostClock = clock();
	}
}

void Player::BuyWeapon(Item* weapon)
{
	if (m_iGold >= weapon->GetPrice())
	{
		m_iGold -= weapon->GetPrice();
		if (m_Weapon != NULL)
		{
			m_Weapon_Bag->AddInventory(weapon);
			return;
		}
		m_Weapon = weapon;
		m_iSumAtt = m_iAtt + m_Weapon->GetAtt();
	}
	else
	{
		m_DM.BorderLine();
		m_DM.Text("������ ��尡 �����մϴ�.");
		getch();
		return;
	}
}

void Player::Save(int slot_number)
{
	string slot;
	slot = "SaveUser" + to_string(slot_number) + ".txt";
	save.open(slot);
	if (save.is_open())
	{
		save << m_strName << " " << m_iLevel << " " << m_iAtt << " " << m_iDef << " " << m_iFullHp << " " << m_iHp << " " << m_iNeed_Exp << " " << m_iExp << " " << m_iGold;
		save << endl << m_Class->GetJobClass();
		if (m_Weapon != NULL)
			save << endl << m_Weapon->GetType() << " " << m_Weapon->GetName() << " " << m_Weapon->GetAtt() << " " << m_Weapon->GetPrice();
	}
	save.close();
	if (m_Weapon_Bag != NULL)
		m_Weapon_Bag->Save(slot);
	if (m_Material_Bag != NULL)
		m_Material_Bag->Save(slot);
}

void Player::LevelUp()
{
	if (m_iExp >= m_iNeed_Exp)
	{
		string str;
		int surplus_exp;
		int Getatt = (rand() % 3) + 1;
		int Getdef = (rand() % 3) + 1;
		int Gethp = (rand() % 10) + 1;
		str = m_strName + "�� ������ �ö����ϴ�!!";
		m_DM.Text(str, 10);
		surplus_exp = m_iExp - m_iNeed_Exp;
		m_iLevel++;
		m_iAtt += Getatt;
		m_iSumAtt += Getatt;
		m_iDef += Getdef;
		m_iFullHp += Gethp;
		ResetHp();
		str = "���ݷ� " + to_string(Getatt) + "���� " + to_string(Getdef) + "ü�� " + to_string(Gethp) + " ����";
		m_DM.Text(str, 11);
		m_iExp = surplus_exp;
		m_iNeed_Exp += (m_iNeed_Exp / 3);
	}
}

void Player::AddMaterial(Material* material)
{
	m_Material_Bag->AddInventory(material);
}

Item* Player::GetWeapon()
{
	return m_Weapon;
}

Player::~Player()
{
	if (m_Class != NULL)
	{
		delete m_Class;
		m_Class = NULL;
	}
	if (m_Weapon != NULL)
	{
		delete m_Weapon;
		m_Weapon = NULL;
	}
	if (m_Weapon_Bag != NULL)
	{
		m_Weapon_Bag->RemoveAll();
		delete m_Weapon_Bag;
		m_Weapon_Bag = NULL;
	}
	if (m_Material_Bag != NULL)
	{
		delete m_Material_Bag;
		m_Material_Bag = NULL;
	}
	if (m_Main_Bag != NULL)
	{
		delete m_Main_Bag;
		m_Main_Bag = NULL;
	}
}

Monster::Monster()
{}

void Monster::MonsterSetting(string name, int level, int att, int def, int hp, int exp, int cost, int gold, string material)
{
	m_strName = name;
	m_iLevel = level;
	m_iAtt = att;
	m_iDef = def;
	m_iFullHp = hp;
	m_iHp = m_iFullHp;
	m_iExp = exp;
	m_iMaxCost = cost;
	m_iCurCost = 0;
	m_iGold = gold;
	m_Material = new Material(material);
}

void Monster::ShowUnit(int line, bool info)
{
	string str;
	str = "====== " + m_strName + " (" + to_string(m_iLevel) + "Lv) ======";
	m_DM.Text(str, line);
	str = "���ݷ� = " + to_string(m_iAtt) + "     ���� = " + to_string(m_iDef);
	m_DM.Text(str, line + 1);
	str = "����� = " + to_string(m_iHp) + "/" + to_string(m_iFullHp) + "   ȹ�� ����ġ = " + to_string(m_iExp);
	m_DM.Text(str, line + 2);
	str = "ȹ�� ��� = " + to_string(m_iGold) + "     ���ݼӵ�  = " + to_string(m_iMaxCost);
	m_DM.Text(str, line + 3);
	if (info)
	{
		str = "ȹ�� ����ǰ = " + m_Material->GetName();
		PLUM
			m_DM.Text(str, line + 4);
		ORIGINAL
	}
}

bool Monster::Costing(Unit* Defender)
{
	if (clock() - m_iCostClock >= COOLTIME)
	{
		if (m_iCurCost < m_iMaxCost)
			m_iCurCost++;
		else
		{
			m_iCurCost = 0;
			m_DM.EraseText(4);
			Attack(Defender);
			m_iCostClock = clock();
			return true;
		}
		m_DM.DrawCost(4, m_iCurCost);
		m_iCostClock = clock();
		return false;
	}
	return false;
}

void Monster::Attack(Unit* Defender)
{
	int Damage;
	if (Defender->GetDef() >= m_iAtt)
		Damage = 1;
	else
		Damage = (rand() % (m_iAtt - Defender->GetDef())) + 1;
	Defender->Damage(Damage);
	m_DM.EraseText(10); // ���Ͷ��� 10
	m_DM.Text("����! ����", 10);
	cout << " " << Damage;
}

void Monster::GetMaterial(Player* user)
{
	int Probability = rand() % 3;
	if (Probability == 0) // 3���� 1 Ȯ��
	{
		user->AddMaterial(m_Material);
		m_DM.Text("����ǰ�� ������ϴ�!", 9);
	}
}

Monster::~Monster()
{
	if (m_Material != NULL)
	{
		delete m_Material;
		m_Material = NULL;
	}
}