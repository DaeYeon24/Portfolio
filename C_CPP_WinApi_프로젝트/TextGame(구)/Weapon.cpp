#include "Weapon.h"

Weapon::Weapon()
{}

void Weapon::WeaponSetting(int type, string name, int att, int price)
{
	m_iWeaponType = type;
	m_strWeaponName = name;
	m_iWeaponAtt = att;
	m_iWeaponPrice = price;
}

void Weapon::Weapon_Info(int line, bool show)
{
	string str;
	str = m_strWeaponName + " ���ݷ� = " + to_string(m_iWeaponAtt);
	m_DM.Text(str, line);
	if (show == true)
	{
		str = "���� ���� = " + to_string(m_iWeaponPrice);
		m_DM.Text(str, line + 1);
	}
}

Weapon::~Weapon()
{}

Bow::Bow()
{}

void Bow::Skill(int* damage, int* hp)
{
	*damage += m_iWeaponAtt;
	YELLOW
		m_DM.Text("����! ���� �߰� ����", 20);
	cout << " " << *damage;
	ORIGINAL
}

Bow::~Bow()
{}

Sword::Sword()
{}

void Sword::Skill(int* damage, int* hp)
{
	*damage *= 2;
	RED
		m_DM.Text("�˱�! ������ �ι� ����", 20);
	cout << " " << *damage;
	ORIGINAL
}

Sword::~Sword()
{}

Spear::Spear()
{}

void Spear::Skill(int* damage, int* hp)
{
	PUPPLE
		if (*damage % 3 == 0)
		{
			*damage += 30000;
			m_DM.Text("���õ�! ����!!!", 20);
			_getch();
		}
		else
		{
			m_DM.Text("���õ�! ����", 20);
			cout << " " << *damage;
		}
	ORIGINAL
}

Spear::~Spear()
{}

Wand::Wand()
{}

void Wand::Skill(int* damage, int* hp)
{
	*hp += *damage;
	GREEN
		m_DM.Text("ȸ��! ü�� ȸ��", 20);
	cout << " " << *damage;
	ORIGINAL
		* damage = 0;
}

Wand::~Wand()
{}

