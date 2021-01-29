#pragma once
#include "Block.h"

struct Limit
{
	int Top;
	int Bottom;
	int Left;
	int Right;
	Limit(int x, int y)
	{
		Top = 1;
		Bottom = y - 2;
		Left = 1;
		Right = x - 2;
	}
};

class Player
{
private:
	int m_iX;
	int m_iY;
	Limit* m_Limit;
	string m_strIcon;
public:
	Player(int x, int y);
	~Player();
	STEP Move(Block** BlockManager, int total);
	void DrawCursor(int x, int y);
	STEP CursorInteraction(Block** BlockManager, CURSER_INTERACTION interaction, int total);
	void StartCursor();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

