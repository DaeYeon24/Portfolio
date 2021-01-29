#include "RankManager.h"

RankManager::RankManager()
{
	m_Rank_User_List = NULL;
	m_Count = 0;
}

void RankManager::Save_User(string name, int score, int stage)
{
	ofstream save;
	save.open("Rank.txt", ios::app);
	save << name << " " << score << " " << stage << endl;
	save.close();
}

void RankManager::Load_User_List()
{
	ifstream load;
	string tmp;
	load.open("Rank.txt");
	if (load.is_open())
	{
		while (!load.eof())
		{
			getline(load, tmp);
			m_Count++;
		}
		m_Count--;
		m_Rank_User_List = new Rank_User[m_Count];
	}
	else
	{
		load.close();
		m_Interface.MidText("저장된 기록이 없습니다..", 20);
		getch();
		return;
	}
	load.close();
	int count = 0;
	load.open("Rank.txt");
	while (!load.eof())
	{
		if (count < m_Count)
		{
			load >> m_Rank_User_List[count].m_Name >> m_Rank_User_List[count].m_Total_Score >> m_Rank_User_List[count].m_End_Stage;
			count++;
		}
		else
			load >> tmp;
	}
	load.close();
	Rank_Info();
}

void RankManager::Rank_Info()
{
	int rank = 0, line = 3;
	string str;
	Rank_User temp;
	for (int i = 0; i < m_Count - 1; i++)
	{
		for (int j = i; j < m_Count; j++)
		{
			if (m_Rank_User_List[i].m_Total_Score < m_Rank_User_List[j].m_Total_Score)
			{
				temp = m_Rank_User_List[i];
				m_Rank_User_List[i] = m_Rank_User_List[j];
				m_Rank_User_List[j] = temp;
				rank++;
			}
			else if (m_Rank_User_List[i].m_Total_Score == m_Rank_User_List[j].m_Total_Score)
			{
				if (m_Rank_User_List[i].m_End_Stage < m_Rank_User_List[j].m_End_Stage)
				{
					temp = m_Rank_User_List[i];
					m_Rank_User_List[i] = m_Rank_User_List[j];
					m_Rank_User_List[j] = temp;
					rank++;
				}
			}
		}
	}
	m_Interface.BorderLine();
	m_Interface.MidText("☆ ★ ☆ 순 위 ☆ ★ ☆");
	RED
		m_Interface.RankingText("NAME", "SCORE", "STAGE", line++);
	ORIGINAL
		for (int i = 0; i < m_Count && i < TOPFIFTEEN; i++)
		{
			m_Interface.RankingText(m_Rank_User_List[i].m_Name, to_string(m_Rank_User_List[i].m_Total_Score), to_string(m_Rank_User_List[i].m_End_Stage), line);
			line += 2;
		}
	getch();
	m_Count = 0;
	delete[] m_Rank_User_List;
	m_Rank_User_List = NULL;
}

RankManager::~RankManager()
{}