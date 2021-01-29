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
	str = m_strWeaponName + " 공격력 = " + to_string(m_iWeaponAtt);
	m_DM.Text(str, line);
	if (show == true)
	{
		str = "구매 가격 = " + to_string(m_iWeaponPrice);
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
		m_DM.Text("저격! 무기 추가 피해", 20);
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
		m_DM.Text("검기! 데미지 두배 피해", 20);
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
			m_DM.Text("즉사시도! 성공!!!", 20);
			_getch();
		}
		else
		{
			m_DM.Text("즉사시도! 실패", 20);
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
		m_DM.Text("회복! 체력 회복", 20);
	cout << " " << *damage;
	ORIGINAL
		* damage = 0;
}

Wand::~Wand()
{}

