#pragma once
#include "Draw.h"
#include "Block.h"
#include "Player.h"

class Manager
{
private:
	int m_iWidth;
	int m_iHeight;
	int m_itotal;
	int m_iMineCount;
	string m_strDifficulty;
	Draw* m_DrawManager;
	Block** m_BlockManager;
	Player* m_Player;
public:
	Manager();
	~Manager();
	void Title();
	void Init();
	void Difficulty();
	void InGame();
	void InGameText();
	bool WinCheck();
	void Boom();
};

