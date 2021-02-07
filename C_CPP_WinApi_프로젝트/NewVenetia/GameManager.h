#pragma once
#include "WordManager.h"
#include "RankManager.h"
#include "Singleton.h"

struct User
{
	string m_Name;
	int m_Total_Score;
	int m_Score;
	int m_End_Stage;
	int m_Life;
	User(string name, int score, int life)
	{
		m_Name = name;
		m_Score = score;
		m_Life = life;
		m_Total_Score = 0;
		m_End_Stage = 1;
	}
};

class GameManager : public Singleton<GameManager>
{
private:
	User* m_User;
	Interface m_Interface;
	WordManager m_WordManager;
	RankManager m_RankManager;
public:
	GameManager();
	~GameManager();
	void Title();
	void Scroll();
	void InGame();
	void Stage_Start();
	void Level_Up();
	void GameOver();
};

