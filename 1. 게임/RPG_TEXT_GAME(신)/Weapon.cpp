//#include "Weapon.h"
//
//Weapon::Weapon(int type, string name, int att, int price)
//{
//	m_iWeaponType = type;
//	m_strWeaponName = name;
//	m_iWeaponAtt = att;
//	m_iWeaponPrice = price;
//}
//
//void Weapon::Weapon_Info(int line, bool show)
//{
//	string str;
//	str = m_strWeaponName + " ���ݷ� = " + to_string(m_iWeaponAtt);
//	m_DM.Text(str, line);
//	if (show == true)
//	{
//		str = "���� ���� = " + to_string(m_iWeaponPrice);
//		m_DM.Text(str, line + 1);
//	}
//}
//
//Weapon::~Weapon()
//{}
//
//
//void Bow::Skill(int* damage, int* hp)
//{
//	*damage += GetAtt();
//	YELLOW
//		m_DM.Text("����! ���� �߰� ����", 20);
//	cout << " " << *damage;
//	ORIGINAL
//}
//
//
//
//void Spear::Skill(int* damage, int* hp)
//{
//	PUPPLE
//		if (*damage % 3 == 0)
//		{
//			*damage += 30000;
//			m_DM.Text("���õ�! ����!!!", 20);
//			getch();
//		}
//		else
//		{
//			m_DM.Text("���õ�! ����", 20);
//			cout << " " << *damage;
//		}
//	ORIGINAL
//}
//
//
//
//void Sword::Skill(int* damage, int* hp)
//{
//	*damage *= 2;
//	RED
//		m_DM.Text("�˱�! ������ �ι� ����", 20);
//	cout << " " << *damage;
//	ORIGINAL
//}
//
//
//void Wand::Skill(int* damage, int* hp)
//{
//	*hp += *damage;
//	GREEN
//		m_DM.Text("ȸ��! ü�� ȸ��", 20);
//	cout << " " << *damage;
//	ORIGINAL
//		* damage = 0;
//}
//
