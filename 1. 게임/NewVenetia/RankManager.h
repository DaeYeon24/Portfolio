#pragma once
#include "Interface.h"

struct Rank_User
{
	string m_Name;
	int m_End_Stage;
	int m_Total_Score;
	void Input_Data(string name, int score, int stage)
	{
		m_Name = name;
		m_Total_Score = score;
		m_End_Stage = stage;
	}
};

class RankManager
{
private:
	Rank_User* m_Rank_User_List;
	Interface m_Interface;
	int m_Count;
public:
	RankManager();
	~RankManager();
	void Save_User(string name, int score, int stage);
	void Load_User_List();
	void Rank_Info();
};

