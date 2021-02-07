#include "GameManager.h"

GameManager::GameManager()
{
	m_User = NULL;
	m_WordManager.Load();
}

void GameManager::Title()
{
	int select;
	while (1)
	{
		if (m_User != NULL)
		{
			delete m_User;
			m_User = NULL;
		}
		m_User = new User("????", 0, 10);
		m_Interface.BorderLine();
		m_Interface.UnderLine(m_User->m_Name.c_str(), NAME); // 1번 3줄
		m_Interface.UnderLine(m_User->m_Score, SCORE);
		m_Interface.UnderLine(m_User->m_Life, LIFE); ///////////////////////////
		//m_Interface.UnderLine_Name(m_User->m_Name); // 2번 3줄
		//m_Interface.UnderLine_Score(m_User->m_Score);
		//m_Interface.UnderLine_Life(m_User->m_Life);///////////////////////
		m_Interface.MidText("☆ ★ ☆ 베네치아 ☆ ★ ☆", 3);
		m_Interface.AlignedText("1. Game Start", 10);
		m_Interface.AlignedText("2. Rank Info", 13);
		m_Interface.AlignedText("3. Game Exit", 16);
		select = m_Interface.MenuSelectCursor(3, 3, 27, 14);
		m_Interface.BorderLine();
		switch (select)
		{
		case 1:
			InGame();
			break;
		case 2:
			m_RankManager.Load_User_List();
			break;
		case 3:
			return;
		}
	}
}

void GameManager::Scroll()
{
	ifstream load;
	string* story;
	int OldClock = clock();
	int story_line = 1;
	int scroll_line = 5;
	int linemax;
	int start = 0;
	m_Interface.BoxDraw();
	m_Interface.BoxText("스킵 = S");
	load.open("Story.txt");
	if (load.is_open())
	{
		load >> linemax;
		story = new string[linemax];
		for (int i = 0; i < linemax; i++)
			getline(load, story[i]);
	}
	load.close();
	while (1)
	{
		if (kbhit())
		{
			if (getch() == 's')
				break;
		}
		if (clock() - OldClock >= SCROLL_TIME)
		{
			if (story_line > 10)
			{
				m_Interface.ScrollErase(20, 5, 50, 20);
				start++;
				if (story_line > 26)
					break;
			}
			for (int i = start; i < story_line; i++)
			{
				m_Interface.MidText(story[i], scroll_line++);
			}
			scroll_line = 5;
			story_line++;
			OldClock = clock();
		}
	}
	delete[] story;
	story = NULL;
}

void GameManager::Stage_Start()
{
	string stage = "STAGE ";
	stage += to_string(m_WordManager.GetStageLv());
	m_Interface.BorderLine();
	m_Interface.MidText(stage, 20);
	Sleep(1000);
	m_Interface.ScrollErase(30, 20, 40, 30);
	m_Interface.BoxDraw();
	m_Interface.Defalt();
}

void GameManager::InGame()
{
	Scroll();
	string answer;
	srand(time(NULL));
	m_Interface.BorderLine();
	m_Interface.MidText("이름 입력", 20);
	m_Interface.BoxDraw();
	while (1)
	{
		if (m_Interface.InPut(m_User->m_Name, 10))
		{
			m_Interface.UnderLine_Name(m_User->m_Name);
			break;
		}
	}
	Stage_Start();
	while (1)
	{
		m_WordManager.Create_Word();
		if (m_WordManager.Falling_Word(m_Interface, m_User->m_Life) == DIE)
			m_Interface.UnderLine_Life(m_User->m_Life);
		m_WordManager.Active_Finigh();
		if (m_Interface.InPut(answer, 20) == true)
		{
			if (m_WordManager.Check_Word(answer, m_User->m_Score))
				m_Interface.UnderLine_Score(m_User->m_Score);
			else
				m_Interface.SetFail();
		}
		if (m_User->m_Life <= 0)
		{
			GameOver();
			return;
		}
		if (m_User->m_Score >= (m_WordManager.GetStageLv() + 1) * 500)
			Level_Up();
	}
}

void GameManager::GameOver()
{
	m_User->m_Total_Score += m_User->m_Score;
	m_RankManager.Save_User(m_User->m_Name, m_User->m_Total_Score, m_User->m_End_Stage);
	RED
		m_Interface.MidText("Game Over..", 20);
	ORIGINAL
		getch();
	m_Interface.Defalt();
	m_WordManager.ReSet_Word();
	m_WordManager.ReSet_Stage();
}

void GameManager::Level_Up()
{
	m_User->m_Total_Score += m_User->m_Score;
	m_User->m_Score = 0;
	m_User->m_End_Stage++;
	m_Interface.UnderLine_Score(m_User->m_Score);
	m_WordManager.Stage_Up();
	m_WordManager.ReSet_Word();
	Stage_Start();
}

GameManager::~GameManager()
{
	if (m_User != NULL)
		delete m_User;
}