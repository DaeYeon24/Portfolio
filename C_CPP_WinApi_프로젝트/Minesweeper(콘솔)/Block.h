#pragma once
#include "header.h"

class Block
{
protected:
	int m_iX;
	int m_iY;
	bool m_bisMine;
	bool m_bisOpen;
	bool m_bMark;
	string m_strIcon;
public:
	Block(int x, int y) : m_iX(x), m_iY(y) {}
	virtual void FindEmptyBlock(Block** BlockManager, int total) = 0;
	void SetIcon(int count);
	STEP Mark();
	bool IsMine();
	bool IsOpen();
	void Open();
	bool GuessXY(int x, int y);
	STEP GuessWhat(Block** BlockManager, int total);
	void Show();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

class Mine : public Block
{
public:
	Mine(int x, int y) : Block(x, y)
	{
		m_bisMine = true;
		m_bisOpen = false;
		m_bMark = false;
		m_strIcon = MINE_BLOCK;
	}
	void FindEmptyBlock(Block** BlockManager, int total) {};
};

class EmptyBlock : public Block
{
public:
	EmptyBlock(int x, int y) : Block(x, y)
	{
		m_bisMine = false;
		m_bisOpen = false;
		m_bMark = false;
		m_strIcon = EMPTY_BLOCK;
	}
	void FindEmptyBlock(Block** BlockManager, int total) override;
};