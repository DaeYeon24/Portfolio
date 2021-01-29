#pragma once
#include "Snake.h"
#include "Alarm.h"

class GameManager
{
private:
	Block* m_BlockManager;
	Draw* m_DrawManager;
	Snake* m_Player;
	Enemy* m_Enemy;
public:
	GameManager();
	~GameManager();
	void BeforeGame();
	void InGame();
};