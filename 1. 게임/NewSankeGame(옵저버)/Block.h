#pragma once
#include "Mecro.h"

struct Point
{
	int m_ix;
	int m_iy;
};

class Block
{
private:
	Point* m_LifeBlock[PREYMAX];
	Point* m_DeathBlock[DEADMAX];
	int m_CreateClock;
public:
	Block();
	~Block();
	void DrawWall();
	void SetDeathBlock();
	void SetLifeBlock();
	void DrawBlock(int what = DEAD, int x = NULL, int y = NULL);
	void EraseBlock(int x, int y);
	int CheckBlock(int x, int y, int what = NULL);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

