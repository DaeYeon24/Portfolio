#include "GameManager.h"

GameManager::GameManager()
{
	m_iSelect_Index = NULL;
	m_iMonster_Count = 0;
	m_iWeapon_Count = 0;
	m_User = NULL;
	m_Monster_List = NULL;
	m_Weapon_List = NULL;
}

void GameManager::Title()
{
	int select, slot_number;
	string slot;
	while (1)
	{
		m_DM.BorderLine();
		m_DM.Text("★ ★ ★ RPG Game ★ ★ ★ ", FIRSTLINE);
		m_DM.MenuText("1.  New Game", 3);
		m_DM.MenuText("2.  Load Game", 5);
		m_DM.MenuText("3.  Exit", 7);
		select = m_DM.MenuSelectCursor(3, 2, 15, (HEIGHT / 3) + 3);
		m_DM.BorderLine();
		switch (select)
		{
		case 1:
			Load();
			Menu();
			break;
		case 2:
			while (1)
			{
				slot_number = FileList();
				if (slot_number != CANCEL)
				{
					slot = "SaveUser" + to_string(slot_number) + ".txt";
					load.open(slot);
					if (load.is_open())
					{
						load.close();
						Load(slot_number);
						Menu();
						break;
					}
					else
					{
						load.close();
						m_DM.BorderLine();
						m_DM.Text("저장된 기록이 없습니다.", FIRSTLINE);
						_getch();
					}
				}
				else
					break;
			}
			break;
		case 3:
			return;
		}
	}
}

void GameManager::MonsterLoad()
{
	int tmp_Level, tmp_Att, tmp_Def, tmp_FullHp, tmp_Exp, tmp_MaxCost, tmp_Gold;
	string tmp, slot, tmp_Name;
	load.open("Monster.txt");
	while (!load.eof())
	{
		getline(load, tmp);
		m_iMonster_Count++;
	}
	load.close();
	if (m_Monster_List != NULL)
		delete[] m_Monster_List;
	m_Monster_List = new Monster[m_iMonster_Count];
	load.open("Monster.txt");
	for (int i = 0; i < m_iMonster_Count; i++)
	{
		load >> tmp_Name >> tmp_Level >> tmp_Att >> tmp_Def >> tmp_FullHp >> tmp_Exp >> tmp_MaxCost >> tmp_Gold;
		m_Monster_List[i].MonsterSetting(tmp_Name, tmp_Level, tmp_Att, tmp_Def, tmp_FullHp, tmp_Exp, tmp_MaxCost, tmp_Gold);
	}
	load.close();
}

int GameManager::FileList()
{
	int select, line = 5;
	string str, slot;
	bool user = false;
	while (1)
	{
		m_DM.Text("======저장목록======", 1);
		GREEN
			for (int i = 0; i < 10; i++)
			{
				slot = "SaveUser" + to_string(i + 1) + ".txt";
				load.open(slot);
				if (load.is_open() == true)
					user = true;
				load.close();
				if (user == true)
				{
					str = to_string(i + 1) + "번 슬롯 [ 파일여부 : o ]";
					user = false;
				}
				else
					str = to_string(i + 1) + "번 슬롯 [ 파일여부 : x ]";
				m_DM.Text(str, line);
				line += 2;
			}
		ORIGINAL
			m_DM.Text("돌아가기", line);
		select = m_DM.MenuSelectCursor(11, 2, 12, 9);
		return select;
	}
}

void GameManager::Fight()
{
	srand(time(NULL));
	int flag = DONE;
	m_DM.BorderLine();
	m_DM.VersusLine();
	while (1)
	{
		m_User->Costing();
		if (m_Monster_List[m_iSelect_Index].Costing(m_User) == true)
			flag = DONE;
		if (m_User->Attack(&m_Monster_List[m_iSelect_Index]) == true)
			flag = DONE;
		if (flag == DONE)
		{
			if (WinCheck() == true)
			{
				_getch();
				return;
			}
			m_User->ShowUnit(27);
			m_Monster_List[m_iSelect_Index].ShowUnit();
			flag = PAUSE;
		}
	}
}

bool GameManager::WinCheck()
{
	string str;
	if (m_User->GetHp() <= 0 || m_Monster_List[m_iSelect_Index].GetHp() <= 0)
	{
		m_DM.BorderLine();
		if (m_Monster_List[m_iSelect_Index].GetHp() <= 0)
		{
			m_User->ResetHp();
			m_Monster_List[m_iSelect_Index].ResetHp();
			str = m_User->GetName() + "이(가) 승리 했습니다!!";
			m_DM.Text(str, 8);
			m_User->AddExp(m_Monster_List[m_iSelect_Index].GetExp());
			m_User->AddGold(m_Monster_List[m_iSelect_Index].GetGold());
			m_User->LevelUp();
		}
		else if (m_User->GetHp() <= 0)
		{
			m_User->ResetHp();
			m_Monster_List[m_iSelect_Index].ResetHp();
			str = m_User->GetName() + "이(가) 패배 했습니다.";
			m_DM.Text(str, 8);
		}
		m_Monster_List[m_iSelect_Index].ResetCost();
		m_User->ResetCost();
		return true;
	}
	else
		return false;
}

void GameManager::Load(int slot_number)
{
	if (m_User != NULL)
		delete m_User;
	m_User = new Player();
	m_User->Load(slot_number);
	MonsterLoad();
	WeaponLoad();
}

void GameManager::WeaponLoad()
{
	string tmp, tmp_name;
	int tmp_type, tmp_att, tmp_price;
	load.open("WeaponList.txt");
	while (!load.eof())
	{
		getline(load, tmp);
		m_iWeapon_Count++;
	}
	load.close();
	if (m_Weapon_List != NULL)
		delete[] m_Weapon_List;
	m_Weapon_List = new Weapon * [m_iWeapon_Count];
	load.open("WeaponList.txt");
	for (int i = 0; i < m_iWeapon_Count; i++)
	{
		load >> tmp_type >> tmp_name >> tmp_att >> tmp_price;
		switch (tmp_type)
		{
		case BOW:
			m_Weapon_List[i] = new Bow;
			break;
		case SWORD:
			m_Weapon_List[i] = new Sword;
			break;
		case WAND:
			m_Weapon_List[i] = new Wand;
			break;
		case SPEAR:
			m_Weapon_List[i] = new Spear;
			break;
		}
		m_Weapon_List[i]->WeaponSetting(tmp_type, tmp_name, tmp_att, tmp_price);
	}
	load.close();
}

void GameManager::Save()
{
	int slot_number;
	slot_number = FileList();
	m_User->Save(slot_number);
}

bool GameManager::DG_List()
{
	int i, tmp, line = FIRSTLINE;
	string str;
	m_DM.BorderLine();
	m_DM.Text("====== 던 전 목 록 ======", 5);
	for (i = 0; i < m_iMonster_Count; i++)
	{
		str = to_string(i + 1) + "층 던전 : [" + m_Monster_List[i].GetName() + "]";
		m_DM.Text(str, line);
		line += 3;
	}
	m_DM.Text("돌아가기", line);
	tmp = m_DM.MenuSelectCursor(i + 1, 3, 12, 13);
	if (tmp == i + 1)
		return false;
	else
	{
		m_iSelect_Index = tmp - 1;
		return true;
	}
}

void GameManager::WeaponShop()
{
	Weapon** tmp = NULL;
	int page = 0, count = 0, line = 1, list = 0, menulen = 0;
	int Weapon_type, menuselect;
	Weapon_type = m_DM.ShopMenu();
	if (Weapon_type == 5)
		return;
	for (int i = 0; i < m_iWeapon_Count; i++)
	{
		if (m_Weapon_List[i]->GetType() == Weapon_type)
			count++;
	}
	tmp = new Weapon * [count];
	for (int i = 0; i < m_iWeapon_Count; i++)
	{
		if (m_Weapon_List[i]->GetType() == Weapon_type)
		{
			switch (m_Weapon_List[i]->GetType())
			{
			case BOW:
				tmp[list] = new Bow;
				break;
			case SWORD:
				tmp[list] = new Sword;
				break;
			case WAND:
				tmp[list] = new Wand;
				break;
			case SPEAR:
				tmp[list] = new Spear;
				break;
			}
			tmp[list++]->WeaponSetting(m_Weapon_List[i]->GetType(), m_Weapon_List[i]->GetName(), m_Weapon_List[i]->GetAtt(), m_Weapon_List[i]->GetPrice());
		}
	}
	list = 0;
	while (1)
	{
		m_DM.BorderLine();
		m_DM.Text("====== 상 점 목 록 ======", line);
		GOLD
			m_DM.Text("        골드 = ", line + 1);
		cout << m_User->GetGold();
		ORIGINAL
			line += 4;
		while (list < count)
		{
			tmp[list++]->Weapon_Info(line, true);
			menulen++;
			line += 4;
			if (list % 4 == 0)
				break;
		}
		m_DM.Text("이전 페이지", line);
		m_DM.Text("다음 페이지", line + 4);
		m_DM.Text("상점 나가기", line + 8);
		menulen += 3;
		menuselect = m_DM.MenuSelectCursor(menulen, 4, 12, 9);
		if (menuselect == menulen)
		{
			if (tmp != NULL)
			{
				for (int i = 0; i < count; i++)
				{
					if (tmp[i] != NULL)
					{
						delete tmp[i];
						tmp[i] = NULL;
					}
				}
				delete[] tmp;
				tmp = NULL;
			}
			count = 0;
			return;
		}
		else if (menuselect == menulen - 1)
		{
			if (list < count)
				page++;
			else
				list = page * 4;
			line = 1;
			menulen = 0;
			continue;
		}
		else if (menuselect == menulen - 2)
		{
			if (page != 0)
				page--;
			list = page * 4;
			line = 1;
			menulen = 0;
			continue;
		}
		else
		{
			m_User->BuyWeapon(tmp[(menuselect + (page * 4)) - 1]);
			list = page * 4;
			line = 1;
			menulen = 0;
			continue;
		}
	}
}

void GameManager::Menu()
{
	int select;
	while (1)
	{
		m_DM.BorderLine();
		m_DM.Text("★ ★ ★ M E N U ★ ★ ★ ", FIRSTLINE);
		m_DM.MenuText("1.  Dongeon", 3);
		m_DM.MenuText("2.  Player Info", 5);
		m_DM.MenuText("3.  Monster Info", 7);
		m_DM.MenuText("4.  Weapon Shop", 9);
		m_DM.MenuText("5.  Save Game", 11);
		m_DM.MenuText("6.  Exit", 13);
		select = m_DM.MenuSelectCursor(6, 2, 15, (HEIGHT / 3) + 3);
		m_DM.BorderLine();
		switch (select)
		{
		case 1:
			if (DG_List() == true)
				Fight();
			break;
		case 2:
			m_User->ShowUnit(9);
			_getch();
			break;
		case 3:
			Monster_Info();
			break;
		case 4:
			WeaponShop();
			break;
		case 5:
			Save();
			break;
		case 6:
			if (m_User != NULL)
			{
				delete m_User;
				m_User = NULL;
			}
			if (m_Monster_List != NULL)
			{
				delete[] m_Monster_List;
				m_Monster_List = NULL;
			}
			if (m_Weapon_List != NULL)
			{
				for (int i = 0; i < m_iWeapon_Count; i++)
				{
					if (m_Weapon_List[i] != NULL)
					{
						delete m_Weapon_List[i];
						m_Weapon_List[i] = NULL;
					}
				}
				delete[] m_Weapon_List;
				m_Weapon_List = NULL;
			}
			m_iMonster_Count = 0;
			m_iWeapon_Count = 0;
			return;
		}
	}
}

void GameManager::Monster_Info()
{
	int line = 1;
	for (int i = 0; i < m_iMonster_Count; i++)
	{
		m_Monster_List[i].ShowUnit(line);
		line += 5;
	}
	_getch();
}

GameManager::~GameManager()
{
	if (m_User != NULL)
		delete m_User;
	if (m_Monster_List != NULL)
		delete[] m_Monster_List;
	if (m_Weapon_List != NULL)
	{
		for (int i = 0; i < m_iWeapon_Count; i++)
		{
			if (m_Weapon_List[i] != NULL)
				delete m_Weapon_List[i];
		}
		delete[] m_Weapon_List;
	}
}