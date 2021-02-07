#include "GameManager.h"

GameManager::GameManager()
{
	m_BlockManager = new Block();
	m_DrawManager = new Draw();
	m_Player = NULL;
	m_Enemy = NULL;
}

void GameManager::BeforeGame()
{
	srand(time(NULL));
	m_BlockManager->DrawWall();
	while (1)
	{
		switch (m_DrawManager->Menu())
		{
		case 1:
			m_BlockManager->DrawWall();
			if (m_Player != NULL)
			{
				delete m_Player;
				m_Player = NULL;
			}
			if (m_Player == NULL)
				m_Player = new Snake;
			//플레이어
			if (m_Enemy != NULL)
			{
				delete m_Enemy;
				m_Enemy = NULL;
			}
			if (m_Enemy == NULL)
				m_Enemy = new Enemy;
			//적군
			if (m_BlockManager != NULL)
			{
				delete m_BlockManager;
				m_BlockManager = NULL;
			}
			if (m_BlockManager == NULL)
				m_BlockManager = new Block;
			// 블록매니저
			InGame();
			break;
		case 2:
			return;
		}
		m_BlockManager->DrawWall();
	}
}

void GameManager::InGame()
{
	int UserFlag = ING;
	int Score = 0;
	m_Player->SetAlarm(m_Enemy);
	m_BlockManager->SetDeathBlock();
	m_BlockManager->DrawBlock();
	m_Player->GrowSnake();
	m_Player->StartSnake();
	m_DrawManager->Score(Score);
	while (1)
	{
		m_BlockManager->SetLifeBlock();
		m_Enemy->SpawnEnemy();
		m_Enemy->AUTO(m_BlockManager);
		if (kbhit())
			m_Player->Input(getch());
		UserFlag = m_Player->Move(m_BlockManager, m_Enemy);
		switch (UserFlag)
		{
		case DEAD:
			m_BlockManager->DrawWall();
			m_DrawManager->End();
			getch();
			return;
		case PREY:
			m_DrawManager->Score(++Score);
			break;
		}
	}
}

GameManager::~GameManager()
{
	delete m_DrawManager;
	if (m_BlockManager != NULL)
		delete m_BlockManager;
	if (m_Player != NULL)
		delete m_Player;
	if (m_Enemy != NULL)
		delete m_Enemy;
}